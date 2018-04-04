/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "mldivide.h"
#include "warning.h"
#include "calculations_data.h"

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = { 1, "mldivide",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"
};

static emlrtRSInfo jc_emlrtRSI = { 54, "lusolve",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

static emlrtRSInfo kc_emlrtRSI = { 169, "lusolve",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const creal_T A[4], const real_T B[4],
              creal_T Y[4])
{
  int32_T r1;
  int32_T r2;
  real_T brm;
  real_T a21_re;
  real_T bim;
  real_T a21_im;
  real_T d;
  real_T a22_re;
  real_T a22_im;
  int32_T k;
  real_T ar;
  real_T ai;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ic_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &jc_emlrtRSI;
  if (muDoubleScalarAbs(A[1].re) + muDoubleScalarAbs(A[1].im) >
      muDoubleScalarAbs(A[0].re) + muDoubleScalarAbs(A[0].im)) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  if (A[r1].im == 0.0) {
    if (A[r2].im == 0.0) {
      a21_re = A[r2].re / A[r1].re;
      a21_im = 0.0;
    } else if (A[r2].re == 0.0) {
      a21_re = 0.0;
      a21_im = A[r2].im / A[r1].re;
    } else {
      a21_re = A[r2].re / A[r1].re;
      a21_im = A[r2].im / A[r1].re;
    }
  } else if (A[r1].re == 0.0) {
    if (A[r2].re == 0.0) {
      a21_re = A[r2].im / A[r1].im;
      a21_im = 0.0;
    } else if (A[r2].im == 0.0) {
      a21_re = 0.0;
      a21_im = -(A[r2].re / A[r1].im);
    } else {
      a21_re = A[r2].im / A[r1].im;
      a21_im = -(A[r2].re / A[r1].im);
    }
  } else {
    brm = muDoubleScalarAbs(A[r1].re);
    bim = muDoubleScalarAbs(A[r1].im);
    if (brm > bim) {
      bim = A[r1].im / A[r1].re;
      d = A[r1].re + bim * A[r1].im;
      a21_re = (A[r2].re + bim * A[r2].im) / d;
      a21_im = (A[r2].im - bim * A[r2].re) / d;
    } else if (bim == brm) {
      if (A[r1].re > 0.0) {
        bim = 0.5;
      } else {
        bim = -0.5;
      }

      if (A[r1].im > 0.0) {
        d = 0.5;
      } else {
        d = -0.5;
      }

      a21_re = (A[r2].re * bim + A[r2].im * d) / brm;
      a21_im = (A[r2].im * bim - A[r2].re * d) / brm;
    } else {
      bim = A[r1].re / A[r1].im;
      d = A[r1].im + bim * A[r1].re;
      a21_re = (bim * A[r2].re + A[r2].im) / d;
      a21_im = (bim * A[r2].im - A[r2].re) / d;
    }
  }

  a22_re = A[2 + r2].re - (a21_re * A[2 + r1].re - a21_im * A[2 + r1].im);
  a22_im = A[2 + r2].im - (a21_re * A[2 + r1].im + a21_im * A[2 + r1].re);
  if (((a22_re == 0.0) && (a22_im == 0.0)) || ((A[r1].re == 0.0) && (A[r1].im ==
        0.0))) {
    c_st.site = &kc_emlrtRSI;
    d_st.site = &j_emlrtRSI;
    warning(&d_st);
  }

  for (k = 0; k < 2; k++) {
    ar = B[r2 + (k << 1)] - B[r1 + (k << 1)] * a21_re;
    ai = 0.0 - B[r1 + (k << 1)] * a21_im;
    if (a22_im == 0.0) {
      if (ai == 0.0) {
        Y[1 + (k << 1)].re = ar / a22_re;
        Y[1 + (k << 1)].im = 0.0;
      } else if (ar == 0.0) {
        Y[1 + (k << 1)].re = 0.0;
        Y[1 + (k << 1)].im = ai / a22_re;
      } else {
        Y[1 + (k << 1)].re = ar / a22_re;
        Y[1 + (k << 1)].im = ai / a22_re;
      }
    } else if (a22_re == 0.0) {
      if (ar == 0.0) {
        Y[1 + (k << 1)].re = ai / a22_im;
        Y[1 + (k << 1)].im = 0.0;
      } else if (ai == 0.0) {
        Y[1 + (k << 1)].re = 0.0;
        Y[1 + (k << 1)].im = -(ar / a22_im);
      } else {
        Y[1 + (k << 1)].re = ai / a22_im;
        Y[1 + (k << 1)].im = -(ar / a22_im);
      }
    } else {
      brm = muDoubleScalarAbs(a22_re);
      bim = muDoubleScalarAbs(a22_im);
      if (brm > bim) {
        bim = a22_im / a22_re;
        d = a22_re + bim * a22_im;
        Y[1 + (k << 1)].re = (ar + bim * ai) / d;
        Y[1 + (k << 1)].im = (ai - bim * ar) / d;
      } else if (bim == brm) {
        if (a22_re > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (a22_im > 0.0) {
          d = 0.5;
        } else {
          d = -0.5;
        }

        Y[1 + (k << 1)].re = (ar * bim + ai * d) / brm;
        Y[1 + (k << 1)].im = (ai * bim - ar * d) / brm;
      } else {
        bim = a22_re / a22_im;
        d = a22_im + bim * a22_re;
        Y[1 + (k << 1)].re = (bim * ar + ai) / d;
        Y[1 + (k << 1)].im = (bim * ai - ar) / d;
      }
    }

    bim = Y[1 + (k << 1)].re * A[2 + r1].im + Y[1 + (k << 1)].im * A[2 + r1].re;
    ar = B[r1 + (k << 1)] - (Y[1 + (k << 1)].re * A[2 + r1].re - Y[1 + (k << 1)]
      .im * A[2 + r1].im);
    ai = 0.0 - (Y[1 + (k << 1)].re * A[2 + r1].im + Y[1 + (k << 1)].im * A[2 +
                r1].re);
    if (A[r1].im == 0.0) {
      if (0.0 - bim == 0.0) {
        Y[k << 1].re = ar / A[r1].re;
        Y[k << 1].im = 0.0;
      } else if (ar == 0.0) {
        Y[k << 1].re = 0.0;
        Y[k << 1].im = (0.0 - bim) / A[r1].re;
      } else {
        Y[k << 1].re = ar / A[r1].re;
        Y[k << 1].im = (0.0 - bim) / A[r1].re;
      }
    } else if (A[r1].re == 0.0) {
      if (ar == 0.0) {
        Y[k << 1].re = (0.0 - bim) / A[r1].im;
        Y[k << 1].im = 0.0;
      } else if (0.0 - bim == 0.0) {
        Y[k << 1].re = 0.0;
        Y[k << 1].im = -(ar / A[r1].im);
      } else {
        Y[k << 1].re = (0.0 - bim) / A[r1].im;
        Y[k << 1].im = -(ar / A[r1].im);
      }
    } else {
      brm = muDoubleScalarAbs(A[r1].re);
      bim = muDoubleScalarAbs(A[r1].im);
      if (brm > bim) {
        bim = A[r1].im / A[r1].re;
        d = A[r1].re + bim * A[r1].im;
        Y[k << 1].re = (ar + bim * ai) / d;
        Y[k << 1].im = (ai - bim * ar) / d;
      } else if (bim == brm) {
        if (A[r1].re > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (A[r1].im > 0.0) {
          d = 0.5;
        } else {
          d = -0.5;
        }

        Y[k << 1].re = (ar * bim + ai * d) / brm;
        Y[k << 1].im = (ai * bim - ar * d) / brm;
      } else {
        bim = A[r1].re / A[r1].im;
        d = A[r1].im + bim * A[r1].re;
        Y[k << 1].re = (bim * ar + ai) / d;
        Y[k << 1].im = (bim * ai - ar) / d;
      }
    }
  }
}

/* End of code generation (mldivide.c) */
