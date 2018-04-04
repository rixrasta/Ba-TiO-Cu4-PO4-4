/*
 * xzhgeqz.c
 *
 * Code generation for function 'xzhgeqz'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzhgeqz.h"
#include "eml_int_forloop_overflow_check.h"
#include "xzlartg.h"
#include "sqrt.h"
#include "mod.h"
#include "xzlanhs.h"
#include "calculations_data.h"

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 37, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo sb_emlrtRSI = { 51, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo tb_emlrtRSI = { 111, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo ub_emlrtRSI = { 391, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo vb_emlrtRSI = { 398, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo wb_emlrtRSI = { 401, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo xb_emlrtRSI = { 410, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo yb_emlrtRSI = { 412, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo ac_emlrtRSI = { 424, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

static emlrtRSInfo bc_emlrtRSI = { 436, "xzhgeqz",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzhgeqz.m"
};

/* Function Definitions */
void xzhgeqz(const emlrtStack *sp, creal_T A[4], int32_T ilo, int32_T ihi,
             creal_T Z[4], int32_T *info, creal_T alpha1[2], creal_T beta1[2])
{
  int32_T jp1;
  real_T eshift_re;
  real_T eshift_im;
  creal_T ctemp;
  real_T anorm;
  real_T temp;
  real_T b_atol;
  real_T ascale;
  boolean_T failed;
  int32_T j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T ifirst;
  int32_T istart;
  int32_T ilast;
  int32_T ilastm1;
  int32_T iiter;
  int32_T maxit;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int32_T jiter;
  int32_T exitg1;
  boolean_T exitg3;
  boolean_T ilazro;
  boolean_T b_guard1 = false;
  creal_T b_ascale;
  real_T tempr;
  creal_T shift;
  real_T ascale_re;
  real_T ascale_im;
  real_T ad22_re;
  real_T ad22_im;
  real_T t1_re;
  boolean_T exitg2;
  real_T t1_im;
  int32_T b_ihi;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  *info = 0;
  for (jp1 = 0; jp1 < 2; jp1++) {
    alpha1[jp1].re = 0.0;
    alpha1[jp1].im = 0.0;
    beta1[jp1].re = 1.0;
    beta1[jp1].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  st.site = &rb_emlrtRSI;
  anorm = xzlanhs(&st, A, ilo, ihi);
  temp = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp > 2.2250738585072014E-308) {
    b_atol = temp;
  }

  temp = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    temp = anorm;
  }

  ascale = 1.0 / temp;
  failed = true;
  st.site = &sb_emlrtRSI;
  for (j = ihi; j + 1 < 3; j++) {
    alpha1[j] = A[j + (j << 1)];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    maxit = 30 * ((ihi - ilo) + 1);
    goto60 = false;
    goto70 = false;
    goto90 = false;
    st.site = &tb_emlrtRSI;
    if ((!(1 > maxit)) && (maxit > 2147483646)) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= maxit) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (muDoubleScalarAbs(A[ilast + (ilastm1 << 1)].re) +
                   muDoubleScalarAbs(A[ilast + (ilastm1 << 1)].im) <= b_atol) {
          A[ilast + (ilastm1 << 1)].re = 0.0;
          A[ilast + (ilastm1 << 1)].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (muDoubleScalarAbs(A[j + ((j - 1) << 1)].re) +
                       muDoubleScalarAbs(A[j + ((j - 1) << 1)].im) <= b_atol) {
              A[j + ((j - 1) << 1)].re = 0.0;
              A[j + ((j - 1) << 1)].im = 0.0;
              ilazro = true;
            } else {
              ilazro = false;
            }

            if (ilazro) {
              ifirst = j + 1;
              goto70 = true;
              exitg3 = true;
            } else {
              j--;
            }
          }
        }

        if (goto60 || goto70) {
          ilazro = true;
        } else {
          ilazro = false;
        }

        if (!ilazro) {
          for (jp1 = 0; jp1 < 2; jp1++) {
            alpha1[jp1].re = rtNaN;
            alpha1[jp1].im = 0.0;
            beta1[jp1].re = rtNaN;
            beta1[jp1].im = 0.0;
          }

          for (jp1 = 0; jp1 < 4; jp1++) {
            Z[jp1].re = rtNaN;
            Z[jp1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          b_guard1 = false;
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast + (ilast << 1)];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              b_guard1 = true;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (b_mod(iiter) != 0) {
                anorm = ascale * A[ilastm1 + (ilastm1 << 1)].re;
                temp = ascale * A[ilastm1 + (ilastm1 << 1)].im;
                if (temp == 0.0) {
                  shift.re = anorm / 0.70710678118654746;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = temp / 0.70710678118654746;
                } else {
                  shift.re = anorm / 0.70710678118654746;
                  shift.im = temp / 0.70710678118654746;
                }

                anorm = ascale * A[ilast + (ilast << 1)].re;
                temp = ascale * A[ilast + (ilast << 1)].im;
                if (temp == 0.0) {
                  ad22_re = anorm / 0.70710678118654746;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = temp / 0.70710678118654746;
                } else {
                  ad22_re = anorm / 0.70710678118654746;
                  ad22_im = temp / 0.70710678118654746;
                }

                t1_re = 0.5 * (shift.re + ad22_re);
                t1_im = 0.5 * (shift.im + ad22_im);
                anorm = ascale * A[ilastm1 + (ilast << 1)].re;
                temp = ascale * A[ilastm1 + (ilast << 1)].im;
                if (temp == 0.0) {
                  ascale_re = anorm / 0.70710678118654746;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = temp / 0.70710678118654746;
                } else {
                  ascale_re = anorm / 0.70710678118654746;
                  ascale_im = temp / 0.70710678118654746;
                }

                anorm = ascale * A[ilast + (ilastm1 << 1)].re;
                temp = ascale * A[ilast + (ilastm1 << 1)].im;
                if (temp == 0.0) {
                  tempr = anorm / 0.70710678118654746;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  tempr = 0.0;
                  anorm = temp / 0.70710678118654746;
                } else {
                  tempr = anorm / 0.70710678118654746;
                  anorm = temp / 0.70710678118654746;
                }

                temp = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (ascale_re * tempr
                  - ascale_im * anorm)) - (shift.re * ad22_re - shift.im *
                  ad22_im);
                shift.im = ((t1_re * t1_im + t1_im * t1_re) + (ascale_re * anorm
                  + ascale_im * tempr)) - temp;
                b_sqrt(&shift);
                if ((t1_re - ad22_re) * shift.re + (t1_im - ad22_im) * shift.im <=
                    0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                anorm = ascale * A[ilast + (ilastm1 << 1)].re;
                temp = ascale * A[ilast + (ilastm1 << 1)].im;
                if (temp == 0.0) {
                  ascale_re = anorm / 0.70710678118654746;
                  ascale_im = 0.0;
                } else if (anorm == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = temp / 0.70710678118654746;
                } else {
                  ascale_re = anorm / 0.70710678118654746;
                  ascale_im = temp / 0.70710678118654746;
                }

                eshift_re += ascale_re;
                eshift_im += ascale_im;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = ascale * A[j + (j << 1)].re - shift.re *
                  0.70710678118654746;
                ctemp.im = ascale * A[j + (j << 1)].im - shift.im *
                  0.70710678118654746;
                temp = muDoubleScalarAbs(ctemp.re) + muDoubleScalarAbs(ctemp.im);
                anorm = ascale * (muDoubleScalarAbs(A[jp1 + (j << 1)].re) +
                                  muDoubleScalarAbs(A[jp1 + (j << 1)].im));
                tempr = temp;
                if (anorm > temp) {
                  tempr = anorm;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  temp /= tempr;
                  anorm /= tempr;
                }

                if ((muDoubleScalarAbs(A[j + ((j - 1) << 1)].re) +
                     muDoubleScalarAbs(A[j + ((j - 1) << 1)].im)) * anorm <=
                    temp * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp.re = ascale * A[(ifirst + ((ifirst - 1) << 1)) - 1].re -
                  shift.re * 0.70710678118654746;
                ctemp.im = ascale * A[(ifirst + ((ifirst - 1) << 1)) - 1].im -
                  shift.im * 0.70710678118654746;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              b_ascale.re = ascale * A[istart + ((istart - 1) << 1)].re;
              b_ascale.im = ascale * A[istart + ((istart - 1) << 1)].im;
              st.site = &ub_emlrtRSI;
              b_xzlartg(&st, ctemp, b_ascale, &tempr, &shift);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  st.site = &vb_emlrtRSI;
                  xzlartg(&st, A[(j + (jp1 << 1)) - 1], A[j + (jp1 << 1)],
                          &tempr, &shift, &A[(j + (jp1 << 1)) - 1]);
                  A[j + (jp1 << 1)].re = 0.0;
                  A[j + (jp1 << 1)].im = 0.0;
                }

                st.site = &wb_emlrtRSI;
                b_st.site = &pb_emlrtRSI;
                for (jp1 = j - 1; jp1 + 1 < 3; jp1++) {
                  ad22_re = tempr * A[(j + (jp1 << 1)) - 1].re + (shift.re * A[j
                    + (jp1 << 1)].re - shift.im * A[j + (jp1 << 1)].im);
                  ad22_im = tempr * A[(j + (jp1 << 1)) - 1].im + (shift.re * A[j
                    + (jp1 << 1)].im + shift.im * A[j + (jp1 << 1)].re);
                  anorm = A[(j + (jp1 << 1)) - 1].im;
                  temp = A[(j + (jp1 << 1)) - 1].re;
                  A[j + (jp1 << 1)].re = tempr * A[j + (jp1 << 1)].re -
                    (shift.re * A[(j + (jp1 << 1)) - 1].re + shift.im * A[(j +
                      (jp1 << 1)) - 1].im);
                  A[j + (jp1 << 1)].im = tempr * A[j + (jp1 << 1)].im -
                    (shift.re * anorm - shift.im * temp);
                  A[(j + (jp1 << 1)) - 1].re = ad22_re;
                  A[(j + (jp1 << 1)) - 1].im = ad22_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                b_ihi = j + 2;
                if (ilast + 1 < j + 2) {
                  b_ihi = ilast + 1;
                }

                st.site = &xb_emlrtRSI;
                b_st.site = &qb_emlrtRSI;
                if ((!(1 > b_ihi)) && (b_ihi > 2147483646)) {
                  c_st.site = &cb_emlrtRSI;
                  check_forloop_overflow_error(&c_st, true);
                }

                for (jp1 = 0; jp1 + 1 <= b_ihi; jp1++) {
                  ad22_re = tempr * A[jp1 + (j << 1)].re + (shift.re * A[jp1 +
                    ((j - 1) << 1)].re - shift.im * A[jp1 + ((j - 1) << 1)].im);
                  ad22_im = tempr * A[jp1 + (j << 1)].im + (shift.re * A[jp1 +
                    ((j - 1) << 1)].im + shift.im * A[jp1 + ((j - 1) << 1)].re);
                  anorm = A[jp1 + (j << 1)].im;
                  temp = A[jp1 + (j << 1)].re;
                  A[jp1 + ((j - 1) << 1)].re = tempr * A[jp1 + ((j - 1) << 1)].
                    re - (shift.re * A[jp1 + (j << 1)].re + shift.im * A[jp1 +
                          (j << 1)].im);
                  A[jp1 + ((j - 1) << 1)].im = tempr * A[jp1 + ((j - 1) << 1)].
                    im - (shift.re * anorm - shift.im * temp);
                  A[jp1 + (j << 1)].re = ad22_re;
                  A[jp1 + (j << 1)].im = ad22_im;
                }

                st.site = &yb_emlrtRSI;
                b_st.site = &qb_emlrtRSI;
                for (jp1 = 0; jp1 < 2; jp1++) {
                  ad22_re = tempr * Z[jp1 + (j << 1)].re + (shift.re * Z[jp1 +
                    ((j - 1) << 1)].re - shift.im * Z[jp1 + ((j - 1) << 1)].im);
                  ad22_im = tempr * Z[jp1 + (j << 1)].im + (shift.re * Z[jp1 +
                    ((j - 1) << 1)].im + shift.im * Z[jp1 + ((j - 1) << 1)].re);
                  anorm = Z[jp1 + (j << 1)].im;
                  temp = Z[jp1 + (j << 1)].re;
                  Z[jp1 + ((j - 1) << 1)].re = tempr * Z[jp1 + ((j - 1) << 1)].
                    re - (shift.re * Z[jp1 + (j << 1)].re + shift.im * Z[jp1 +
                          (j << 1)].im);
                  Z[jp1 + ((j - 1) << 1)].im = tempr * Z[jp1 + ((j - 1) << 1)].
                    im - (shift.re * anorm - shift.im * temp);
                  Z[jp1 + (j << 1)].re = ad22_re;
                  Z[jp1 + (j << 1)].im = ad22_im;
                }

                jp1 = j - 1;
                j++;
              }
            }

            b_guard1 = true;
          }

          if (b_guard1) {
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      st.site = &ac_emlrtRSI;
      if ((!(1 > ilast + 1)) && (ilast + 1 > 2147483646)) {
        b_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (jp1 = 0; jp1 + 1 <= ilast + 1; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }

      for (jp1 = 0; jp1 < 4; jp1++) {
        Z[jp1].re = rtNaN;
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    st.site = &bc_emlrtRSI;
    if ((!(1 > ilo - 1)) && (ilo - 1 > 2147483646)) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = 0; j + 1 < ilo; j++) {
      alpha1[j] = A[j + (j << 1)];
    }
  }
}

/* End of code generation (xzhgeqz.c) */
