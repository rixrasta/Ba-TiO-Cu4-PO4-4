/*
 * File: xzhgeqz.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "sqrt.h"
#include "mod.h"
#include "xzlanhs.h"
#include "calculations_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : creal_T A[4]
 *                int ilo
 *                int ihi
 *                creal_T Z[4]
 *                int *info
 *                creal_T alpha1[2]
 *                creal_T beta1[2]
 * Return Type  : void
 */
void xzhgeqz(creal_T A[4], int ilo, int ihi, creal_T Z[4], int *info, creal_T
             alpha1[2], creal_T beta1[2])
{
  int jp1;
  double eshift_re;
  double eshift_im;
  double ctemp_re;
  double ctemp_im;
  double anorm;
  double temp2;
  double b_atol;
  double d;
  double ascale;
  boolean_T failed;
  int j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ifirst;
  int istart;
  int ilast;
  int ilastm1;
  int iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int exitg1;
  boolean_T exitg3;
  boolean_T ilazro;
  boolean_T b_guard1 = false;
  double ad22_re;
  double ad22_im;
  creal_T shift;
  double c;
  double t1_re;
  boolean_T exitg2;
  double t1_im;
  boolean_T guard3 = false;
  double tempr;
  int x;
  *info = 0;
  for (jp1 = 0; jp1 < 2; jp1++) {
    alpha1[jp1].re = 0.0;
    alpha1[jp1].im = 0.0;
    beta1[jp1].re = 1.0;
    beta1[jp1].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp_re = 0.0;
  ctemp_im = 0.0;
  anorm = xzlanhs(A, ilo, ihi);
  temp2 = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp2 > 2.2250738585072014E-308) {
    b_atol = temp2;
  }

  d = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    d = anorm;
  }

  ascale = 1.0 / d;
  failed = true;
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
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1)) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (fabs(A[ilast + (ilastm1 << 1)].re) + fabs(A[ilast + (ilastm1 <<
          1)].im) <= b_atol) {
          A[ilast + (ilastm1 << 1)].re = 0.0;
          A[ilast + (ilastm1 << 1)].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (fabs(A[j + ((j - 1) << 1)].re) + fabs(A[j + ((j - 1) << 1)]
                        .im) <= b_atol) {
              A[j].re = 0.0;
              A[j].im = 0.0;
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
                temp2 = ascale * A[ilastm1 + (ilastm1 << 1)].im;
                if (temp2 == 0.0) {
                  shift.re = anorm / 0.70710678118654746;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = temp2 / 0.70710678118654746;
                } else {
                  shift.re = anorm / 0.70710678118654746;
                  shift.im = temp2 / 0.70710678118654746;
                }

                anorm = ascale * A[ilast + (ilast << 1)].re;
                temp2 = ascale * A[ilast + (ilast << 1)].im;
                if (temp2 == 0.0) {
                  ad22_re = anorm / 0.70710678118654746;
                  ad22_im = 0.0;
                } else if (anorm == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = temp2 / 0.70710678118654746;
                } else {
                  ad22_re = anorm / 0.70710678118654746;
                  ad22_im = temp2 / 0.70710678118654746;
                }

                t1_re = 0.5 * (shift.re + ad22_re);
                t1_im = 0.5 * (shift.im + ad22_im);
                anorm = ascale * A[ilastm1 + (ilast << 1)].re;
                temp2 = ascale * A[ilastm1 + (ilast << 1)].im;
                if (temp2 == 0.0) {
                  d = anorm / 0.70710678118654746;
                  c = 0.0;
                } else if (anorm == 0.0) {
                  d = 0.0;
                  c = temp2 / 0.70710678118654746;
                } else {
                  d = anorm / 0.70710678118654746;
                  c = temp2 / 0.70710678118654746;
                }

                anorm = ascale * A[ilast + (ilastm1 << 1)].re;
                temp2 = ascale * A[ilast + (ilastm1 << 1)].im;
                if (temp2 == 0.0) {
                  tempr = anorm / 0.70710678118654746;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  tempr = 0.0;
                  anorm = temp2 / 0.70710678118654746;
                } else {
                  tempr = anorm / 0.70710678118654746;
                  anorm = temp2 / 0.70710678118654746;
                }

                temp2 = shift.re * ad22_im + shift.im * ad22_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) + (d * tempr - c *
                  anorm)) - (shift.re * ad22_re - shift.im * ad22_im);
                shift.im = ((t1_re * t1_im + t1_im * t1_re) + (d * anorm + c *
                  tempr)) - temp2;
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
                temp2 = ascale * A[ilast + (ilastm1 << 1)].im;
                if (temp2 == 0.0) {
                  d = anorm / 0.70710678118654746;
                  c = 0.0;
                } else if (anorm == 0.0) {
                  d = 0.0;
                  c = temp2 / 0.70710678118654746;
                } else {
                  d = anorm / 0.70710678118654746;
                  c = temp2 / 0.70710678118654746;
                }

                eshift_re += d;
                eshift_im += c;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp_re = ascale * A[j + (j << 1)].re - shift.re *
                  0.70710678118654746;
                ctemp_im = ascale * A[j + (j << 1)].im - shift.im *
                  0.70710678118654746;
                anorm = fabs(ctemp_re) + fabs(ctemp_im);
                temp2 = ascale * (fabs(A[jp1 + (j << 1)].re) + fabs(A[jp1 + (j <<
                  1)].im));
                tempr = anorm;
                if (temp2 > anorm) {
                  tempr = temp2;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  anorm /= tempr;
                  temp2 /= tempr;
                }

                if ((fabs(A[j + ((j - 1) << 1)].re) + fabs(A[j + ((j - 1) << 1)]
                      .im)) * temp2 <= anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                ctemp_re = ascale * A[(ifirst + ((ifirst - 1) << 1)) - 1].re -
                  shift.re * 0.70710678118654746;
                ctemp_im = ascale * A[(ifirst + ((ifirst - 1) << 1)) - 1].im -
                  shift.im * 0.70710678118654746;
                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              ad22_re = ascale * A[istart + ((istart - 1) << 1)].re;
              ad22_im = ascale * A[istart + ((istart - 1) << 1)].im;
              anorm = fabs(ctemp_re);
              temp2 = fabs(ctemp_im);
              if (temp2 > anorm) {
                anorm = temp2;
              }

              d = fabs(ad22_re);
              temp2 = fabs(ad22_im);
              if (temp2 > d) {
                d = temp2;
              }

              if (d > anorm) {
                anorm = d;
              }

              shift.re = ctemp_re;
              shift.im = ctemp_im;
              guard3 = false;
              if (anorm >= 7.4428285367870146E+137) {
                do {
                  shift.re *= 1.3435752215134178E-138;
                  shift.im *= 1.3435752215134178E-138;
                  ad22_re *= 1.3435752215134178E-138;
                  ad22_im *= 1.3435752215134178E-138;
                  anorm *= 1.3435752215134178E-138;
                } while (!(anorm < 7.4428285367870146E+137));

                guard3 = true;
              } else if (anorm <= 1.3435752215134178E-138) {
                if ((ad22_re == 0.0) && (ad22_im == 0.0)) {
                  c = 1.0;
                  shift.re = 0.0;
                  shift.im = 0.0;
                } else {
                  do {
                    shift.re *= 7.4428285367870146E+137;
                    shift.im *= 7.4428285367870146E+137;
                    ad22_re *= 7.4428285367870146E+137;
                    ad22_im *= 7.4428285367870146E+137;
                    anorm *= 7.4428285367870146E+137;
                  } while (!(anorm > 1.3435752215134178E-138));

                  guard3 = true;
                }
              } else {
                guard3 = true;
              }

              if (guard3) {
                anorm = shift.re * shift.re + shift.im * shift.im;
                temp2 = ad22_re * ad22_re + ad22_im * ad22_im;
                d = temp2;
                if (1.0 > temp2) {
                  d = 1.0;
                }

                if (anorm <= d * 2.0041683600089728E-292) {
                  if ((ctemp_re == 0.0) && (ctemp_im == 0.0)) {
                    c = 0.0;
                    d = rt_hypotd_snf(ad22_re, ad22_im);
                    shift.re = ad22_re / d;
                    shift.im = -ad22_im / d;
                  } else {
                    tempr = sqrt(temp2);
                    c = rt_hypotd_snf(shift.re, shift.im) / tempr;
                    d = fabs(ctemp_re);
                    temp2 = fabs(ctemp_im);
                    if (temp2 > d) {
                      d = temp2;
                    }

                    if (d > 1.0) {
                      d = rt_hypotd_snf(ctemp_re, ctemp_im);
                      shift.re = ctemp_re / d;
                      shift.im = ctemp_im / d;
                    } else {
                      anorm = 7.4428285367870146E+137 * ctemp_re;
                      temp2 = 7.4428285367870146E+137 * ctemp_im;
                      d = rt_hypotd_snf(anorm, temp2);
                      shift.re = anorm / d;
                      shift.im = temp2 / d;
                    }

                    ad22_re /= tempr;
                    ad22_im = -ad22_im / tempr;
                    anorm = shift.re;
                    shift.re = shift.re * ad22_re - shift.im * ad22_im;
                    shift.im = anorm * ad22_im + shift.im * ad22_re;
                  }
                } else {
                  tempr = sqrt(1.0 + temp2 / anorm);
                  c = 1.0 / tempr;
                  d = anorm + temp2;
                  anorm = tempr * shift.re / d;
                  temp2 = tempr * shift.im / d;
                  shift.re = anorm * ad22_re - temp2 * -ad22_im;
                  shift.im = anorm * -ad22_im + temp2 * ad22_re;
                }
              }

              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  xzlartg(A[1 + (jp1 << 1)], A[j + (jp1 << 1)], &c, &shift, &A[1
                          + (jp1 << 1)]);
                  A[2 + (jp1 << 1)].re = 0.0;
                  A[2 + (jp1 << 1)].im = 0.0;
                }

                for (jp1 = j - 1; jp1 + 1 < 3; jp1++) {
                  ad22_re = c * A[(j + (jp1 << 1)) - 1].re + (shift.re * A[1 +
                    (jp1 << 1)].re - shift.im * A[1 + (jp1 << 1)].im);
                  ad22_im = c * A[(j + (jp1 << 1)) - 1].im + (shift.re * A[1 +
                    (jp1 << 1)].im + shift.im * A[1 + (jp1 << 1)].re);
                  anorm = A[(j + (jp1 << 1)) - 1].im;
                  temp2 = A[(j + (jp1 << 1)) - 1].re;
                  A[1 + (jp1 << 1)].re = c * A[j + (jp1 << 1)].re - (shift.re *
                    A[(j + (jp1 << 1)) - 1].re + shift.im * A[(j + (jp1 << 1)) -
                    1].im);
                  A[1 + (jp1 << 1)].im = c * A[j + (jp1 << 1)].im - (shift.re *
                    anorm - shift.im * temp2);
                  A[(j + (jp1 << 1)) - 1].re = ad22_re;
                  A[(j + (jp1 << 1)) - 1].im = ad22_im;
                }

                shift.re = -shift.re;
                shift.im = -shift.im;
                x = j;
                if (ilast + 1 < j + 2) {
                  x = ilast - 1;
                }

                for (jp1 = 0; jp1 + 1 <= x + 2; jp1++) {
                  ad22_re = c * A[jp1 + (j << 1)].re + (shift.re * A[jp1 + ((j -
                    1) << 1)].re - shift.im * A[jp1 + ((j - 1) << 1)].im);
                  ad22_im = c * A[jp1 + (j << 1)].im + (shift.re * A[jp1 + ((j -
                    1) << 1)].im + shift.im * A[jp1 + ((j - 1) << 1)].re);
                  anorm = A[jp1 + (j << 1)].im;
                  temp2 = A[jp1 + (j << 1)].re;
                  A[jp1 + ((j - 1) << 1)].re = c * A[jp1 + ((j - 1) << 1)].re -
                    (shift.re * A[jp1 + (j << 1)].re + shift.im * A[jp1 + (j <<
                      1)].im);
                  A[jp1 + ((j - 1) << 1)].im = c * A[jp1 + ((j - 1) << 1)].im -
                    (shift.re * anorm - shift.im * temp2);
                  A[2 + jp1].re = ad22_re;
                  A[2 + jp1].im = ad22_im;
                }

                for (jp1 = 0; jp1 < 2; jp1++) {
                  ad22_re = c * Z[jp1 + (j << 1)].re + (shift.re * Z[jp1 + ((j -
                    1) << 1)].re - shift.im * Z[jp1 + ((j - 1) << 1)].im);
                  ad22_im = c * Z[jp1 + (j << 1)].im + (shift.re * Z[jp1 + ((j -
                    1) << 1)].im + shift.im * Z[jp1 + ((j - 1) << 1)].re);
                  anorm = Z[jp1 + (j << 1)].im;
                  temp2 = Z[jp1 + (j << 1)].re;
                  Z[jp1 + ((j - 1) << 1)].re = c * Z[jp1 + ((j - 1) << 1)].re -
                    (shift.re * Z[jp1 + (j << 1)].re + shift.im * Z[jp1 + (j <<
                      1)].im);
                  Z[jp1 + ((j - 1) << 1)].im = c * Z[jp1 + ((j - 1) << 1)].im -
                    (shift.re * anorm - shift.im * temp2);
                  Z[2 + jp1].re = ad22_re;
                  Z[2 + jp1].im = ad22_im;
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
    for (j = 0; j + 1 < ilo; j++) {
      alpha1[j] = A[j + (j << 1)];
    }
  }
}

/*
 * File trailer for xzhgeqz.c
 *
 * [EOF]
 */
