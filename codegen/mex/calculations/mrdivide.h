/*
 * mrdivide.h
 *
 * Code generation for function 'mrdivide'
 *
 */

#ifndef MRDIVIDE_H
#define MRDIVIDE_H

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
extern void mrdivide(const emlrtStack *sp, const real_T A[9], const real_T B[9],
                     real_T y[9]);

#endif

/* End of code generation (mrdivide.h) */
