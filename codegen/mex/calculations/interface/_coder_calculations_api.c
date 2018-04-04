/*
 * _coder_calculations_api.c
 *
 * Code generation for function '_coder_calculations_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "_coder_calculations_api.h"
#include "calculations_data.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *B1,
  const char_T *identifier))[9];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[9];
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *a1, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u[385]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9];

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *B1,
  const char_T *identifier))[9]
{
  real_T (*y)[9];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(B1), &thisId);
  emlrtDestroyArray(&B1);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[9]
{
  real_T (*y)[9];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *a1, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a1), &thisId);
  emlrtDestroyArray(&a1);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[385])
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv6[2] = { 0, 0 };

  static const int32_T iv7[2] = { 1, 385 };

  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u);
  emlrtSetDimensions((mxArray *)m2, iv7, 2);
  emlrtAssign(&y, m2);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[9]
{
  real_T (*ret)[9];
  static const int32_T dims[2] = { 3, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[9])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void calculations_api(calculationsStackData *SD, const mxArray * const prhs[4],
  const mxArray *plhs[1])
{
  real_T (*F)[385];
  real_T a1;
  real_T a2;
  real_T a3;
  real_T (*B1)[9];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  F = (real_T (*)[385])mxMalloc(sizeof(real_T [385]));

  /* Marshall function inputs */
  a1 = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a1");
  a2 = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "a2");
  a3 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a3");
  B1 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "B1");

  /* Invoke the target function */
  calculations(SD, &st, a1, a2, a3, *B1, *F);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*F);
}

/* End of code generation (_coder_calculations_api.c) */
