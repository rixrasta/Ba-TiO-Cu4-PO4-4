/*
 * xzggbal.c
 *
 * Code generation for function 'xzggbal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzggbal.h"

/* Function Definitions */
void xzggbal(creal_T A[4], int32_T *ilo, int32_T *ihi, int32_T rscale[2])
{
  int32_T i;
  int32_T j;
  boolean_T found;
  int32_T ii;
  boolean_T exitg3;
  int32_T nzcount;
  int32_T jj;
  boolean_T exitg4;
  real_T atmp_re;
  real_T atmp_im;
  boolean_T exitg1;
  boolean_T guard2 = false;
  boolean_T exitg2;
  boolean_T guard1 = false;
  for (i = 0; i < 2; i++) {
    rscale[i] = 1;
  }

  *ilo = 1;
  *ihi = 2;
  i = 0;
  j = 0;
  found = false;
  ii = 2;
  exitg3 = false;
  while ((!exitg3) && (ii > 0)) {
    nzcount = 0;
    i = ii;
    j = 2;
    jj = 1;
    exitg4 = false;
    while ((!exitg4) && (jj <= 2)) {
      guard2 = false;
      if ((A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (A[(ii + ((jj - 1) << 1))
           - 1].im != 0.0) || (ii == jj)) {
        if (nzcount == 0) {
          j = jj;
          nzcount = 1;
          guard2 = true;
        } else {
          nzcount = 2;
          exitg4 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        jj++;
      }
    }

    if (nzcount < 2) {
      found = true;
      exitg3 = true;
    } else {
      ii--;
    }
  }

  if (!found) {
    i = 0;
    j = 0;
    found = false;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 2)) {
      nzcount = 0;
      i = 2;
      j = jj;
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii <= 2)) {
        guard1 = false;
        if ((A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (A[(ii + ((jj - 1) << 1))
             - 1].im != 0.0) || (ii == jj)) {
          if (nzcount == 0) {
            i = ii;
            nzcount = 1;
            guard1 = true;
          } else {
            nzcount = 2;
            exitg2 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ii++;
        }
      }

      if (nzcount < 2) {
        found = true;
        exitg1 = true;
      } else {
        jj++;
      }
    }

    if (!found) {
    } else {
      if (i != 1) {
        for (ii = 0; ii + 1 < 3; ii++) {
          atmp_re = A[(i + (ii << 1)) - 1].re;
          atmp_im = A[(i + (ii << 1)) - 1].im;
          A[(i + (ii << 1)) - 1] = A[ii << 1];
          A[ii << 1].re = atmp_re;
          A[ii << 1].im = atmp_im;
        }
      }

      if (j != 1) {
        for (ii = 0; ii + 1 < 3; ii++) {
          atmp_re = A[ii + ((j - 1) << 1)].re;
          atmp_im = A[ii + ((j - 1) << 1)].im;
          A[ii + ((j - 1) << 1)] = A[ii];
          A[ii].re = atmp_re;
          A[ii].im = atmp_im;
        }
      }

      rscale[0] = j;
      *ilo = 2;
      rscale[1] = 2;
    }
  } else {
    if (i != 2) {
      for (ii = 0; ii < 2; ii++) {
        atmp_re = A[(i + (ii << 1)) - 1].re;
        atmp_im = A[(i + (ii << 1)) - 1].im;
        A[(i + (ii << 1)) - 1] = A[1 + (ii << 1)];
        A[1 + (ii << 1)].re = atmp_re;
        A[1 + (ii << 1)].im = atmp_im;
      }
    }

    if (j != 2) {
      for (ii = 0; ii + 1 < 3; ii++) {
        atmp_re = A[ii + ((j - 1) << 1)].re;
        atmp_im = A[ii + ((j - 1) << 1)].im;
        A[ii + ((j - 1) << 1)] = A[2 + ii];
        A[2 + ii].re = atmp_re;
        A[2 + ii].im = atmp_im;
      }
    }

    rscale[1] = j;
    *ihi = 1;
    rscale[0] = 1;
  }
}

/* End of code generation (xzggbal.c) */
