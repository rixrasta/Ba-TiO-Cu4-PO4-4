/*
 * File: calculations.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:43:28
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "diag.h"
#include "eig.h"
#include "mrdivide.h"
#include "poore.h"

/* Function Definitions */

/*
 * %Finds a list of intentsities corresponding to the provided angles
 * Arguments: a1,a2,a3 - euler angles; B1 - rotation matrix
 * Return: List of values.
 * Arguments    : double a1
 *                double a2
 *                double a3
 *                const double B1[9]
 *                double F[385]
 * Return Type  : void
 */
void calculations(double a1, double a2, double a3, const double B1[9], double F
                  [385])
{
  double A1[9];
  static double g12[148225];
  int k;
  double C1[9];
  double b_C1[9];
  double c_C1[9];
  double d_C1[9];
  int i;
  double dv0[9];
  int i0;
  double dv1[9];
  int i1;
  double T1[9];
  creal_T dcv0[4];
  creal_T X1[4];
  creal_T E1[4];
  static const double b[4] = { 0.0, 0.5, 0.5, 0.0 };

  static const double b_b[4] = { 0.5, 0.0, 0.0, -0.5 };

  static const double dv2[4] = { 0.0, 0.5, -0.5, 0.0 };

  static const double c_b[9] = { 1.001298, 0.0, 0.0, 0.0, 1.001832, 0.0, 0.0,
    0.0, 1.001952 };

  creal_T dcv1[2];
  double E[2];

  /* 31P jaoks 600MHz väljas [Hz] */
  /* nihke tensor PAS-s */
  poore(a1, a2, a3, A1);

  /* a1k(m),a2k(m),a3k(m)); */
  /* A1i=inv(A1); */
  /* 5/2 tuuma spinni operaatorid */
  /* mõõteoperaator: */
  /* nivoode vahe */
  /* intensiivsus */
  memset(&g12[0], 0, 148225U * sizeof(double));
  for (k = 0; k < 385; k++) {
    poore(-12.0 + (double)k, 90.0, 0.0, C1);

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

    mrdivide(b_C1, A1, dv0);
    mrdivide(dv0, B1, dv1);
    mrdivide(dv1, C1, T1);
    for (i = 0; i < 4; i++) {
      dcv0[i].re = 8.0986E+7 * ((T1[2] * b[i] + T1[5] * 0.0) + T1[8] * b_b[i]);
      dcv0[i].im = 8.0986E+7 * (T1[5] * dv2[i]);
    }

    eig(dcv0, X1, E1);

    /* X on maatriks omavektoritest ,E on omavaartused */
    diag(E1, dcv1);
    for (i = 0; i < 2; i++) {
      E[i] = dcv1[i].re;
    }

    /* sagedus */
    g12[k] = E[1] - E[0];
    F[k] = (g12[k] - 8.0986E+7) / 8.0986E+7 * 100.0;

    /* intensiivsus */
  }

  /* F(1,:) */
}

/*
 * File trailer for calculations.c
 *
 * [EOF]
 */
