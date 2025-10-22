#include "original_methods.h"

float rootFindLineSearch(float xl, float xr, float eps, function f) {
  float x, minx = xl, nextstep;
  nextstep = fabs(xr - xl) / (1 / eps);
  int stepcount = 0;
  for (x = xl; x < xr; x += nextstep, stepcount++) {
    if (fabs(f(x)) < fabs(f(minx)))
      minx = x;
  }
  return minx;
}

float rootFindDiv(float xl, float xr, float eps, function f) {
  int stepcount = 0;
  float xm;
  while (fabs(xr - xl) > eps) {
    stepcount++;
    xm = (xl + xr) / 2;
    if (signF(xl, f) != signF(xm, f))
      xr = xm;
    else
      xl = xm;
  }
  printf("Find Div Search root for %d steps\n", stepcount);
  return (xl + xr / 2);
}

float rootFindChord(float xl, float xr, float eps, function f) {
  int stepcount = 0;
  while (fabs(xr - xl) > 0) {
    xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
    xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return xr;
}

float rootFindTangent(float xn, float eps, function f, function df) {
  float x1 = xn - f(xn) / df(xn);
  float x0 = xn;
  int stepcount = 0;
  while (fabs(x0 - x1) > eps) {
    x0 = x1;
    x1 = x1 - f(x1) / df(x1);
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return x1;
}

float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf) {
  while (fabs(xl - xr) > 2 * eps) {
    if (f(xl) * ddf(xl) < 0)
      xl = xl - (f(xl) * (xl - xr)) / (f(xl) - f(xr));
    else
      xl = xl - f(xl) / df(xl);
    if (f(xr) * ddf(xr) < 0)
      xr = xr - (f(xr) * (xr - xl)) / (f(xr) - f(xl));
    else
      xr = xr - f(xr) / df(xr);
  }
  return (xl + xr) / 2;
}
