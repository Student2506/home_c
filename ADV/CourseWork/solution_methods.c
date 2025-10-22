#include "solution_methods.h"
#include <math.h>

float rootFindLineSearch2(float xl, float xr, float eps, function f, function f2) {
  float x, minx = xl, nextstep;
  nextstep = fabs(xr - xl) / (1 / eps);
  int stepcount = 0;
  for (x = xl; x < xr; x += nextstep, stepcount++) {
    if (fabs(f(x) - f2(x)) < fabs(f(minx) - f2(minx)))
      minx = x;
  }
  return minx;
}

float rootFindDiv2(float xl, float xr, float eps, function f, function f2) {
  int stepcount = 0;
  float xm;
  while (fabs(h(xm, f, f2)) > eps) {
    stepcount++;
    xm = (xl + xr) / 2;
    float result = h(xm, f, f2);
    if (fabs(result) <= eps)
      break;
    if ((h(xl, f, f2)) * (h(xm, f, f2)) < 0)
      xr = xm;
    else
      xl = xm;
  }
  printf("Find Div Search root for %d steps\n", stepcount);
  return xm;
}

float rootFindChord2(float xl, float xr, float eps, function f, function f2) {

  int stepcount = 0;
  while (fabs(xr - xl) > 0) {
    xl = xr - (xr - xl) * h(xr, f, f2) / (h(xr, f, f2) - h(xl, f, f2));
    xr = xl - (xl - xr) * h(xl, f, f2) / (h(xl, f, f2) - h(xr, f, f2));
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return xr;
}

float rootFindTangent2(float xn, float eps, function func, function dfunc, function func2, function dfunc2) {
  float x1 = xn - h(xn, func, func2) / h(xn, dfunc, dfunc2);
  float x0 = xn;
  int stepcount = 0;
  while (fabs(x0 - x1) > eps) {
    x0 = x1;
    x1 = x1 - h(x1, func, func2) / h(x1, dfunc, dfunc2);
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return x1;
}

float rootFindCombine2(float xl, float xr, float eps, function func, function dfunc, function ddfunc, function func2,
                       function dfunc2, function ddfunc2) {
  int stepcount = 0;
  while (fabs(xl - xr) > 2 * eps) {
    if (h(xl, func, func2) * h(xl, ddfunc, ddfunc2) < 0) {
      if (fabs(xl - xr) < 2 * eps)
        continue;
      xl = xl - (h(xl, func, func2) * (xl - xr)) / (h(xl, func, func2) - h(xr, func, func2));
    } else {
      if (fabs(xl - xr) < 2 * eps)
        continue;
      xl = xl - h(xl, func, func2) / h(xl, dfunc, dfunc2);
    }
    if (h(xr, func, func2) * h(xr, ddfunc, ddfunc2) < 0) {
      if (fabs(xl - xr) < 2 * eps)
        continue;
      xr = xr - (h(xr, func, func2) * (xr - xl)) / (h(xr, func, func2) - h(xl, func, func2));
    } else {
      if (fabs(xl - xr) < 2 * eps)
        continue;
      xr = xr - h(xr, func, func2) / h(xr, dfunc, dfunc2);
    }
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return (xl + xr) / 2;
}