/*
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "diag.h"

/* Function Definitions */
void diag(const creal_T v[4], creal_T d[2])
{
  int32_T j;
  for (j = 0; j < 2; j++) {
    d[j] = v[j * 3];
  }
}

/* End of code generation (diag.c) */
