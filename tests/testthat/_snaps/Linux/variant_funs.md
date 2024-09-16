# run_factor

    Code
      LNR_factor[[1]]$samples$theta_lambda[, , idx]
    Output
                    F1         F2
      m      0.6047598  0.0000000
      m_lMd  1.0018996  0.7112937
      s     -0.2976574 -0.5467998
      t0    -0.3318586 -0.8585592

---

    Code
      LNR_factor[[1]]$samples$alpha[, , idx]
    Output
                  as1t       bd6t
      m     -0.8449149 -0.9391686
      m_lMd -0.3082034 -0.6155118
      s     -0.9379678 -0.4871466
      t0    -1.9409439 -1.5628295

---

    Code
      LNR_factor[[1]]$samples$theta_mu[, idx]
    Output
                m       m_lMd           s          t0 
      -0.79574211 -1.00035757 -0.06807463 -0.63776152 

---

    Code
      LNR_factor[[1]]$samples$theta_var[, , idx]
    Output
                     m      m_lMd          s         t0
      m      0.4387771  0.6059086 -0.1800112 -0.2006948
      m_lMd  0.6059086  1.5494909 -0.6871581 -0.9431767
      s     -0.1800112 -0.6871581  0.4194850  0.5682401
      t0    -0.2006948 -0.9431767  0.5682401  0.8693539

# run_diag

    Code
      LNR_diag[[1]]$samples$alpha[, , idx]
    Output
                  as1t       bd6t
      m     -0.8156988 -0.9626350
      m_lMd -0.3332761 -0.5750740
      s     -0.9533433 -0.5416191
      t0    -2.1261239 -1.6269718

---

    Code
      LNR_diag[[1]]$samples$theta_mu[, idx]
    Output
               m      m_lMd          s         t0 
      -0.8289350 -0.7164414 -0.6293863 -1.8574561 

---

    Code
      LNR_diag[[1]]$samples$theta_var[, , idx]
    Output
                      m      m_lMd         s        t0
      m     0.006684457 0.00000000 0.0000000 0.0000000
      m_lMd 0.000000000 0.07735308 0.0000000 0.0000000
      s     0.000000000 0.00000000 0.1548257 0.0000000
      t0    0.000000000 0.00000000 0.0000000 0.1028706

# run_blocked

    Code
      LNR_blocked[[1]]$samples$alpha[, , idx]
    Output
                   as1t       bd6t
      m      -0.5935478 -0.6906642
      m_lMd  -0.2591428 -0.5639740
      s      -1.2749725 -0.8236691
      t0    -21.9116141 -2.2851430

---

    Code
      LNR_blocked[[1]]$samples$theta_mu[, idx]
    Output
                m       m_lMd           s          t0 
      -0.07532994 -0.53444049 -0.80814592 -0.76968633 

---

    Code
      LNR_blocked[[1]]$samples$theta_var[, , idx]
    Output
                   m    m_lMd        s         t0
      m     2.719012  0.00000 0.000000   0.000000
      m_lMd 0.000000 13.35262 0.000000   0.000000
      s     0.000000  0.00000 0.116051   4.766243
      t0    0.000000  0.00000 4.766243 214.663684

# run_single

    Code
      LNR_single[[1]]$samples$alpha[, , idx]
    Output
                  as1t       bd6t
      m     -0.6279802 -0.7302802
      m_lMd -0.2520426 -0.7756329
      s     -1.2729494 -0.6108434
      t0    -3.1900456 -2.1466979

# run_bridge

    Code
      compare(list(single = LNR_single, diag = LNR_diag, factor = LNR_factor), stage = "preburn",
      cores_for_props = 1)
    Output
               MD wMD  DIC wDIC BPIC wBPIC EffectiveN meanD Dmean minD
      single -346   0 -141    0  -35     0        106  -247  -353 -353
      diag   -503   1 -481    1 -442     1         39  -520  -538 -559
      factor  234   0 -341    0 -225     0        116  -457  -561 -573

