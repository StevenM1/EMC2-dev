// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// dmvnrm_arma_fast
arma::vec dmvnrm_arma_fast(arma::mat const& x, arma::rowvec const& mean, arma::mat const& sigma, bool const logd);
RcppExport SEXP _EMC2_dmvnrm_arma_fast(SEXP xSEXP, SEXP meanSEXP, SEXP sigmaSEXP, SEXP logdSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat const& >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::rowvec const& >::type mean(meanSEXP);
    Rcpp::traits::input_parameter< arma::mat const& >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< bool const >::type logd(logdSEXP);
    rcpp_result_gen = Rcpp::wrap(dmvnrm_arma_fast(x, mean, sigma, logd));
    return rcpp_result_gen;
END_RCPP
}
// calc_ll
NumericVector calc_ll(NumericMatrix p_matrix, DataFrame data, NumericVector constants, List designs, const int n_trials, String type, CharacterVector p_types, LogicalVector winner, NumericVector expand, double min_ll);
RcppExport SEXP _EMC2_calc_ll(SEXP p_matrixSEXP, SEXP dataSEXP, SEXP constantsSEXP, SEXP designsSEXP, SEXP n_trialsSEXP, SEXP typeSEXP, SEXP p_typesSEXP, SEXP winnerSEXP, SEXP expandSEXP, SEXP min_llSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type p_matrix(p_matrixSEXP);
    Rcpp::traits::input_parameter< DataFrame >::type data(dataSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type constants(constantsSEXP);
    Rcpp::traits::input_parameter< List >::type designs(designsSEXP);
    Rcpp::traits::input_parameter< const int >::type n_trials(n_trialsSEXP);
    Rcpp::traits::input_parameter< String >::type type(typeSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type p_types(p_typesSEXP);
    Rcpp::traits::input_parameter< LogicalVector >::type winner(winnerSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type expand(expandSEXP);
    Rcpp::traits::input_parameter< double >::type min_ll(min_llSEXP);
    rcpp_result_gen = Rcpp::wrap(calc_ll(p_matrix, data, constants, designs, n_trials, type, p_types, winner, expand, min_ll));
    return rcpp_result_gen;
END_RCPP
}
// dlba
NumericVector dlba(NumericVector t, NumericVector A, NumericVector b, NumericVector v, NumericVector sv, bool posdrift, bool robust);
RcppExport SEXP _EMC2_dlba(SEXP tSEXP, SEXP ASEXP, SEXP bSEXP, SEXP vSEXP, SEXP svSEXP, SEXP posdriftSEXP, SEXP robustSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type t(tSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type A(ASEXP);
    Rcpp::traits::input_parameter< NumericVector >::type b(bSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type v(vSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type sv(svSEXP);
    Rcpp::traits::input_parameter< bool >::type posdrift(posdriftSEXP);
    Rcpp::traits::input_parameter< bool >::type robust(robustSEXP);
    rcpp_result_gen = Rcpp::wrap(dlba(t, A, b, v, sv, posdrift, robust));
    return rcpp_result_gen;
END_RCPP
}
// plba
NumericVector plba(NumericVector t, NumericVector A, NumericVector b, NumericVector v, NumericVector sv, bool posdrift, bool robust);
RcppExport SEXP _EMC2_plba(SEXP tSEXP, SEXP ASEXP, SEXP bSEXP, SEXP vSEXP, SEXP svSEXP, SEXP posdriftSEXP, SEXP robustSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type t(tSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type A(ASEXP);
    Rcpp::traits::input_parameter< NumericVector >::type b(bSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type v(vSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type sv(svSEXP);
    Rcpp::traits::input_parameter< bool >::type posdrift(posdriftSEXP);
    Rcpp::traits::input_parameter< bool >::type robust(robustSEXP);
    rcpp_result_gen = Rcpp::wrap(plba(t, A, b, v, sv, posdrift, robust));
    return rcpp_result_gen;
END_RCPP
}
// dWald
NumericVector dWald(NumericVector t, NumericVector v, NumericVector B, NumericVector A, NumericVector t0);
RcppExport SEXP _EMC2_dWald(SEXP tSEXP, SEXP vSEXP, SEXP BSEXP, SEXP ASEXP, SEXP t0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type t(tSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type v(vSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type B(BSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type A(ASEXP);
    Rcpp::traits::input_parameter< NumericVector >::type t0(t0SEXP);
    rcpp_result_gen = Rcpp::wrap(dWald(t, v, B, A, t0));
    return rcpp_result_gen;
END_RCPP
}
// pWald
NumericVector pWald(NumericVector t, NumericVector v, NumericVector B, NumericVector A, NumericVector t0);
RcppExport SEXP _EMC2_pWald(SEXP tSEXP, SEXP vSEXP, SEXP BSEXP, SEXP ASEXP, SEXP t0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type t(tSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type v(vSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type B(BSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type A(ASEXP);
    Rcpp::traits::input_parameter< NumericVector >::type t0(t0SEXP);
    rcpp_result_gen = Rcpp::wrap(pWald(t, v, B, A, t0));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_EMC2_dmvnrm_arma_fast", (DL_FUNC) &_EMC2_dmvnrm_arma_fast, 4},
    {"_EMC2_calc_ll", (DL_FUNC) &_EMC2_calc_ll, 10},
    {"_EMC2_dlba", (DL_FUNC) &_EMC2_dlba, 7},
    {"_EMC2_plba", (DL_FUNC) &_EMC2_plba, 7},
    {"_EMC2_dWald", (DL_FUNC) &_EMC2_dWald, 5},
    {"_EMC2_pWald", (DL_FUNC) &_EMC2_pWald, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_EMC2(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
