/*
 * File: xzlanhs.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzlanhs.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T A[4]
 *                int ilo
 *                int ihi
 * Return Type  : double
 */
double xzlanhs(const creal_T A[4], int ilo, int ihi)
{
  double f;
  double scale;
  double sumsq;
  boolean_T firstNonZero;
  int j;
  int i2;
  int i;
  double reAij;
  double imAij;
  double temp2;
  f = 0.0;
  if (ilo > ihi) {
  } else {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      i2 = j + 1;
      if (ihi < j + 1) {
        i2 = ihi;
      }

      for (i = ilo; i <= i2; i++) {
        reAij = A[(i + ((j - 1) << 1)) - 1].re;
        imAij = A[(i + ((j - 1) << 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = fabs(reAij);
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
          reAij = fabs(imAij);
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

    f = scale * sqrt(sumsq);
  }

  return f;
}

/*
 * File trailer for xzlanhs.c
 *
 * [EOF]
 */
