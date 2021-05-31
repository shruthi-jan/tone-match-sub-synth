//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "synth.h"
#include "abs.h"
#include "synth_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *y
// Return Type  : void
//
void b_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned int x_idx_0;
  int k;
  x_idx_0 = (unsigned int)x->size[0];
  k = y->size[0];
  y->size[0] = (int)x_idx_0;
  emxEnsureCapacity_real_T(y, k);
  for (k = 0; k < x->size[0]; k++) {
    y->data[k] = std::abs(x->data[k]);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
