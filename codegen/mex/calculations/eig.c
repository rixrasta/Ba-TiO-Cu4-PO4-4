/*
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "eig.h"
#include "warning.h"
#include "xzggev.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = { 111, "eig",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"
};

static emlrtRSInfo l_emlrtRSI = { 118, "eig",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"
};

static emlrtRSInfo m_emlrtRSI = { 14, "xzgeev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeev.m"
};

/* Function Definitions */
void eig(const emlrtStack *sp, const creal_T A[4], creal_T V[4], creal_T D[4])
{
  creal_T At[4];
  int32_T info;
  creal_T alpha1[2];
  creal_T beta1[2];
  int32_T coltop;
  int32_T k;
  real_T colnorm;
  real_T scale;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &k_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  memcpy(&At[0], &A[0], sizeof(creal_T) << 2);
  b_st.site = &m_emlrtRSI;
  xzggev(&b_st, At, &info, alpha1, beta1, V);
  for (coltop = 0; coltop <= 3; coltop += 2) {
    colnorm = 0.0;
    scale = 2.2250738585072014E-308;
    for (k = coltop; k + 1 <= coltop + 2; k++) {
      absxk = muDoubleScalarAbs(V[k].re);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }

      absxk = muDoubleScalarAbs(V[k].im);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }
    }

    colnorm = scale * muDoubleScalarSqrt(colnorm);
    for (k = coltop; k + 1 <= coltop + 2; k++) {
      if (V[k].im == 0.0) {
        V[k].re /= colnorm;
        V[k].im = 0.0;
      } else if (V[k].re == 0.0) {
        V[k].re = 0.0;
        V[k].im /= colnorm;
      } else {
        V[k].re /= colnorm;
        V[k].im /= colnorm;
      }
    }
  }

  for (k = 0; k < 4; k++) {
    D[k].re = 0.0;
    D[k].im = 0.0;
  }

  for (k = 0; k < 2; k++) {
    if (beta1[k].im == 0.0) {
      if (alpha1[k].im == 0.0) {
        D[k + (k << 1)].re = alpha1[k].re / beta1[k].re;
        D[k + (k << 1)].im = 0.0;
      } else if (alpha1[k].re == 0.0) {
        D[k + (k << 1)].re = 0.0;
        D[k + (k << 1)].im = alpha1[k].im / beta1[k].re;
      } else {
        D[k + (k << 1)].re = alpha1[k].re / beta1[k].re;
        D[k + (k << 1)].im = alpha1[k].im / beta1[k].re;
      }
    } else if (beta1[k].re == 0.0) {
      if (alpha1[k].re == 0.0) {
        D[k + (k << 1)].re = alpha1[k].im / beta1[k].im;
        D[k + (k << 1)].im = 0.0;
      } else if (alpha1[k].im == 0.0) {
        D[k + (k << 1)].re = 0.0;
        D[k + (k << 1)].im = -(alpha1[k].re / beta1[k].im);
      } else {
        D[k + (k << 1)].re = alpha1[k].im / beta1[k].im;
        D[k + (k << 1)].im = -(alpha1[k].re / beta1[k].im);
      }
    } else {
      absxk = muDoubleScalarAbs(beta1[k].re);
      colnorm = muDoubleScalarAbs(beta1[k].im);
      if (absxk > colnorm) {
        colnorm = beta1[k].im / beta1[k].re;
        scale = beta1[k].re + colnorm * beta1[k].im;
        D[k + (k << 1)].re = (alpha1[k].re + colnorm * alpha1[k].im) / scale;
        D[k + (k << 1)].im = (alpha1[k].im - colnorm * alpha1[k].re) / scale;
      } else if (colnorm == absxk) {
        if (beta1[k].re > 0.0) {
          colnorm = 0.5;
        } else {
          colnorm = -0.5;
        }

        if (beta1[k].im > 0.0) {
          scale = 0.5;
        } else {
          scale = -0.5;
        }

        D[k + (k << 1)].re = (alpha1[k].re * colnorm + alpha1[k].im * scale) /
          absxk;
        D[k + (k << 1)].im = (alpha1[k].im * colnorm - alpha1[k].re * scale) /
          absxk;
      } else {
        colnorm = beta1[k].re / beta1[k].im;
        scale = beta1[k].im + colnorm * beta1[k].re;
        D[k + (k << 1)].re = (colnorm * alpha1[k].re + alpha1[k].im) / scale;
        D[k + (k << 1)].im = (colnorm * alpha1[k].im - alpha1[k].re) / scale;
      }
    }
  }

  if (info != 0) {
    st.site = &l_emlrtRSI;
    b_warning(&st);
  }
}

/* End of code generation (eig.c) */
