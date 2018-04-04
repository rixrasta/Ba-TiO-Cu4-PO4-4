/*
 * xztgevc.c
 *
 * Code generation for function 'xztgevc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xztgevc.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 113, 5, "xztgevc",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xztgevc.m"
};

/* Function Definitions */
void xztgevc(const emlrtStack *sp, const creal_T A[4], creal_T V[4])
{
  real_T d_re;
  real_T anorm;
  real_T xmx;
  real_T ascale;
  int32_T je;
  real_T temp;
  real_T salpha_re;
  real_T salpha_im;
  real_T acoeff;
  boolean_T b0;
  boolean_T b1;
  real_T scale;
  creal_T work1[2];
  int32_T jr;
  real_T dmin;
  creal_T work2[2];
  real_T d_im;
  int32_T jc;
  real_T work1_re;
  d_re = (muDoubleScalarAbs(A[2].re) + muDoubleScalarAbs(A[2].im)) +
    (muDoubleScalarAbs(A[3].re) + muDoubleScalarAbs(A[3].im));
  anorm = muDoubleScalarAbs(A[0].re) + muDoubleScalarAbs(A[0].im);
  if (d_re > anorm) {
    anorm = d_re;
  }

  xmx = anorm;
  if (2.2250738585072014E-308 > anorm) {
    xmx = 2.2250738585072014E-308;
  }

  ascale = 1.0 / xmx;
  for (je = 0; je < 2; je++) {
    xmx = (muDoubleScalarAbs(A[(((1 - je) << 1) - je) + 1].re) +
           muDoubleScalarAbs(A[(((1 - je) << 1) - je) + 1].im)) * ascale;
    if (1.0 > xmx) {
      xmx = 1.0;
    }

    temp = 1.0 / xmx;
    salpha_re = ascale * (temp * A[(((1 - je) << 1) - je) + 1].re);
    salpha_im = ascale * (temp * A[(((1 - je) << 1) - je) + 1].im);
    acoeff = temp * ascale;
    if ((muDoubleScalarAbs(temp) >= 2.2250738585072014E-308) &&
        (muDoubleScalarAbs(acoeff) < 2.0041683600089728E-292)) {
      b0 = true;
    } else {
      b0 = false;
    }

    if ((muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im) >=
         2.2250738585072014E-308) && (muDoubleScalarAbs(salpha_re) +
         muDoubleScalarAbs(salpha_im) < 2.0041683600089728E-292)) {
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

      scale = 2.0041683600089728E-292 / muDoubleScalarAbs(temp) * xmx;
    }

    if (b1) {
      d_re = 2.0041683600089728E-292 / (muDoubleScalarAbs(salpha_re) +
        muDoubleScalarAbs(salpha_im));
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (b0 || b1) {
      xmx = muDoubleScalarAbs(acoeff);
      d_re = muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im);
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
    dmin = 2.2204460492503131E-16 * muDoubleScalarAbs(acoeff) * anorm;
    d_re = 2.2204460492503131E-16 * (muDoubleScalarAbs(salpha_re) +
      muDoubleScalarAbs(salpha_im));
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
    emlrtForLoopVectorCheckR2012b((2.0 + -(real_T)je) - 1.0, -1.0, 1.0,
      mxDOUBLE_CLASS, 1 - je, &c_emlrtRTEI, sp);
    jr = 0;
    while (jr <= -je) {
      d_re = acoeff * A[(-je << 1) - je].re - salpha_re;
      d_im = acoeff * A[(-je << 1) - je].im - salpha_im;
      if (muDoubleScalarAbs(d_re) + muDoubleScalarAbs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0;
      }

      if ((muDoubleScalarAbs(d_re) + muDoubleScalarAbs(d_im) < 1.0) &&
          (muDoubleScalarAbs(work1[-je].re) + muDoubleScalarAbs(work1[-je].im) >=
           2.2471164185778949E+307 * (muDoubleScalarAbs(d_re) +
            muDoubleScalarAbs(d_im)))) {
        temp = 1.0 / (muDoubleScalarAbs(work1[-je].re) + muDoubleScalarAbs
                      (work1[-je].im));
        for (jr = 0; jr <= 1 - je; jr++) {
          work1[jr].re *= temp;
          work1[jr].im *= temp;
        }
      }

      work1_re = -work1[-je].re;
      if (d_im == 0.0) {
        if (-work1[-je].im == 0.0) {
          work1[-je].re = -work1[-je].re / d_re;
          work1[-je].im = 0.0;
        } else if (-work1[-je].re == 0.0) {
          work1[-je].re = 0.0;
          work1[-je].im = -work1[-je].im / d_re;
        } else {
          work1[-je].re = -work1[-je].re / d_re;
          work1[-je].im = -work1[-je].im / d_re;
        }
      } else if (d_re == 0.0) {
        if (-work1[-je].re == 0.0) {
          work1[-je].re = -work1[-je].im / d_im;
          work1[-je].im = 0.0;
        } else if (-work1[-je].im == 0.0) {
          work1[-je].re = 0.0;
          work1[-je].im = -(work1_re / d_im);
        } else {
          work1[-je].re = -work1[-je].im / d_im;
          work1[-je].im = -(work1_re / d_im);
        }
      } else {
        temp = muDoubleScalarAbs(d_re);
        xmx = muDoubleScalarAbs(d_im);
        if (temp > xmx) {
          scale = d_im / d_re;
          xmx = d_re + scale * d_im;
          work1[-je].re = (-work1[-je].re + scale * -work1[-je].im) / xmx;
          work1[-je].im = (-work1[-je].im - scale * work1_re) / xmx;
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

          work1[-je].re = (-work1[-je].re * scale + -work1[-je].im * xmx) / temp;
          work1[-je].im = (-work1[-je].im * scale - work1_re * xmx) / temp;
        } else {
          scale = d_re / d_im;
          xmx = d_im + scale * d_re;
          work1[-je].re = (scale * -work1[-je].re + -work1[-je].im) / xmx;
          work1[-je].im = (scale * -work1[-je].im - work1_re) / xmx;
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

    d_re = muDoubleScalarAbs(work2[1].re) + muDoubleScalarAbs(work2[1].im);
    xmx = muDoubleScalarAbs(work2[0].re) + muDoubleScalarAbs(work2[0].im);
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

/* End of code generation (xztgevc.c) */
