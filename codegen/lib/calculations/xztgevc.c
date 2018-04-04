/*
 * File: xztgevc.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xztgevc.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T A[4]
 *                creal_T V[4]
 * Return Type  : void
 */
void xztgevc(const creal_T A[4], creal_T V[4])
{
  double d_re;
  double anorm;
  double xmx;
  double ascale;
  int je;
  double temp;
  double salpha_re;
  double salpha_im;
  double acoeff;
  boolean_T b0;
  boolean_T b1;
  double scale;
  creal_T work1[2];
  int jr;
  double dmin;
  creal_T work2[2];
  double d_im;
  int jc;
  double work1_re;
  d_re = (fabs(A[2].re) + fabs(A[2].im)) + (fabs(A[3].re) + fabs(A[3].im));
  anorm = fabs(A[0].re) + fabs(A[0].im);
  if (d_re > anorm) {
    anorm = d_re;
  }

  xmx = anorm;
  if (2.2250738585072014E-308 > anorm) {
    xmx = 2.2250738585072014E-308;
  }

  ascale = 1.0 / xmx;
  for (je = 0; je < 2; je++) {
    xmx = (fabs(A[(((1 - je) << 1) - je) + 1].re) + fabs(A[(((1 - je) << 1) - je)
            + 1].im)) * ascale;
    if (1.0 > xmx) {
      xmx = 1.0;
    }

    temp = 1.0 / xmx;
    salpha_re = ascale * (temp * A[(((1 - je) << 1) - je) + 1].re);
    salpha_im = ascale * (temp * A[(((1 - je) << 1) - je) + 1].im);
    acoeff = temp * ascale;
    if ((fabs(temp) >= 2.2250738585072014E-308) && (fabs(acoeff) <
         2.0041683600089728E-292)) {
      b0 = true;
    } else {
      b0 = false;
    }

    if ((fabs(salpha_re) + fabs(salpha_im) >= 2.2250738585072014E-308) && (fabs
         (salpha_re) + fabs(salpha_im) < 2.0041683600089728E-292)) {
      b1 = true;
    } else {
      b1 = false;
    }

    scale = 1.0;
    if (b0) {
      xmx = anorm;
      if (4.9896007738368E+291 < anorm) {
        xmx = 4.9896007738368E+291;
      }

      scale = 2.0041683600089728E-292 / fabs(temp) * xmx;
    }

    if (b1) {
      d_re = 2.0041683600089728E-292 / (fabs(salpha_re) + fabs(salpha_im));
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (b0 || b1) {
      xmx = fabs(acoeff);
      d_re = fabs(salpha_re) + fabs(salpha_im);
      if (1.0 > xmx) {
        xmx = 1.0;
      }

      if (d_re > xmx) {
        xmx = d_re;
      }

      d_re = 1.0 / (2.2250738585072014E-308 * xmx);
      if (d_re < scale) {
        scale = d_re;
      }

      if (b0) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      if (b1) {
        salpha_re *= scale;
        salpha_im *= scale;
      } else {
        salpha_re *= scale;
        salpha_im *= scale;
      }
    }

    for (jr = 0; jr < 2; jr++) {
      work1[jr].re = 0.0;
      work1[jr].im = 0.0;
    }

    work1[1 - je].re = 1.0;
    work1[1 - je].im = 0.0;
    dmin = 2.2204460492503131E-16 * fabs(acoeff) * anorm;
    d_re = 2.2204460492503131E-16 * (fabs(salpha_re) + fabs(salpha_im));
    if (d_re > dmin) {
      dmin = d_re;
    }

    if (2.2250738585072014E-308 > dmin) {
      dmin = 2.2250738585072014E-308;
    }

    jr = 0;
    while (jr <= -je) {
      work1[0].re = acoeff * A[(1 - je) << 1].re;
      work1[0].im = acoeff * A[(1 - je) << 1].im;
      jr = 1;
    }

    work1[1 - je].re = 1.0;
    work1[1 - je].im = 0.0;
    jr = 0;
    while (jr <= -je) {
      d_re = acoeff * A[0].re - salpha_re;
      d_im = acoeff * A[0].im - salpha_im;
      if (fabs(d_re) + fabs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0;
      }

      if ((fabs(d_re) + fabs(d_im) < 1.0) && (fabs(work1[0].re) + fabs(work1[0].
            im) >= 2.2471164185778949E+307 * (fabs(d_re) + fabs(d_im)))) {
        temp = 1.0 / (fabs(work1[0].re) + fabs(work1[0].im));
        for (jr = 0; jr <= 1 - je; jr++) {
          work1[jr].re *= temp;
          work1[jr].im *= temp;
        }
      }

      work1_re = -work1[0].re;
      if (d_im == 0.0) {
        if (-work1[0].im == 0.0) {
          work1[0].re = -work1[0].re / d_re;
          work1[0].im = 0.0;
        } else if (-work1[0].re == 0.0) {
          work1[0].re = 0.0;
          work1[0].im = -work1[0].im / d_re;
        } else {
          work1[0].re = -work1[0].re / d_re;
          work1[0].im = -work1[0].im / d_re;
        }
      } else if (d_re == 0.0) {
        if (-work1[0].re == 0.0) {
          work1[0].re = -work1[0].im / d_im;
          work1[0].im = 0.0;
        } else if (-work1[0].im == 0.0) {
          work1[0].re = 0.0;
          work1[0].im = -(work1_re / d_im);
        } else {
          work1[0].re = -work1[0].im / d_im;
          work1[0].im = -(work1_re / d_im);
        }
      } else {
        temp = fabs(d_re);
        xmx = fabs(d_im);
        if (temp > xmx) {
          scale = d_im / d_re;
          xmx = d_re + scale * d_im;
          work1[0].re = (-work1[0].re + scale * -work1[0].im) / xmx;
          work1[0].im = (-work1[0].im - scale * work1_re) / xmx;
        } else if (xmx == temp) {
          if (d_re > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          if (d_im > 0.0) {
            xmx = 0.5;
          } else {
            xmx = -0.5;
          }

          work1[0].re = (-work1[0].re * scale + -work1[0].im * xmx) / temp;
          work1[0].im = (-work1[0].im * scale - work1_re * xmx) / temp;
        } else {
          scale = d_re / d_im;
          xmx = d_im + scale * d_re;
          work1[0].re = (scale * -work1[0].re + -work1[0].im) / xmx;
          work1[0].im = (scale * -work1[0].im - work1_re) / xmx;
        }
      }

      jr = 1;
    }

    for (jr = 0; jr < 2; jr++) {
      work2[jr].re = 0.0;
      work2[jr].im = 0.0;
    }

    for (jc = 0; jc <= 1 - je; jc++) {
      for (jr = 0; jr < 2; jr++) {
        work2[jr].re += V[jr + (jc << 1)].re * work1[jc].re - V[jr + (jc << 1)].
          im * work1[jc].im;
        work2[jr].im += V[jr + (jc << 1)].re * work1[jc].im + V[jr + (jc << 1)].
          im * work1[jc].re;
      }
    }

    d_re = fabs(work2[1].re) + fabs(work2[1].im);
    xmx = fabs(work2[0].re) + fabs(work2[0].im);
    if (d_re > xmx) {
      xmx = d_re;
    }

    if (xmx > 2.2250738585072014E-308) {
      temp = 1.0 / xmx;
      for (jr = 0; jr < 2; jr++) {
        V[jr + ((1 - je) << 1)].re = temp * work2[jr].re;
        V[jr + ((1 - je) << 1)].im = temp * work2[jr].im;
      }
    } else {
      for (jr = 0; jr < 2; jr++) {
        V[jr + ((1 - je) << 1)].re = 0.0;
        V[jr + ((1 - je) << 1)].im = 0.0;
      }
    }
  }
}

/*
 * File trailer for xztgevc.c
 *
 * [EOF]
 */
