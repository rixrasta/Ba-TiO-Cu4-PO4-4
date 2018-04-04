/*
 * File: diag.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "diag.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T v[4]
 *                creal_T d[2]
 * Return Type  : void
 */
void diag(const creal_T v[4], creal_T d[2])
{
  int j;
  for (j = 0; j < 2; j++) {
    d[j] = v[j * 3];
  }
}

/*
 * File trailer for diag.c
 *
 * [EOF]
 */
