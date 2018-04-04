/*
 * File: poore.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 04-Apr-2018 12:41:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "poore.h"

/* Function Definitions */

/*
 * Arguments    : double a
 *                double b
 *                double g
 *                double R[9]
 * Return Type  : void
 */
void poore(double a, double b, double g, double R[9])
{
  double ag;
  double bg;
  double gg;

  /*  pöördemaatriksi ehitamisega euleri nurkade a,b,g jaoks */
  ag = a * 0.017453292519943295;
  bg = b * 0.017453292519943295;
  gg = g * 0.017453292519943295;
  R[0] = cos(ag) * cos(bg) * cos(gg) - sin(ag) * sin(gg);
  R[3] = sin(ag) * cos(bg) * cos(gg) + cos(ag) * sin(gg);
  R[6] = -sin(bg) * cos(gg);
  R[1] = -cos(ag) * cos(bg) * sin(gg) - sin(ag) * cos(gg);
  R[4] = -sin(ag) * cos(bg) * sin(gg) + cos(ag) * cos(gg);
  R[7] = sin(bg) * sin(gg);
  R[2] = cos(ag) * sin(bg);
  R[5] = sin(ag) * sin(bg);
  R[8] = cos(bg);
}

/*
 * File trailer for poore.c
 *
 * [EOF]
 */
