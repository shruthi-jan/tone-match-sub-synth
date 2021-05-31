/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_synth_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 17-Nov-2020 17:30:25
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_synth_api.h"
#include "_coder_synth_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "synth",                             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_boolean_T *y);
static void b_emlrt_marshallOut(const real_T u[12], const mxArray *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fs, const
  char_T *identifier);
static const mxArray *c_emlrt_marshallOut(const real_T u);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *zi,
  const char_T *identifier))[12];
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *note, const
  char_T *identifier, emxArray_boolean_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray);
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);
static void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12];
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_boolean_T *ret);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12];

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_boolean_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_boolean_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u[12]
 *                const mxArray *y
 * Return Type  : void
 */
static void b_emlrt_marshallOut(const real_T u[12], const mxArray *y)
{
  static const int32_T iv1[2] = { 6, 2 };

  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, *(int32_T (*)[2])&iv1[0], 2);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *fs
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fs, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(fs), &thisId);
  emlrtDestroyArray(&fs);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *zi
 *                const char_T *identifier
 * Return Type  : real_T (*)[12]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *zi,
  const char_T *identifier))[12]
{
  real_T (*y)[12];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(zi), &thisId);
  emlrtDestroyArray(&zi);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *note
 *                const char_T *identifier
 *                emxArray_boolean_T *y
 * Return Type  : void
 */
  static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *note, const
  char_T *identifier, emxArray_boolean_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(note), &thisId, y);
  emlrtDestroyArray(&note);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_boolean_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      emlrtFreeMex2018a(sp, (void *)(*pEmxArray)->data);
    }

    emlrtFreeMex2018a(sp, (void *)(*pEmxArray)->size);
    emlrtFreeMex2018a(sp, (void *)*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex2018a(sp, (void *)(*pEmxArray)->data);
    }

    emlrtFreeMex2018a(sp, (void *)(*pEmxArray)->size);
    emlrtFreeMex2018a(sp, (void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_boolean_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_boolean_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T *)emlrtMallocMex(sizeof(emxArray_boolean_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2018a(sp, (void *)pEmxArray, (void (*)(const
      void *, void *))emxFree_boolean_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2018a(sp, (void *)pEmxArray, (void (*)(const
      void *, void *))emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[12]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_boolean_T *ret
 * Return Type  : void
 */
  static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_boolean_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv2[2];
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src,
    "logical", false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv0[0], iv2);
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (boolean_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[12]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  real_T (*ret)[12];
  static const int32_T dims[2] = { 6, 2 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  ret = (real_T (*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray * const prhs[16]
 *                int32_T nlhs
 *                const mxArray *plhs[5]
 * Return Type  : void
 */
  void synth_api(const mxArray * const prhs[16], int32_T nlhs, const mxArray
                 *plhs[5])
{
  emxArray_boolean_T *note;
  emxArray_real_T *y;
  emxArray_real_T *y2;
  const mxArray *prhs_copy_idx_6;
  real_T fs;
  real_T f0;
  real_T Q;
  real_T wf;
  real_T N;
  real_T (*zi)[12];
  real_T a1;
  real_T d1;
  real_T s1;
  real_T r1;
  real_T a2;
  real_T d2;
  real_T s2;
  real_T r2;
  real_T fa;
  real_T amp1;
  real_T amp2;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_boolean_T(&st, &note, 2, true);
  emxInit_real_T(&st, &y, 1, true);
  emxInit_real_T(&st, &y2, 1, true);
  prhs_copy_idx_6 = emlrtProtectR2012b(prhs[6], 6, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "note", note);
  fs = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "fs");
  f0 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "f0");
  Q = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "Q");
  wf = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "wf");
  N = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "N");
  zi = e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_6), "zi");
  a1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "a1");
  d1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "d1");
  s1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "s1");
  r1 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "r1");
  a2 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "a2");
  d2 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "d2");
  s2 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "s2");
  r2 = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "r2");
  fa = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "fa");

  /* Invoke the target function */
  synth(note, fs, f0, Q, wf, N, *zi, a1, d1, s1, r1, a2, d2, s2, r2, fa, y, y2,
        &amp1, &amp2);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(y);
  y->canFreeData = false;
  emxFree_real_T(&st, &y);
  note->canFreeData = false;
  emxFree_boolean_T(&st, &note);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(y2);
  }

  y2->canFreeData = false;
  emxFree_real_T(&st, &y2);
  if (nlhs > 2) {
    b_emlrt_marshallOut(*zi, prhs_copy_idx_6);
    plhs[2] = prhs_copy_idx_6;
  }

  if (nlhs > 3) {
    plhs[3] = c_emlrt_marshallOut(amp1);
  }

  if (nlhs > 4) {
    plhs[4] = c_emlrt_marshallOut(amp2);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void synth_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  synth_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void synth_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void synth_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_synth_api.c
 *
 * [EOF]
 */
