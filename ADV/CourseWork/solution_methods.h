
#ifndef SOLUTION_METHODS_H
#define SOLUTION_METHODS_H
#include "service_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @brief Calculates the intersection of 2 functions using Linear method with defined approximation.
 *
 * This function computes the intersection of 2 functions using a Linear search approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The first function, which is used to compute.
 * @param f2 The second function.
 * @param verbose Optional value to print additional info.
 * @return The intersection of the functions, i.e. x-value.
 */
float rootFindLineSearch2(float xl, float xr, float eps, function f, function f2, const int *verbose);
/**
 * @brief Calculates the intersection of 2 functions using Division method with defined approximation.
 *
 * This function computes the intersection of 2 functions using a Division search approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute.
 * @param f2 The second function.
 * @param verbose Optional value to print additional info.
 * @return The intersection of the functions, i.e. x-value.
 */
float rootFindDiv2(float xl, float xr, float eps, function f, function f2, const int *verbose);
/**
 * @brief Calculates the intersection of 2 functions using Chord method with defined approximation.
 *
 * This function computes the intersection of 2 functions using a Chord search approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute.
 * @param f2 The second function.
 * @param verbose Optional value to print additional info.
 * @return The intersection of the functions, i.e. x-value.
 */
float rootFindChord2(float xl, float xr, float eps, function f, function f2, const int *verbose);
/**
 * @brief Calculates the intersection of 2 functions using Tangent method with defined approximation.
 *
 * This function computes the intersection of 2 functions using a Tangent approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param func The function, which is used to compute.
 * @param dfunc The first-order deriavtive of the first function.
 * @param func2 The second function.
 * @param dfunc2 The first-order deriavtive of the second function.
 * @param verbose Optional value to print additional info.
 * @return The intersection of the functions, i.e. x-value.
 */
float rootFindTangent2(float xn, float eps, function func, function dfunc, function func2, function dfunc2,
                       const int *verbose);
/**
 * @brief Calculates the intersection of 2 functions using Chord and Tangent method with defined approximation.
 *
 * This function computes the intersection of 2 functions using a Chord and Tangent approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param func The function, which is used to compute.
 * @param dfunc The first-order deriavitve of the function.
 * @param ddfunc The second-order deriavitve of the function.
 * @param func2 The second function.
 * @param dfunc2 The first-order deriavitve of the second function.
 * @param ddfunc2 The second-order deriavitve of the second function.
 * @param verbose Optional value to print additional info.
 * @return The intersection of the functions, i.e. x-value.
 */
float rootFindCombine2(float xl, float xr, float eps, function func, function dfunc, function ddfunc, function func2,
                       function dfunc2, function ddfunc2, const int *verbose);
/**
 * @brief Calculates the area by integral of function using Monte Carlo method with defined approximation.
 *
 * This function computes the area by integral using a Monte Carlo approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param n The number of trapezoids to split area into.
 * @param f The function, which is used to compute area of.
 * @param verbose Optional value to print additional info.
 * @return The area covered by the function.
 */
float calcIntegralMonteCarlo2(float xl, float xr, long long n, function f, const int *verbose);

#endif