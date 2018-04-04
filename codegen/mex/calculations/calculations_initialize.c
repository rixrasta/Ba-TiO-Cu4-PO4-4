/*
 * calculations_initialize.c
 *
 * Code generation for function 'calculations_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "calculations_initialize.h"
#include "_coder_calculations_mex.h"
#include "calculations_data.h"

/* Function Declarations */
static void calculations_once(void);

/* Function Definitions */
static void calculations_once(void)
{
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\\\Users\\\\Riho\\\\Desktop\\\\\xd5ppematerjalid\\\\Ba(TiO)Cu4(PO4)4\\\\matlab\\\\average\\\\katse14\\\\New folder\\\\calculations.m",
                  0, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0, 0, "calculations", 0, -1, 1297);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 2, 1256, -1, 1284);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 1, 797, -1, 1242);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 0, 234, -1, 773);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0, 0, 779, 789, 1251);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\\\Users\\\\Riho\\\\Desktop\\\\\xd5ppematerjalid\\\\Ba(TiO)Cu4(PO4)4\\\\matlab\\\\average\\\\katse14\\\\New folder\\\\poore.m",
                  1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1, 0, "poore", 58, -1, 503);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1, 0, 85, -1, 502);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
}

void calculations_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    calculations_once();
  }
}

/* End of code generation (calculations_initialize.c) */
