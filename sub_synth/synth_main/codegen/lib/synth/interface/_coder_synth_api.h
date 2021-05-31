/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_synth_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 17-Nov-2020 17:30:25
 */

#ifndef _CODER_SYNTH_API_H
#define _CODER_SYNTH_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_synth_api.h"

/* Type Definitions */
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void synth(emxArray_boolean_T *note, real_T fs, real_T f0, real_T Q,
                  real_T wf, real_T N, real_T zi[12], real_T a1, real_T d1,
                  real_T s1, real_T r1, real_T a2, real_T d2, real_T s2, real_T
                  r2, real_T fa, emxArray_real_T *y, emxArray_real_T *y2, real_T
                  *amp1, real_T *amp2);
extern void synth_api(const mxArray * const prhs[16], int32_T nlhs, const
                      mxArray *plhs[5]);
extern void synth_atexit(void);
extern void synth_initialize(void);
extern void synth_terminate(void);
extern void synth_xil_terminate(void);

#endif

/*
 * File trailer for _coder_synth_api.h
 *
 * [EOF]
 */
