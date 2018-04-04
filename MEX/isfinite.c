/*
 * File: isfinite.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:43:28
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "isfinite.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : boolean_T
 */
boolean_T b_isfinite(double x)
{
  return (!rtIsInf(x)) && (!rtIsNaN(x));
}

/*
 * File trailer for isfinite.c
 *
 * [EOF]
 */
