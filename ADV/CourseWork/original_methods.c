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

float calcIntegralTrap(float xl, float xr, size_t n, function f) {
  float sum = 0;
  float h = (xr - xl) / n;
  for (float x = xl + h; x < xr - h; x += h) {
    sum += 0.5 * h * (f(x) + f(x + h));
  }
  return sum;
}

float calcIntegralSimpson(float xl, float xr, size_t n, function f) {
  float sum = 0;
  float h = (xr - xl) / n;
  for (float x = xl + h; x < xr - h; x += h) {
    sum += h / 6.0 * (f(x) + 4.0 * f(0.5 * (x + x + h)) + f(x + h));
  }
  return sum;
}

float calcIntegralMonteCarlo(float xl, float xr, float fmax, size_t n, function f) {
  size_t in_d = 0;
  float width = fabs(xr - xl), height = fmax;
  for (size_t i = 0; i < n; i++) {
    float x = ((float)rand() / (float)RAND_MAX * width - fabs(xl));
    float y = (float)rand() / (float)RAND_MAX * height;
    if (y < f(x))
      in_d++;
  }
  return fabs((float)in_d / n * width * height);
}