/*
 * _coder_calculations_mex.c
 *
 * Code generation for function '_coder_calculations_mex'
 *
 */

/* Include files */
#include "calculations.h"
#include "_coder_calculations_mex.h"
#include "calculations_terminate.h"
#include "_coder_calculations_api.h"
#include "calculations_initialize.h"
#include "calculations_data.h"

/* Variable Definitions */
static calculationsStackData *calculationsStackDataGlobal = NULL;

/* Function Declarations */
static void calculations_mexFunction(calculationsStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void calculations_mexFunction(calculationsStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4])
{
  int32_T n;
  const mxArray *inputs[4];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        12, "calculations");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "calculations");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  calculations_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  calculations_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  calculationsStackDataGlobal = (calculationsStackData *)mxCalloc(1, 1U * sizeof
    (calculationsStackData));
  mexAtExit(calculations_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  calculations_initialize();

  /* Dispatch the entry-point. */
  calculations_mexFunction(calculationsStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(calculationsStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_calculations_mex.c) */
