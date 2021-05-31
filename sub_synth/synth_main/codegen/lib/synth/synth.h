//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: synth.h
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 17-Nov-2020 17:30:25
//
#ifndef SYNTH_H
#define SYNTH_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "synth_types.h"

// Function Declarations
extern void synth(const emxArray_boolean_T *note, double fs, double f0, double Q,
                  double wf, double N, double zi[12], double a1, double d1,
                  double s1, double r1, double a2, double d2, double s2, double
                  r2, double fa, emxArray_real_T *y, emxArray_real_T *y2, double
                  *amp1, double *amp2);

#endif

//
// File trailer for synth.h
//
// [EOF]
//
