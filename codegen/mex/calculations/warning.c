/*
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "warning.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 14, 25, "warning",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo b_emlrtMCI = { 14, 9, "warning",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtRSInfo mc_emlrtRSI = { 14, "warning",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m3;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m3, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp)
{
  int32_T i3;
  const mxArray *y;
  char_T u[7];
  static const char_T cv2[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m1;
  static const int32_T iv3[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv3[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv4[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[24];
  static const char_T msgID[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e', 'i',
    'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c', 'e' };

  static const int32_T iv5[2] = { 1, 24 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i3 = 0; i3 < 7; i3++) {
    u[i3] = cv2[i3];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m1, &u[0]);
  emlrtAssign(&y, m1);
  for (i3 = 0; i3 < 7; i3++) {
    b_u[i3] = cv3[i3];
  }

  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&b_y, m1);
  for (i3 = 0; i3 < 24; i3++) {
    c_u[i3] = msgID[i3];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 24, m1, &c_u[0]);
  emlrtAssign(&c_y, m1);
  st.site = &mc_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  int32_T i2;
  const mxArray *y;
  char_T u[7];
  static const char_T cv0[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv1[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[27];
  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  static const int32_T iv2[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i2 = 0; i2 < 7; i2++) {
    u[i2] = cv0[i2];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i2 = 0; i2 < 7; i2++) {
    b_u[i2] = cv1[i2];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 7, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  for (i2 = 0; i2 < 27; i2++) {
    c_u[i2] = msgID[i2];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 27, m0, &c_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &mc_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &emlrtMCI), &b_emlrtMCI);
}

/* End of code generation (warning.c) */
