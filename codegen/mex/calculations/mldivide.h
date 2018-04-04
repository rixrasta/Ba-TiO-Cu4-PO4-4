/*
 * mldivide.h
 *
 * Code generation for function 'mldivide'
 *
 */

#ifndef MLDIVIDE_H
#define MLDIVIDE_H

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
extern void mldivide(const emlrtStack *sp, const creal_T A[4], const real_T B[4],
                     creal_T Y[4]);

#endif

/* End of code generation (mldivide.h) */
