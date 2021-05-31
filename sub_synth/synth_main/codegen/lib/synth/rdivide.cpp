//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rdivide.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//

// Include Files
#include "rt_nonfinite.h"
#include "synth.h"
#include "rdivide.h"
#include "synth_emxutil.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                double y
//                emxArray_real_T *z
// Return Type  : void
//
void rdivide(const emxArray_real_T *x, double y, emxArray_real_T *z)
{
  int i0;
  int loop_ub;
  i0 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity_real_T(z, i0);
  loop_ub = x->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    z->data[i0] = x->data[i0] / y;
  }
}

//
// File trailer for rdivide.cpp
//
// [EOF]
//
