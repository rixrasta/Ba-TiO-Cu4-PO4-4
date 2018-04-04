/*
 * calculations.h
 *
 * Code generation for function 'calculations'
 *
 */

#ifndef CALCULATIONS_H
#define CALCULATIONS_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "calculations_types.h"

/* Function Declarations */
extern void calculations(calculationsStackData *SD, const emlrtStack *sp, real_T
  a1, real_T a2, real_T a3, const real_T B1[9], real_T F[385]);

#endif

/* End of code generation (calculations.h) */
