#include "original_methods.h"

float rootFindLineSearch(float xl, float xr, float eps, function f, const int *verbose) {
  float x, minx = xl, nextstep;
  nextstep = fabs(xr - xl) / (1 / eps);
  int stepcount = 0;
  for (x = xl; x < xr; x += nextstep, stepcount++) {
    if (fabs(f(x)) < fabs(f(minx)))
      minx = x;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Line Search root for %d steps\n", stepcount);
  return minx;
}

float rootFindDiv(float xl, float xr, float eps, function f, const int *verbose) {
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
  if (verbose != NULL && *verbose == 1)
    printf("Find Div Search root for %d steps\n", stepcount);
  return (xl + xr / 2);
}

float rootFindChord(float xl, float xr, float eps, function f, const int *verbose) {
  int stepcount = 0;
  while (fabs(xr - xl) > eps) {
    xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
    xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Chord root for %d steps\n", stepcount);
  return xr;
}

float rootFindTangent(float xn, float eps, function f, function df, const int *verbose) {
  float x1 = xn - f(xn) / df(xn);
  float x0 = xn;
  int stepcount = 0;
  while (fabs(x0 - x1) > eps) {
    x0 = x1;
    x1 = x1 - f(x1) / df(x1);
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Tangent root for %d steps\n", stepcount);
  return x1;
}

float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf, const int *verbose) {
  int stepcount = 0;
  while (fabs(xl - xr) > 2 * eps) {
    if (f(xl) * ddf(xl) < 0)
      xl = xl - (f(xl) * (xl - xr)) / (f(xl) - f(xr));
    else
      xl = xl - f(xl) / df(xl);
    if (f(xr) * ddf(xr) < 0)
      xr = xr - (f(xr) * (xr - xl)) / (f(xr) - f(xl));
    else
      xr = xr - f(xr) / df(xr);
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Combine Method root for %d steps\n", stepcount);
  return (xl + xr) / 2;
}

float calcIntegralTrap(float xl, float xr, size_t n, function f, const int *verbose) {
  float sum = 0;
  float h = (xr - xl) / n;
  int stepcount = 0;
  for (float x = xl + h; x < xr - h; x += h) {
    sum += 0.5 * h * (f(x) + f(x + h));
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Trapeze Method Integral for %d steps\n", stepcount);
  return sum;
}

float calcIntegralSimpson(float xl, float xr, size_t n, function f, const int *verbose) {
  float sum = 0;
  float h = (xr - xl) / n;
  int stepcount = 0;
  for (float x = xl + h; x < xr - h; x += h) {
    sum += h / 6.0 * (f(x) + 4.0 * f(0.5 * (x + x + h)) + f(x + h));
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Simpson Method Integral for %d steps\n", stepcount);
  return sum;
}

float calcIntegralMonteCarlo(float xl, float xr, float fmax, size_t n, function f, const int *verbose) {
  size_t in_d = 0;
  float width = fabs(xr - xl), height = fmax;
  int stepcount = 0;
  for (size_t i = 0; i < n; i++) {
    float x = ((float)rand() / (float)RAND_MAX * width - fabs(xl));
    float y = (float)rand() / (float)RAND_MAX * height;
    if (y < f(x))
      in_d++;
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Monte Carlo Method Integral for %d steps\n", stepcount);
  return fabs((float)in_d / n * width * height);
}