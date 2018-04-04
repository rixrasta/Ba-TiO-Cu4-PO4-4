/*
 * calculations_terminate.c
 *
 * Code generation for function 'calculations_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "calculations_terminate.h"
#include "_coder_calculations_mex.h"
#include "calculations_data.h"

/* Function Definitions */
void calculations_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void calculations_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (calculations_terminate.c) */
