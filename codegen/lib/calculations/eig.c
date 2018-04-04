/*
 * File: eig.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "eig.h"
#include "xzggev.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T A[4]
 *                creal_T V[4]
 *                creal_T D[4]
 * Return Type  : void
 */
void eig(const creal_T A[4], creal_T V[4], creal_T D[4])
{
  creal_T At[4];
  int info;
  creal_T alpha1[2];
  creal_T beta1[2];
  int coltop;
  double colnorm;
  double scale;
  double absxk;
  double t;
  memcpy(&At[0], &A[0], sizeof(creal_T) << 2);
  xzggev(At, &info, alpha1, beta1, V);
  for (coltop = 0; coltop <= 3; coltop += 2) {
    colnorm = 0.0;
    scale = 2.2250738585072014E-308;
    for (info = coltop; info + 1 <= coltop + 2; info++) {
      absxk = fabs(V[info].re);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }

      absxk = fabs(V[info].im);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }
    }

    colnorm = scale * sqrt(colnorm);
    for (info = coltop; info + 1 <= coltop + 2; info++) {
      if (V[info].im == 0.0) {
        V[info].re /= colnorm;
        V[info].im = 0.0;
      } else if (V[info].re == 0.0) {
        V[info].re = 0.0;
        V[info].im /= colnorm;
      } else {
        V[info].re /= colnorm;
        V[info].im /= colnorm;
      }
    }
  }

  for (info = 0; info < 4; info++) {
    D[info].re = 0.0;
    D[info].im = 0.0;
  }

  for (info = 0; info < 2; info++) {
    if (beta1[info].im == 0.0) {
      if (alpha1[info].im == 0.0) {
        D[info + (info << 1)].re = alpha1[info].re / beta1[info].re;
        D[info + (info << 1)].im = 0.0;
      } else if (alpha1[info].re == 0.0) {
        D[info + (info << 1)].re = 0.0;
        D[info + (info << 1)].im = alpha1[info].im / beta1[info].re;
      } else {
        D[info + (info << 1)].re = alpha1[info].re / beta1[info].re;
        D[info + (info << 1)].im = alpha1[info].im / beta1[info].re;
      }
    } else if (beta1[info].re == 0.0) {
      if (alpha1[info].re == 0.0) {
        D[info + (info << 1)].re = alpha1[info].im / beta1[info].im;
        D[info + (info << 1)].im = 0.0;
      } else if (alpha1[info].im == 0.0) {
        D[info + (info << 1)].re = 0.0;
        D[info + (info << 1)].im = -(alpha1[info].re / beta1[info].im);
      } else {
        D[info + (info << 1)].re = alpha1[info].im / beta1[info].im;
        D[info + (info << 1)].im = -(alpha1[info].re / beta1[info].im);
      }
    } else {
      absxk = fabs(beta1[info].re);
      colnorm = fabs(beta1[info].im);
      if (absxk > colnorm) {
        colnorm = beta1[info].im / beta1[info].re;
        scale = beta1[info].re + colnorm * beta1[info].im;
        D[info + (info << 1)].re = (alpha1[info].re + colnorm * alpha1[info].im)
          / scale;
        D[info + (info << 1)].im = (alpha1[info].im - colnorm * alpha1[info].re)
          / scale;
      } else if (colnorm == absxk) {
        if (beta1[info].re > 0.0) {
          colnorm = 0.5;
        } else {
          colnorm = -0.5;
        }

        if (beta1[info].im > 0.0) {
          scale = 0.5;
        } else {
          scale = -0.5;
        }

        D[info + (info << 1)].re = (alpha1[info].re * colnorm + alpha1[info].im *
          scale) / absxk;
        D[info + (info << 1)].im = (alpha1[info].im * colnorm - alpha1[info].re *
          scale) / absxk;
      } else {
        colnorm = beta1[info].re / beta1[info].im;
        scale = beta1[info].im + colnorm * beta1[info].re;
        D[info + (info << 1)].re = (colnorm * alpha1[info].re + alpha1[info].im)
          / scale;
        D[info + (info << 1)].im = (colnorm * alpha1[info].im - alpha1[info].re)
          / scale;
      }
    }
  }
}

/*
 * File trailer for eig.c
 *
 * [EOF]
 */
