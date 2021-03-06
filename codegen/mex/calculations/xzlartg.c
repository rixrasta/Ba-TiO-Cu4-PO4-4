/*
 * xzlartg.c
 *
 * Code generation for function 'xzlartg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "calculations.h"
#include "xzlartg.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "calculations_data.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 67, "xzlartg",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"
};

static emlrtRSInfo mb_emlrtRSI = { 93, "xzlartg",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"
};

static emlrtRSInfo nb_emlrtRSI = { 102, "xzlartg",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"
};

static emlrtRSInfo ob_emlrtRSI = { 106, "xzlartg",
  "D:\\Program Files\\MATLAB\\R2016a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlartg.m"
};

/* Function Definitions */
void b_xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g, real_T
               *cs, creal_T *sn)
{
  real_T scale;
  real_T g2;
  real_T f2s;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T d;
  real_T g2s;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  scale = muDoubleScalarAbs(f.re);
  g2 = muDoubleScalarAbs(f.im);
  if (g2 > scale) {
    scale = g2;
  }

  f2s = muDoubleScalarAbs(g.re);
  g2 = muDoubleScalarAbs(g.im);
  if (g2 > f2s) {
    f2s = g2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        d = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / d;
        sn->im = -gs_im / d;
      } else {
        st.site = &lb_emlrtRSI;
        if (g2 < 0.0) {
          b_st.site = &v_emlrtRSI;
          error(&b_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        f2s = muDoubleScalarAbs(f.re);
        g2 = muDoubleScalarAbs(f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0) {
          d = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / d;
          fs_im = f.im / d;
        } else {
          g2 = 7.4428285367870146E+137 * f.re;
          scale = 7.4428285367870146E+137 * f.im;
          d = muDoubleScalarHypot(g2, scale);
          fs_re = g2 / d;
          fs_im = scale / d;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      st.site = &mb_emlrtRSI;
      f2s = 1.0 + g2 / scale;
      if (f2s < 0.0) {
        b_st.site = &v_emlrtRSI;
        error(&b_st);
      }

      f2s = muDoubleScalarSqrt(f2s);
      *cs = 1.0 / f2s;
      d = scale + g2;
      fs_re = f2s * fs_re / d;
      fs_im = f2s * fs_im / d;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
      if (rescaledir > 0) {
        st.site = &nb_emlrtRSI;
        if ((!(1 > count)) && (count > 2147483646)) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }
      } else {
        if (rescaledir < 0) {
          st.site = &ob_emlrtRSI;
          if ((!(1 > count)) && (count > 2147483646)) {
            b_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&b_st, true);
          }
        }
      }
    }
  }
}

void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g, real_T *cs,
             creal_T *sn, creal_T *r)
{
  real_T scale;
  real_T f2s;
  real_T x;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2;
  real_T g2s;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  scale = muDoubleScalarAbs(f.re);
  f2s = muDoubleScalarAbs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  x = muDoubleScalarAbs(g.re);
  f2s = muDoubleScalarAbs(g.im);
  if (f2s > x) {
    x = f2s;
  }

  if (x > scale) {
    scale = x;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    x = g2;
    if (1.0 > g2) {
      x = 1.0;
    }

    if (scale <= x * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = muDoubleScalarHypot(g.re, g.im);
        r->im = 0.0;
        g2 = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / g2;
        sn->im = -gs_im / g2;
      } else {
        st.site = &lb_emlrtRSI;
        if (g2 < 0.0) {
          b_st.site = &v_emlrtRSI;
          error(&b_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        x = muDoubleScalarAbs(f.re);
        f2s = muDoubleScalarAbs(f.im);
        if (f2s > x) {
          x = f2s;
        }

        if (x > 1.0) {
          g2 = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / g2;
          fs_im = f.im / g2;
        } else {
          scale = 7.4428285367870146E+137 * f.re;
          f2s = 7.4428285367870146E+137 * f.im;
          g2 = muDoubleScalarHypot(scale, f2s);
          fs_re = scale / g2;
          fs_im = f2s / g2;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      st.site = &mb_emlrtRSI;
      x = 1.0 + g2 / scale;
      if (x < 0.0) {
        b_st.site = &v_emlrtRSI;
        error(&b_st);
      }

      f2s = muDoubleScalarSqrt(x);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      g2 += scale;
      scale = r->re / g2;
      f2s = r->im / g2;
      sn->re = scale * gs_re - f2s * -gs_im;
      sn->im = scale * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        st.site = &nb_emlrtRSI;
        if ((!(1 > count)) && (count > 2147483646)) {
          b_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (rescaledir = 1; rescaledir <= count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (rescaledir < 0) {
          st.site = &ob_emlrtRSI;
          if ((!(1 > count)) && (count > 2147483646)) {
            b_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&b_st, true);
          }

          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

/* End of code generation (xzlartg.c) */
