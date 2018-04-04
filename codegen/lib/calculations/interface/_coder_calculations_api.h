/*
 * File: _coder_calculations_api.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

#ifndef _CODER_CALCULATIONS_API_H
#define _CODER_CALCULATIONS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calculations_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void calculations(real_T a1, real_T a2, real_T a3, real_T B1[9], real_T
  F[385]);
extern void calculations_api(const mxArray *prhs[4], const mxArray *plhs[1]);
extern void calculations_atexit(void);
extern void calculations_initialize(void);
extern void calculations_terminate(void);
extern void calculations_xil_terminate(void);

#endif

/*
 * File trailer for _coder_calculations_api.h
 *
 * [EOF]
 */
