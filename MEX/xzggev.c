/*
 * File: xzggev.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:43:28
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzggev.h"
#include "xztgevc.h"
#include "xzhgeqz.h"
#include "isfinite.h"
#include "xzlangeM.h"

/* Function Definitions */

/*
 * Arguments    : creal_T A[4]
 *                int *info
 *                creal_T alpha1[2]
 *                creal_T beta1[2]
 *                creal_T V[4]
 * Return Type  : void
 */
void xzggev(creal_T A[4], int *info, creal_T alpha1[2], creal_T beta1[2],
            creal_T V[4])
{
  double anrm;
  boolean_T ilascl;
  double anrmto;
  int i;
  int nzcount;
  double cfromc;
  signed char rscale[2];
  double ctoc;
  boolean_T notdone;
  int ilo;
  int ihi;
  double cfrom1;
  double cto1;
  int j;
  double mul;
  int ii;
  boolean_T exitg3;
  int jj;
  boolean_T exitg4;
  boolean_T exitg1;
  boolean_T guard2 = false;
  signed char I[4];
  boolean_T exitg2;
  boolean_T guard1 = false;
  *info = 0;
  anrm = xzlangeM(A);
  if (!b_isfinite(anrm)) {
    for (i = 0; i < 2; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (nzcount = 0; nzcount < 4; nzcount++) {
      V[nzcount].re = rtNaN;
      V[nzcount].im = 0.0;
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
      cfromc = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        cfrom1 = cfromc * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          cfromc = cfrom1;
        } else if (fabs(cto1) > fabs(cfromc)) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / cfromc;
          notdone = false;
        }

        for (nzcount = 0; nzcount < 4; nzcount++) {
          A[nzcount].re *= mul;
          A[nzcount].im *= mul;
        }
      }
    }

    for (i = 0; i < 2; i++) {
      rscale[i] = 1;
    }

    ilo = 1;
    ihi = 2;
    i = 0;
    j = 0;
    notdone = false;
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
        notdone = true;
        exitg3 = true;
      } else {
        ii--;
      }
    }

    if (!notdone) {
      i = 0;
      j = 0;
      notdone = false;
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
          if ((A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (A[(ii + ((jj - 1) <<
                 1)) - 1].im != 0.0) || (ii == jj)) {
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
          notdone = true;
          exitg1 = true;
        } else {
          jj++;
        }
      }

      if (!notdone) {
      } else {
        if (i != 1) {
          for (nzcount = 0; nzcount + 1 < 3; nzcount++) {
            cfromc = A[(i + (nzcount << 1)) - 1].re;
            ctoc = A[(i + (nzcount << 1)) - 1].im;
            A[(i + (nzcount << 1)) - 1] = A[nzcount << 1];
            A[nzcount << 1].re = cfromc;
            A[nzcount << 1].im = ctoc;
          }
        }

        if (j != 1) {
          for (nzcount = 0; nzcount + 1 < 3; nzcount++) {
            cfromc = A[nzcount + ((j - 1) << 1)].re;
            ctoc = A[nzcount + ((j - 1) << 1)].im;
            A[nzcount + ((j - 1) << 1)] = A[nzcount];
            A[nzcount].re = cfromc;
            A[nzcount].im = ctoc;
          }
        }

        rscale[0] = (signed char)j;
        ilo = 2;
        rscale[1] = 2;
      }
    } else {
      if (i != 2) {
        for (nzcount = 0; nzcount < 2; nzcount++) {
          cfromc = A[nzcount << 1].re;
          ctoc = A[nzcount << 1].im;
          A[nzcount << 1] = A[1 + (nzcount << 1)];
          A[1 + (nzcount << 1)].re = cfromc;
          A[1 + (nzcount << 1)].im = ctoc;
        }
      }

      if (j != 2) {
        for (nzcount = 0; nzcount + 1 < 3; nzcount++) {
          cfromc = A[nzcount].re;
          ctoc = A[nzcount].im;
          A[nzcount] = A[2 + nzcount];
          A[2 + nzcount].re = cfromc;
          A[2 + nzcount].im = ctoc;
        }
      }

      rscale[1] = (signed char)j;
      ihi = 1;
      rscale[0] = 1;
    }

    for (nzcount = 0; nzcount < 4; nzcount++) {
      I[nzcount] = 0;
    }

    for (nzcount = 0; nzcount < 2; nzcount++) {
      I[nzcount + (nzcount << 1)] = 1;
    }

    for (nzcount = 0; nzcount < 4; nzcount++) {
      V[nzcount].re = I[nzcount];
      V[nzcount].im = 0.0;
    }

    xzhgeqz(A, ilo, ihi, V, info, alpha1, beta1);
    if (*info != 0) {
    } else {
      xztgevc(A, V);
      if (ilo > 1) {
        for (i = 0; i + 1 >= 1; i--) {
          nzcount = rscale[i] - 1;
          if (rscale[i] != i + 1) {
            for (j = 0; j < 2; j++) {
              cfromc = V[i + (j << 1)].re;
              ctoc = V[i + (j << 1)].im;
              V[i + (j << 1)] = V[nzcount + (j << 1)];
              V[nzcount + (j << 1)].re = cfromc;
              V[nzcount + (j << 1)].im = ctoc;
            }
          }
        }
      }

      if (ihi < 2) {
        nzcount = rscale[1] - 1;
        if (rscale[1] != 2) {
          for (j = 0; j < 2; j++) {
            cfromc = V[1 + (j << 1)].re;
            ctoc = V[1 + (j << 1)].im;
            V[1 + (j << 1)] = V[nzcount + (j << 1)];
            V[nzcount + (j << 1)].re = cfromc;
            V[nzcount + (j << 1)].im = ctoc;
          }
        }
      }

      for (nzcount = 0; nzcount < 2; nzcount++) {
        cfromc = fabs(V[1 + (nzcount << 1)].re) + fabs(V[1 + (nzcount << 1)].im);
        ctoc = fabs(V[nzcount << 1].re) + fabs(V[nzcount << 1].im);
        if (cfromc > ctoc) {
          ctoc = cfromc;
        }

        if (ctoc >= 6.7178761075670888E-139) {
          ctoc = 1.0 / ctoc;
          for (ii = 0; ii < 2; ii++) {
            V[ii + (nzcount << 1)].re *= ctoc;
            V[ii + (nzcount << 1)].im *= ctoc;
          }
        }
      }

      if (ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          cto1 = anrm / 4.9896007738368E+291;
          if ((fabs(cfrom1) > fabs(anrm)) && (anrm != 0.0)) {
            mul = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (fabs(cto1) > fabs(anrmto)) {
            mul = 4.9896007738368E+291;
            anrm = cto1;
          } else {
            mul = anrm / anrmto;
            notdone = false;
          }

          for (nzcount = 0; nzcount < 2; nzcount++) {
            alpha1[nzcount].re *= mul;
            alpha1[nzcount].im *= mul;
          }
        }
      }
    }
  }
}

/*
 * File trailer for xzggev.c
 *
 * [EOF]
 */
