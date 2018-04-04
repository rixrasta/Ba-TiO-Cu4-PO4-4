/*
 * xzhgeqz.h
 *
 * Code generation for function 'xzhgeqz'
 *
 */

#ifndef XZHGEQZ_H
#define XZHGEQZ_H

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
extern void xzhgeqz(const emlrtStack *sp, creal_T A[4], int32_T ilo, int32_T ihi,
                    creal_T Z[4], int32_T *info, creal_T alpha1[2], creal_T
                    beta1[2]);

#endif

/* End of code generation (xzhgeqz.h) */
