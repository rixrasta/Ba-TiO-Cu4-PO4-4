/*
 * eig.h
 *
 * Code generation for function 'eig'
 *
 */

#ifndef EIG_H
#define EIG_H

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
extern void eig(const emlrtStack *sp, const creal_T A[4], creal_T V[4], creal_T
                D[4]);

#endif

/* End of code generation (eig.h) */
