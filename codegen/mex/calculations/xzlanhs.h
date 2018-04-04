/*
 * xzlanhs.h
 *
 * Code generation for function 'xzlanhs'
 *
 */

#ifndef XZLANHS_H
#define XZLANHS_H

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
extern real_T xzlanhs(const emlrtStack *sp, const creal_T A[4], int32_T ilo,
                      int32_T ihi);

#ifdef __WATCOMC__

#pragma aux xzlanhs value [8087];

#endif
#endif

/* End of code generation (xzlanhs.h) */
