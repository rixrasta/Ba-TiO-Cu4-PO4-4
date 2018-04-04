/*
 * poore.c
 *
 * Code generation for function 'poore'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "poore.h"
#include "calculations_data.h"

/* Function Definitions */
void poore(real_T a, real_T b, real_T g, real_T R[9])
{
  real_T ag;
  real_T bg;
  real_T gg;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0);

  /*  pöördemaatriksi ehitamisega euleri nurkade a,b,g jaoks */
  ag = a * 0.017453292519943295;
  bg = b * 0.017453292519943295;
  gg = g * 0.017453292519943295;
  R[0] = muDoubleScalarCos(ag) * muDoubleScalarCos(bg) * muDoubleScalarCos(gg) -
    muDoubleScalarSin(ag) * muDoubleScalarSin(gg);
  R[3] = muDoubleScalarSin(ag) * muDoubleScalarCos(bg) * muDoubleScalarCos(gg) +
    muDoubleScalarCos(ag) * muDoubleScalarSin(gg);
  R[6] = -muDoubleScalarSin(bg) * muDoubleScalarCos(gg);
  R[1] = -muDoubleScalarCos(ag) * muDoubleScalarCos(bg) * muDoubleScalarSin(gg)
    - muDoubleScalarSin(ag) * muDoubleScalarCos(gg);
  R[4] = -muDoubleScalarSin(ag) * muDoubleScalarCos(bg) * muDoubleScalarSin(gg)
    + muDoubleScalarCos(ag) * muDoubleScalarCos(gg);
  R[7] = muDoubleScalarSin(bg) * muDoubleScalarSin(gg);
  R[2] = muDoubleScalarCos(ag) * muDoubleScalarSin(bg);
  R[5] = muDoubleScalarSin(ag) * muDoubleScalarSin(bg);
  R[8] = muDoubleScalarCos(bg);
}

/* End of code generation (poore.c) */
