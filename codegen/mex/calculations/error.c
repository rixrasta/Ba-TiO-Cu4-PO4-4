/*
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 17, 9, "error",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"
};

/* Function Definitions */
void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
    3, 4, 4, "sqrt");
}

/* End of code generation (error.c) */
