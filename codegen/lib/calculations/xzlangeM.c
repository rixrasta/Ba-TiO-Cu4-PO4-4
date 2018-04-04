/*
 * File: xzlangeM.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzlangeM.h"
#include "xzlartg.h"
#include "calculations_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x[4]
 * Return Type  : double
 */
double xzlangeM(const creal_T x[4])
{
  double y;
  int k;
  boolean_T exitg1;
  double absxk;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    absxk = rt_hypotd_snf(x[k].re, x[k].im);
    if (rtIsNaN(absxk)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > y) {
        y = absxk;
      }

      k++;
    }
  }

  return y;
}

/*
 * File trailer for xzlangeM.c
 *
 * [EOF]
 */
