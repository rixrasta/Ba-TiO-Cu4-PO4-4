/*
 * calculations.c
 *
 * Code generation for function 'calculations'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "poore.h"
#include "power.h"
#include "abs.h"
#include "mldivide.h"
#include "diag.h"
#include "eig.h"
#include "mrdivide.h"
#include "calculations_data.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 37, "calculations",
  "C:\\\\Users\\\\Riho\\\\Desktop\\\\\xc3\x95ppematerjalid\\\\Ba(TiO)Cu4(PO4)4\\\\matlab\\\\average\\\\katse14\\\\New folder\\\\calculations.m"
};

static emlrtRSInfo d_emlrtRSI = { 41, "calculations",
  "C:\\\\Users\\\\Riho\\\\Desktop\\\\\xc3\x95ppematerjalid\\\\Ba(TiO)Cu4(PO4)4\\\\matlab\\\\average\\\\katse14\\\\New folder\\\\calculations.m"
};

static emlrtRSInfo e_emlrtRSI = { 43, "calculations",
  "C:\\\\Users\\\\Riho\\\\Desktop\\\\\xc3\x95ppematerjalid\\\\Ba(TiO)Cu4(PO4)4\\\\matlab\\\\average\\\\katse14\\\\New folder\\\\calculations.m"
};

/* Function Definitions */
void calculations(calculationsStackData *SD, const emlrtStack *sp, real_T a1,
                  real_T a2, real_T a3, const real_T B1[9], real_T F[385])
{
  real_T A1[9];
  int32_T k;
  real_T C1[9];
  real_T b_C1[9];
  real_T c_C1[9];
  real_T d_C1[9];
  int32_T i;
  real_T T1[9];
  int32_T i0;
  creal_T E1[4];
  int32_T i1;
  creal_T X1[4];
  creal_T b_E1[4];
  static const real_T b[4] = { 0.0, 0.5, 0.5, 0.0 };

  static const real_T b_b[4] = { 0.5, 0.0, 0.0, -0.5 };

  static const real_T dv0[4] = { 0.0, 0.5, -0.5, 0.0 };

  creal_T dcv0[2];
  real_T E[2];
  static const real_T c_b[9] = { 1.001298, 0.0, 0.0, 0.0, 1.001832, 0.0, 0.0,
    0.0, 1.001952 };

  static const real_T dv1[4] = { 0.0, 1.0, 1.0, 0.0 };

  real_T dv2[4];
  real_T unusedExpr[4];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0);

  /* %Finds a list of intentsities corresponding to the provided angles */
  /* Arguments: a1,a2,a3 - euler angles; B1 - rotation matrix */
  /* Return: List of values.  */
  /* 31P jaoks 600MHz väljas [Hz] */
  /* nihke tensor PAS-s */
  poore(a1, a2, a3, A1);

  /* a1k(m),a2k(m),a3k(m)); */
  /* A1i=inv(A1); */
  /* 5/2 tuuma spinni operaatorid */
  /* mõõteoperaator: */
  /* nivoode vahe */
  /* intensiivsus */
  memset(&SD->f0.g12[0], 0, 148225U * sizeof(real_T));
  k = 0;
  while (k < 385) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1);
    poore(-12.0 + (real_T)k, 90.0, 0.0, C1);

    /* C1i=inv(C1); */
    for (i = 0; i < 3; i++) {
      for (i0 = 0; i0 < 3; i0++) {
        c_C1[i + 3 * i0] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          c_C1[i + 3 * i0] += C1[i + 3 * i1] * B1[i1 + 3 * i0];
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        d_C1[i + 3 * i0] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          d_C1[i + 3 * i0] += c_C1[i + 3 * i1] * A1[i1 + 3 * i0];
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_C1[i + 3 * i0] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          b_C1[i + 3 * i0] += d_C1[i + 3 * i1] * c_b[i1 + 3 * i0];
        }
      }
    }

    st.site = &c_emlrtRSI;
    mrdivide(&st, b_C1, A1, T1);
    st.site = &c_emlrtRSI;
    mrdivide(&st, T1, B1, c_C1);
    st.site = &c_emlrtRSI;
    mrdivide(&st, c_C1, C1, T1);
    for (i = 0; i < 4; i++) {
      E1[i].re = 8.0986E+7 * ((T1[2] * b[i] + T1[5] * 0.0) + T1[8] * b_b[i]);
      E1[i].im = 8.0986E+7 * (T1[5] * dv0[i]);
    }

    st.site = &d_emlrtRSI;
    eig(&st, E1, X1, b_E1);

    /* X on maatriks omavektoritest ,E on omavaartused */
    diag(b_E1, dcv0);
    for (i = 0; i < 2; i++) {
      E[i] = dcv0[i].re;
    }

    st.site = &e_emlrtRSI;
    mldivide(&st, X1, dv1, b_E1);
    for (i = 0; i < 2; i++) {
      for (i0 = 0; i0 < 2; i0++) {
        E1[i + (i0 << 1)].re = 0.0;
        E1[i + (i0 << 1)].im = 0.0;
        for (i1 = 0; i1 < 2; i1++) {
          E1[i + (i0 << 1)].re += b_E1[i + (i1 << 1)].re * X1[i1 + (i0 << 1)].re
            - b_E1[i + (i1 << 1)].im * X1[i1 + (i0 << 1)].im;
          E1[i + (i0 << 1)].im += b_E1[i + (i1 << 1)].re * X1[i1 + (i0 << 1)].im
            + b_E1[i + (i1 << 1)].im * X1[i1 + (i0 << 1)].re;
        }
      }
    }

    b_abs(E1, dv2);
    power(dv2, unusedExpr);

    /* sagedus */
    SD->f0.g12[k] = E[1] - E[0];
    F[k] = (SD->f0.g12[k] - 8.0986E+7) / 8.0986E+7 * 100.0;

    /* intensiivsus */
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2);

  /* F(1,:) */
}

/* End of code generation (calculations.c) */
