/*
 * xzggev.h
 *
 * Code generation for function 'xzggev'
 *
 */

#ifndef XZGGEV_H
#define XZGGEV_H

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
extern void xzggev(const emlrtStack *sp, creal_T A[4], int32_T *info, creal_T
                   alpha1[2], creal_T beta1[2], creal_T V[4]);

#endif

/* End of code generation (xzggev.h) */
