#include <Rcpp.h>
#include "utility_functions.h"
#include "model_lnr.h"
#include "model_LBA.h"
#include "model_RDM.h"
#include "model_DDM.h"
using namespace Rcpp;


NumericVector c_expand(NumericVector x1, NumericVector expand){
  const int n_out = expand.length();
  NumericVector out(n_out);
  int curr_idx;
  for(int i = 0; i < n_out; i++){
    curr_idx = expand[i] - 1; //expand created in 1-based R
    out[i] = x1[curr_idx];
  }
  return(out);
}

LogicalVector c_bool_expand(LogicalVector x1, NumericVector expand){
  const int n_out = expand.length();
  LogicalVector out(n_out);
  int curr_idx;
  for(int i = 0; i < n_out; i++){
    curr_idx = expand[i] - 1; //expand created in 1-based R
    out[i] = x1[curr_idx];
  }
  return(out);
}

NumericVector c_add_vectors(NumericVector x1, NumericVector x2){
  if(is_na(x2)[0] ){
    return(x1);
  }
  NumericVector output(x1.size() + x2.size());
  std::copy(x1.begin(), x1.end(), output.begin());
  std::copy(x2.begin(), x2.end(), output.begin() + x1.size());
  CharacterVector all_names(x1.size() + x2.size());
  CharacterVector x1_names = x1.names();
  CharacterVector x2_names = x2.names();
  std::copy(x1_names.begin(), x1_names.end(), all_names.begin());
  std::copy(x2_names.begin(), x2_names.end(), all_names.begin() + x1.size());
  output.names() = all_names;
  return output;
}

// LL generic functions
// [[Rcpp::export]]
NumericMatrix c_map_p(NumericVector p_vector, CharacterVector p_types, List designs, int n_trials){
  NumericMatrix pars(n_trials, p_types.length());
  for(int i = 0; i < p_types.length(); i++){
    NumericMatrix curr_design = designs[i];
    CharacterVector curr_names = colnames(curr_design);
    for(int j = 0; j < curr_design.ncol(); j ++){
      String curr_name(curr_names[j]);
      pars(_, i) = pars(_, i) + p_vector[curr_name] * curr_design(_, j);
    };
  };
  colnames(pars) = p_types;
  return(pars);
}

NumericMatrix get_pars_matrix(NumericVector p_vector, NumericVector constants,
                       NumericVector (*transform)(NumericVector),
                       NumericMatrix (*Ntransform)(NumericMatrix),
                       CharacterVector p_types, List designs, int n_trials){
  NumericVector p_vector_updtd(clone(p_vector));
  p_vector_updtd = c_add_vectors(p_vector_updtd, constants);
  p_vector_updtd = transform(p_vector_updtd);
  NumericMatrix pars = c_map_p(p_vector_updtd, p_types, designs, n_trials);
  pars = Ntransform(pars);
  return(pars);
}

double c_log_likelihood_DDM(NumericMatrix pars, DataFrame data,
                          const int n_trials, NumericVector expand,
                          double min_ll, List group_idx){
  const int n_out = expand.length();
  NumericVector rts = data["rt"];
  IntegerVector R = data["R"];
  NumericVector lls(n_trials);
  NumericVector lls_exp(n_out);
  lls = d_DDM_Wien(rts, R, pars);
  lls_exp = c_expand(lls, expand); // decompress
  lls_exp[is_na(lls_exp)] = min_ll;
  lls_exp[is_infinite(lls_exp)] = min_ll;
  lls_exp[lls_exp < min_ll] = min_ll;
  return(sum(lls_exp));
}

double c_log_likelihood_race(NumericMatrix pars, DataFrame data,
                             NumericVector (*dfun)(NumericVector, NumericMatrix, LogicalVector, double),
                             NumericVector (*pfun)(NumericVector, NumericMatrix, LogicalVector, double),
                             const int n_trials, LogicalVector winner, NumericVector expand,
                             double min_ll){
  const int n_out = expand.length();
  NumericVector lds(n_trials);
  NumericVector rts = data["rt"];
  CharacterVector R = data["R"];
  NumericVector lds_exp(n_out);
  const int n_acc = unique(R).length();
  if(sum(contains(data.names(), "NACC")) == 1){
    NumericVector lR = data["lR"];
    NumericVector NACC = data["NACC"];
    for(int x = 0; x < pars.nrow(); x++){
      if(lR[x] > NACC[x]){
        pars(x,0) = NA_REAL;
      }
    }
  }
  NumericVector win = log(dfun(rts, pars, winner, exp(min_ll))); //first for compressed
  lds[winner] = win;
  if(n_acc > 1){
    NumericVector loss = log(1- pfun(rts, pars, !winner, exp(min_ll))); //cdfs
    loss[is_na(loss)] = min_ll;
    loss[loss == log(1 - exp(min_ll))] = min_ll;
    lds[!winner] = loss;
  }
  lds[is_na(lds)] = min_ll;
  lds_exp = c_expand(lds, expand); // decompress
  if(n_acc > 1){
    LogicalVector winner_exp = c_bool_expand(winner, expand);
    NumericVector ll_out = lds_exp[winner_exp];
    if(n_acc == 2){
      NumericVector lds_los = lds_exp[!winner_exp];
      ll_out = ll_out + lds_los;
    } else{
      NumericVector lds_los = lds_exp[!winner_exp];
      for(int z = 0; z < ll_out.length(); z++){
        ll_out[z] = ll_out[z] + sum(lds_los[seq( z * (n_acc -1), (z+1) * (n_acc -1) -1)]);
      }
    }
    ll_out[is_na(ll_out)] = min_ll;
    ll_out[is_infinite(ll_out)] = min_ll;
    ll_out[ll_out < min_ll] = min_ll;
    return(sum(ll_out));
  } else{
    lds_exp[is_na(lds_exp)] = min_ll;
    lds_exp[is_infinite(lds_exp)] = min_ll;
    lds_exp[lds_exp < min_ll] = min_ll;
    return(sum(lds_exp));
  }
}

// [[Rcpp::export]]
NumericVector calc_ll(NumericMatrix p_matrix, DataFrame data, NumericVector constants,
                      List designs, String type, CharacterVector p_types,
                      double min_ll, List group_idx){
  const int n_particles = p_matrix.nrow();
  const int n_trials = data.nrow();
  NumericVector lls(n_particles);
  NumericVector p_vector(p_matrix.ncol());
  if(type == "MRI"){
    // for(int i = 0; i < n_particles; i++){
    //   p_vector = p_matrix(i, _);
    //   NumericMatrix designMatrix = data.attr("design_matrix_mri");
    //   lls[i] = c_log_likelihood_fMRI(p_vector, data, designMatrix, min_ll);
    // }
  } else{
    CharacterVector p_names = colnames(p_matrix);
    NumericMatrix pars(n_trials, p_types.length());
    p_vector.names() = p_names;
    NumericVector expand = data.attr("expand");
    if(type == "DDM"){
      for(int i = 0; i < n_particles; i++){
        p_vector = p_matrix(i, _);
        pars = get_pars_matrix(p_vector, constants, transform_DDM, Ntransform_DDM, p_types, designs, n_trials);
        lls[i] = c_log_likelihood_DDM(pars, data, n_trials, expand, min_ll, group_idx);
      }
    } else{
      LogicalVector winner = data["winner"];
      // Love me some good old ugly but fast c++ pointers
      NumericVector (*dfun)(NumericVector, NumericMatrix, LogicalVector, double);
      NumericVector (*pfun)(NumericVector, NumericMatrix, LogicalVector, double);
      NumericVector (*transform)(NumericVector);
      NumericMatrix (*Ntransform)(NumericMatrix);
      // NumericMatrix (*Ttransform)(NumericMatrix);
      if(type == "LBA"){
        dfun = dlba_c;
        pfun = plba_c;
        transform = transform_lba;
        Ntransform = Ntransform_lba;
      } else if(type == "RDM"){
        dfun = drdm_c;
        pfun = prdm_c;
        transform = transform_rdm;
        Ntransform = Ntransform_rdm;
      } else{
        dfun = dlnr_c;
        pfun = plnr_c;
        transform = transform_lnr;
        Ntransform = Ntransform_lnr;
      }
      for(int i = 0; i < n_particles; i++){
        p_vector = p_matrix(i, _);
        pars = get_pars_matrix(p_vector, constants, transform, Ntransform, p_types, designs, n_trials);
        lls[i] = c_log_likelihood_race(pars, data, dfun, pfun, n_trials, winner, expand, min_ll);
      }
    }
  }
  return(lls);
}

