/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "abs.h"

/* Function Definitions */
void b_abs(const creal_T x[4], real_T y[4])
{
  int32_T k;
  for (k = 0; k < 4; k++) {
    y[k] = muDoubleScalarHypot(x[k].re, x[k].im);
  }
}

/* End of code generation (abs.c) */
