/*
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "mod.h"

/* Function Definitions */
int32_T b_mod(int32_T x)
{
  return x - x / 10 * 10;
}

/* End of code generation (mod.c) */
