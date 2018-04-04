/*
 * xzlanhs.c
 *
 * Code generation for function 'xzlanhs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzlanhs.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "calculations_data.h"

/* Variable Definitions */
static emlrtRSInfo cc_emlrtRSI = { 20, "xzlanhs",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"
};

static emlrtRSInfo dc_emlrtRSI = { 21, "xzlanhs",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"
};

static emlrtRSInfo ec_emlrtRSI = { 57, "xzlanhs",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlanhs.m"
};

/* Function Definitions */
real_T xzlanhs(const emlrtStack *sp, const creal_T A[4], int32_T ilo, int32_T
               ihi)
{
  real_T f;
  real_T scale;
  real_T sumsq;
  boolean_T firstNonZero;
  int32_T j;
  int32_T b;
  int32_T i;
  real_T reAij;
  real_T imAij;
  real_T temp2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  f = 0.0;
  if (ilo > ihi) {
  } else {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    st.site = &cc_emlrtRSI;
    if ((!(ilo > ihi)) && (ihi > 2147483646)) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = ilo; j <= ihi; j++) {
      b = j + 1;
      if (ihi < j + 1) {
        b = ihi;
      }

      st.site = &dc_emlrtRSI;
      if ((!(ilo > b)) && (b > 2147483646)) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (i = ilo; i <= b; i++) {
        reAij = A[(i + ((j - 1) << 1)) - 1].re;
        imAij = A[(i + ((j - 1) << 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = muDoubleScalarAbs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          reAij = muDoubleScalarAbs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    st.site = &ec_emlrtRSI;
    if (sumsq < 0.0) {
      b_st.site = &v_emlrtRSI;
      error(&b_st);
    }

    f = scale * muDoubleScalarSqrt(sumsq);
  }

  return f;
}

/* End of code generation (xzlanhs.c) */
