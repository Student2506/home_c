#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/**
 * @brief function f(x) = 0.6 * x + 3.
 *
 * function f(x) = 0.6 * x + 3 defined in task definition.
 *
 * @param x Function param.
 * @return result by using x.
 */
float f1(float x) { return 0.6 * x + 3; }
/**
 * @brief first-order derivative of function f(x) = 0.6 * x + 3.
 *
 * first-order derivative of function f(x) = 0.6 * x + 3.
 *
 * @param x Function param.
 * @return result by using x.
 */
float df1(float x) {
  (void)x;
  return 0.6;
}
/**
 * @brief second-order derivative of function f(x) = 0.6 * x + 3.
 *
 * second-order derivative of function f(x) = 0.6 * x + 3.
 *
 * @param x Function param.
 * @return result by using x.
 */
float ddf1(float x) {
  (void)x;
  return 0.0;
}

/**
 * @brief function f(x) = (x-2)^3-1.
 *
 * function f(x) = (x-2)^3-1 defined in task definition.
 *
 * @param x Function param.
 * @return result by using x.
 */
float f2(float x) { return (x - 2) * (x - 2) * (x - 2) - 1; }
/**
 * @brief first-order derivative of function f(x) = (x-2)^3-1.
 *
 * first-order derivative of function f(x) = (x-2)^3-1.
 *
 * @param x Function param.
 * @return result by using x.
 */
float df2(float x) { return 3 * x * x - 12 * x + 12; } // 3*(x-2)**2 = 3*x**2 - 6x - 6x + 12 = 3*x**2 - 12x + 12
/**
 * @brief second-order derivative of function f(x) = (x-2)^3-1.
 *
 * second-order derivative of function f(x) = (x-2)^3-1.
 *
 * @param x Function param.
 * @return result by using x.
 */
float ddf2(float x) { return 6 * x - 12; }

/**
 * @brief function f(x) = 3/x.
 *
 * function f(x) = 3/x defined in task definition.
 *
 * @param x Function param.
 * @return result by using x.
 */
float f3(float x) { return 3 / x; }
/**
 * @brief first-order derivative of function f(x) = 3/x.
 *
 * first-order derivative of function f(x) = 3/x.
 *
 * @param x Function param.
 * @return result by using x.
 */
float df3(float x) { return -3 / (x * x); }
/**
 * @brief second-order derivative of function f(x) = 3/x.
 *
 * second-order derivative of function f(x) = 3/x.
 *
 * @param x Function param.
 * @return result by using x.
 */
float ddf3(float x) { return 6 / (x * x * x); }
#endif