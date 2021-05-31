//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: synth_initialize.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//

// Include Files
#include "rt_nonfinite.h"
#include "synth.h"
#include "synth_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void synth_initialize()
{
  rt_InitInfAndNaN(8U);
  c_eml_rand_mt19937ar_stateful_i();
}

//
// File trailer for synth_initialize.cpp
//
// [EOF]
//
