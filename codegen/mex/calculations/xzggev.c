/*
 * xzggev.c
 *
 * Code generation for function 'xzggev'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzggev.h"
#include "xzggbal.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "eml_int_forloop_overflow_check.h"
#include "xzlartg.h"
#include "calculations_data.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 39, "xzggev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"
};

static emlrtRSInfo q_emlrtRSI = { 84, "xzggev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"
};

static emlrtRSInfo r_emlrtRSI = { 100, "xzggev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"
};

static emlrtRSInfo s_emlrtRSI = { 101, "xzggev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"
};

static emlrtRSInfo t_emlrtRSI = { 106, "xzggev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"
};

static emlrtRSInfo u_emlrtRSI = { 108, "xzggev",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggev.m"
};

static emlrtRSInfo hb_emlrtRSI = { 62, "xzgghrd",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"
};

static emlrtRSInfo ib_emlrtRSI = { 64, "xzgghrd",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"
};

static emlrtRSInfo jb_emlrtRSI = { 77, "xzgghrd",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"
};

static emlrtRSInfo kb_emlrtRSI = { 79, "xzgghrd",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgghrd.m"
};

static emlrtRSInfo fc_emlrtRSI = { 32, "xzggbak",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzggbak.m"
};

/* Function Definitions */
void xzggev(const emlrtStack *sp, creal_T A[4], int32_T *info, creal_T alpha1[2],
            creal_T beta1[2], creal_T V[4])
{
  real_T anrm;
  int32_T jrow;
  boolean_T exitg1;
  real_T absxk;
  boolean_T ilascl;
  real_T anrmto;
  int32_T i;
  int32_T ilo;
  int32_T ihi;
  int32_T rscale[2];
  real_T ctoc;
  boolean_T notdone;
  int8_T I[4];
  real_T cfrom1;
  real_T stemp_re;
  real_T stemp_im;
  int32_T jcol;
  creal_T tmp;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  *info = 0;
  st.site = &p_emlrtRSI;
  anrm = 0.0;
  jrow = 0;
  exitg1 = false;
  while ((!exitg1) && (jrow < 4)) {
    absxk = muDoubleScalarHypot(A[jrow].re, A[jrow].im);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      jrow++;
    }
  }

  if (!((!muDoubleScalarIsInf(anrm)) && (!muDoubleScalarIsNaN(anrm)))) {
    for (i = 0; i < 2; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (jrow = 0; jrow < 4; jrow++) {
      V[jrow].re = rtNaN;
      V[jrow].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        cfrom1 = absxk * 2.0041683600089728E-292;
        stemp_re = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          stemp_im = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (stemp_re > absxk) {
          stemp_im = 4.9896007738368E+291;
          ctoc = stemp_re;
        } else {
          stemp_im = ctoc / absxk;
          notdone = false;
        }

        for (jrow = 0; jrow < 4; jrow++) {
          A[jrow].re *= stemp_im;
          A[jrow].im *= stemp_im;
        }
      }
    }

    st.site = &q_emlrtRSI;
    xzggbal(A, &ilo, &ihi, rscale);
    st.site = &r_emlrtRSI;
    for (jrow = 0; jrow < 4; jrow++) {
      I[jrow] = 0;
    }

    for (jrow = 0; jrow < 2; jrow++) {
      I[jrow + (jrow << 1)] = 1;
    }

    for (jrow = 0; jrow < 4; jrow++) {
      V[jrow].re = I[jrow];
      V[jrow].im = 0.0;
    }

    if (ihi < ilo + 2) {
    } else {
      for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
        for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
          b_st.site = &hb_emlrtRSI;
          xzlartg(&b_st, A[(jrow + (jcol << 1)) - 1], A[jrow + (jcol << 1)],
                  &cfrom1, &tmp, &A[(jrow + (jcol << 1)) - 1]);
          A[jrow + (jcol << 1)].re = 0.0;
          A[jrow + (jcol << 1)].im = 0.0;
          b_st.site = &ib_emlrtRSI;
          c_st.site = &pb_emlrtRSI;
          for (j = jcol + 1; j + 1 < 3; j++) {
            stemp_re = cfrom1 * A[(jrow + (j << 1)) - 1].re + (tmp.re * A[jrow +
              (j << 1)].re - tmp.im * A[jrow + (j << 1)].im);
            stemp_im = cfrom1 * A[(jrow + (j << 1)) - 1].im + (tmp.re * A[jrow +
              (j << 1)].im + tmp.im * A[jrow + (j << 1)].re);
            absxk = A[(jrow + (j << 1)) - 1].im;
            ctoc = A[(jrow + (j << 1)) - 1].re;
            A[jrow + (j << 1)].re = cfrom1 * A[jrow + (j << 1)].re - (tmp.re *
              A[(jrow + (j << 1)) - 1].re + tmp.im * A[(jrow + (j << 1)) - 1].im);
            A[jrow + (j << 1)].im = cfrom1 * A[jrow + (j << 1)].im - (tmp.re *
              absxk - tmp.im * ctoc);
            A[(jrow + (j << 1)) - 1].re = stemp_re;
            A[(jrow + (j << 1)) - 1].im = stemp_im;
          }

          tmp.re = -tmp.re;
          tmp.im = -tmp.im;
          b_st.site = &jb_emlrtRSI;
          c_st.site = &qb_emlrtRSI;
          if ((!(1 > ihi)) && (ihi > 2147483646)) {
            d_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&d_st, true);
          }

          for (i = 0; i + 1 <= ihi; i++) {
            stemp_re = cfrom1 * A[i + (jrow << 1)].re + (tmp.re * A[i + ((jrow -
              1) << 1)].re - tmp.im * A[i + ((jrow - 1) << 1)].im);
            stemp_im = cfrom1 * A[i + (jrow << 1)].im + (tmp.re * A[i + ((jrow -
              1) << 1)].im + tmp.im * A[i + ((jrow - 1) << 1)].re);
            absxk = A[i + (jrow << 1)].im;
            ctoc = A[i + (jrow << 1)].re;
            A[i + ((jrow - 1) << 1)].re = cfrom1 * A[i + ((jrow - 1) << 1)].re -
              (tmp.re * A[i + (jrow << 1)].re + tmp.im * A[i + (jrow << 1)].im);
            A[i + ((jrow - 1) << 1)].im = cfrom1 * A[i + ((jrow - 1) << 1)].im -
              (tmp.re * absxk - tmp.im * ctoc);
            A[i + (jrow << 1)].re = stemp_re;
            A[i + (jrow << 1)].im = stemp_im;
          }

          b_st.site = &kb_emlrtRSI;
          c_st.site = &qb_emlrtRSI;
          for (i = 0; i < 2; i++) {
            stemp_re = cfrom1 * V[i + (jrow << 1)].re + (tmp.re * V[i + ((jrow -
              1) << 1)].re - tmp.im * V[i + ((jrow - 1) << 1)].im);
            stemp_im = cfrom1 * V[i + (jrow << 1)].im + (tmp.re * V[i + ((jrow -
              1) << 1)].im + tmp.im * V[i + ((jrow - 1) << 1)].re);
            absxk = V[i + (jrow << 1)].re;
            V[i + ((jrow - 1) << 1)].re = cfrom1 * V[i + ((jrow - 1) << 1)].re -
              (tmp.re * V[i + (jrow << 1)].re + tmp.im * V[i + (jrow << 1)].im);
            V[i + ((jrow - 1) << 1)].im = cfrom1 * V[i + ((jrow - 1) << 1)].im -
              (tmp.re * V[i + (jrow << 1)].im - tmp.im * absxk);
            V[i + (jrow << 1)].re = stemp_re;
            V[i + (jrow << 1)].im = stemp_im;
          }
        }
      }
    }

    st.site = &s_emlrtRSI;
    xzhgeqz(&st, A, ilo, ihi, V, info, alpha1, beta1);
    if (*info != 0) {
    } else {
      st.site = &t_emlrtRSI;
      xztgevc(&st, A, V);
      st.site = &u_emlrtRSI;
      if (ilo > 1) {
        for (i = ilo - 2; i + 1 >= 1; i--) {
          jrow = rscale[i] - 1;
          if (rscale[i] != i + 1) {
            for (j = 0; j < 2; j++) {
              tmp = V[i + (j << 1)];
              V[i + (j << 1)] = V[jrow + (j << 1)];
              V[jrow + (j << 1)] = tmp;
            }
          }
        }
      }

      if (ihi < 2) {
        b_st.site = &fc_emlrtRSI;
        while (ihi + 1 < 3) {
          jrow = rscale[ihi] - 1;
          if (rscale[ihi] != ihi + 1) {
            for (j = 0; j < 2; j++) {
              tmp = V[ihi + (j << 1)];
              V[ihi + (j << 1)] = V[jrow + (j << 1)];
              V[jrow + (j << 1)] = tmp;
            }
          }

          ihi++;
        }
      }

      for (jrow = 0; jrow < 2; jrow++) {
        absxk = muDoubleScalarAbs(V[1 + (jrow << 1)].re) + muDoubleScalarAbs(V[1
          + (jrow << 1)].im);
        ctoc = muDoubleScalarAbs(V[jrow << 1].re) + muDoubleScalarAbs(V[jrow <<
          1].im);
        if (absxk > ctoc) {
          ctoc = absxk;
        }

        if (ctoc >= 6.7178761075670888E-139) {
          ctoc = 1.0 / ctoc;
          for (jcol = 0; jcol < 2; jcol++) {
            V[jcol + (jrow << 1)].re *= ctoc;
            V[jcol + (jrow << 1)].im *= ctoc;
          }
        }
      }

      if (ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          stemp_re = anrm / 4.9896007738368E+291;
          if ((cfrom1 > anrm) && (anrm != 0.0)) {
            stemp_im = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (stemp_re > anrmto) {
            stemp_im = 4.9896007738368E+291;
            anrm = stemp_re;
          } else {
            stemp_im = anrm / anrmto;
            notdone = false;
          }

          for (jrow = 0; jrow < 2; jrow++) {
            alpha1[jrow].re *= stemp_im;
            alpha1[jrow].im *= stemp_im;
          }
        }
      }
    }
  }
}

/* End of code generation (xzggev.c) */
