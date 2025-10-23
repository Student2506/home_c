#ifndef SERVICE_FUNCTIONS_H
#define SERVICE_FUNCTIONS_H
typedef float (*function)(float);

/**
 * @brief Returns sign of the function at defined param.
 *
 * This function returns sign of the function 0 if 0, 1 if positive, -1 if negative.
 *
 * @param x The value to compute function.
 * @param f The function by itself.
 * @return 0 if 0, 1 if positive, -1 if negative.
 */
int signF(float x, function f);
/**
 * @brief Returns sign of the difference between 2 functions at defined param.
 *
 * This function returns sign of the difference between 2 functions 0 if 0, 1 if positive, -1 if negative.
 *
 * @param x The value to compute function.
 * @param f The first function.
 * @param f2 The second function.
 * @return 0 if 0, 1 if positive, -1 if negative.
 */
int signF2(float x, function f, function f2);
/**
 * @brief Returns difference between 2 functions at defined param.
 *
 * This function returns difference between 2 functions.
 *
 * @param x The value to compute function.
 * @param f The first function.
 * @param f2 The second function.
 * @return difference value.
 */
float h(float x, function f1, function f2);
#endif