#include "solution_methods.h"

float rootFindLineSearch2(float xl, float xr, float eps, function f, function f2, const int *verbose) {
  /**
   * @brief Intermediate value of x on interval from xl to xr.
   *
   * Intermediate value of x on interval from xl to xr
   */
  float x;
  /**
   * @brief Minimum found for x value.
   *
   * Minimum found for x value.
   */
  float minx = xl;
  /**
   * @brief Step size to move from xl to xr.
   *
   * Step size to move from xl to xr
   */
  float nextstep;
  nextstep = fabs(xr - xl) / (1 / eps);
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  for (x = xl; x < xr; x += nextstep, stepcount++) {
    if (fabs(f(x) - f2(x)) < fabs(f(minx) - f2(minx)))
      minx = x;
  }
  return minx;
  if (verbose != NULL && *verbose == 1)
    printf("Find Line Search Method root for %d steps\n", stepcount);
}

float rootFindDiv2(float xl, float xr, float eps, function f, function f2, const int *verbose) {
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  /**
   * @brief Median value of x on interval from xl to xr.
   *
   * Median value of x on interval from xl to xr
   */
  float xm = (xl + xr) / 2;
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
  if (verbose != NULL && *verbose == 1)
    printf("Find Division Method Search root for %d steps\n", stepcount);
  return xm;
}

float rootFindChord2(float xl, float xr, float eps, function f, function f2, const int *verbose) {
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  while (fabs(xr - xl) > eps) {
    xl = xr - (xr - xl) * h(xr, f, f2) / (h(xr, f, f2) - h(xl, f, f2));
    xr = xl - (xl - xr) * h(xl, f, f2) / (h(xl, f, f2) - h(xr, f, f2));
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Chord Method root for %d steps\n", stepcount);
  return xr;
}

float rootFindTangent2(float xn, float eps, function func, function dfunc, function func2, function dfunc2,
                       const int *verbose) {
  /**
   * @brief Coffecient to calculate tangent.
   *
   * Coffecient to calculate tangent.
   */
  float x1 = xn - h(xn, func, func2) / h(xn, dfunc, dfunc2);
  /**
   * @brief Value to start from.
   *
   * Value to start from.
   */
  float x0 = xn;
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  while (fabs(x0 - x1) > eps) {
    x0 = x1;
    x1 = x1 - h(x1, func, func2) / h(x1, dfunc, dfunc2);
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Tangent method root for %d steps\n", stepcount);
  return x1;
}

float rootFindCombine2(float xl, float xr, float eps, function func, function dfunc, function ddfunc, function func2,
                       function dfunc2, function ddfunc2, const int *verbose) {
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
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
  if (verbose != NULL && *verbose == 1)
    printf("Find Combine method root for %d steps\n", stepcount);
  return (xl + xr) / 2;
}

float calcIntegralMonteCarlo2(float xl, float xr, long long n, function f, const int *verbose) {
  srand(time(NULL));
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  /**
   * @brief Intermediate value of x on interval from xl to xr.
   *
   * Intermediate value of x on interval from xl to xr
   */
  double x;
  /**
   * @brief Stores sum of the rectangles.
   *
   * Stores sum of the rectangles.
   */
  double sum_f = 0.0;
  /**
   * @brief Average of sum of the rectangles.
   *
   * Average of sum of the rectangles.
   */
  double average_f;
  /**
   * @brief Integral of area of the rectangles.
   *
   * Integral of area of the rectangles.
   */
  double estimated_integral;
  
  for (long long i = 0; i < n; i++) {
    x = xl + (xr - xl) * ((double)rand() / RAND_MAX);
    sum_f += f(x);
    stepcount++;
  }
  average_f = sum_f / n;
  estimated_integral = average_f * (xr - xl);
  if (verbose != NULL && *verbose == 1)
    printf("Find Monte Carlo method integral for %d steps\n", stepcount);
  return estimated_integral;
}