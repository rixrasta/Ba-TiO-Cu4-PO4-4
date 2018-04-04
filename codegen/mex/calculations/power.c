/*
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "power.h"

/* Function Definitions */
void power(const real_T a[4], real_T y[4])
{
  int32_T k;
  for (k = 0; k < 4; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
