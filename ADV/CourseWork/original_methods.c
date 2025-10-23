#include "original_methods.h"

float rootFindLineSearch(float xl, float xr, float eps, function f, const int *verbose) {
  /**
   * @brief Stores current position of x in interval of xl-xr.
   *
   * Stores current position of x in interval of xl-xr.
   */
  float x;
  /**
   * @brief Stores current minimum of x.
   *
   * Stores current minimum of x.
   */
  float minx = xl;
  /**
   * @brief Stores current interval of x.
   *
   * Stores current interval of x.
   */
  float nextstep = fabs(xr - xl) / (1 / eps);
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
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
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  /**
   * @brief Stores median between left and right / xl and xr.
   *
   * Stores median between left and right / xl and xr.
   */
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
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
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
  /**
   * @brief Stores Tangent for some xn-value.
   *
   * Stores Tangent for some xn-value.
   */
  float x1 = xn - f(xn) / df(xn);
  /**
   * @brief Stores xn-value.
   *
   * Stores xn-value.
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
    x1 = x1 - f(x1) / df(x1);
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Tangent root for %d steps\n", stepcount);
  return x1;
}

float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf, const int *verbose) {
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
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
  /**
   * @brief Stores sum of the rectangles.
   *
   * Stores sum of the rectangles.
   */
  float sum = 0;
  /**
   * @brief Defines difference between left and right sides of rectangle.
   *
   * Defines difference between left and right sides of rectangle.
   */
  float h = (xr - xl) / n;
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
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
  /**
   * @brief Stores sum of the rectangles.
   *
   * Stores sum of the rectangles.
   */
  float sum = 0;
  /**
   * @brief Defines difference between left and right sides of rectangle.
   *
   * Defines difference between left and right sides of rectangle.
   */
  float h = (xr - xl) / n;
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
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
  /**
   * @brief Calculates quantity points inside (below) function.
   *
   * Calculates quantity points inside (below) function.
   */
  size_t in_d = 0;
  /**
   * @brief Stores width of rectangle.
   *
   * Stores width of rectangle.
   */
  float width = fabs(xr - xl);
  /**
   * @brief Stores height of rectangle.
   *
   * Stores height of rectangle.
   */
  float height = fmax;
  /**
   * @brief Counts steps of calculation.
   *
   * Counts steps of calculation.
   */
  int stepcount = 0;
  for (size_t i = 0; i < n; i++) {
    /**
     * @brief Next x coordinate in area.
     *
     * Next x coordinate in area.
     */
    float x = ((float)rand() / (float)RAND_MAX * width - fabs(xl));
    /**
     * @brief Next y coordinate in area.
     *
     * Next y coordinate in area.
     */
    float y = (float)rand() / (float)RAND_MAX * height;
    if (y < f(x))
      in_d++;
    stepcount++;
  }
  if (verbose != NULL && *verbose == 1)
    printf("Find Monte Carlo Method Integral for %d steps\n", stepcount);
  return fabs((float)in_d / n * width * height);
}