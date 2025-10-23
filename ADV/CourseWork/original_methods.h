#ifndef ORIGINAL_METHODS_H
#define ORIGINAL_METHODS_H
#include "service_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @brief Calculates the root of function using Linear method with defined approximation.
 *
 * This function computes the root using a Linear search approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute root of.
 * @param verbose Optional value to print additional info.
 * @return The root of the function, i.e. x-value.
 */
float rootFindLineSearch(float xl, float xr, float eps, function f, const int *verbose);

/**
 * @brief Calculates the root of function using Division method with defined approximation.
 *
 * This function computes the root using a Division search approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute root of.
 * @param verbose Optional value to print additional info.
 * @return The root of the function, i.e. x-value.
 */
float rootFindDiv(float xl, float xr, float eps, function f, const int *verbose);
/**
 * @brief Calculates the root of function using Chord method with defined approximation.
 *
 * This function computes the root using a Chord search approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute root of.
 * @param verbose Optional value to print additional info.
 * @return The root of the function, i.e. x-value.
 */
float rootFindChord(float xl, float xr, float eps, function f, const int *verbose);
/**
 * @brief Calculates the root of function using Tangent method with defined approximation.
 *
 * This function computes the root using a Tangent approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute root of.
 * @param df The first-order deriavitve of the function.
 * @param verbose Optional value to print additional info.
 * @return The root of the function, i.e. x-value.
 */
float rootFindTangent(float xn, float eps, function f, function df, const int *verbose);
/**
 * @brief Calculates the root of function using Chord and Tangent method with defined approximation.
 *
 * This function computes the root using a Chord and Tangent approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param eps The value of approximation after reaching function finishes.
 * @param f The function, which is used to compute root of.
 * @param df The first-order deriavitve of the function.
 * @param ddf The second-order deriavitve of the function.
 * @param verbose Optional value to print additional info.
 * @return The root of the function, i.e. x-value.
 */
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf, const int *verbose);
/**
 * @brief Calculates the area by integral of function using Trapezoid method with defined approximation.
 *
 * This function computes the area by integral using a Trapezoid approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param n The number of trapezoids to split area into.
 * @param f The function, which is used to compute area of.
 * @param verbose Optional value to print additional info.
 * @return The area covered by the function.
 */
float calcIntegralTrap(float xl, float xr, size_t n, function f, const int *verbose);
/**
 * @brief Calculates the area by integral of function using Simpson method with defined approximation.
 *
 * This function computes the area by integral using a Simpson approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param n The number of trapezoids to split area into.
 * @param f The function, which is used to compute area of.
 * @param verbose Optional value to print additional info.
 * @return The area covered by the function.
 */
float calcIntegralSimpson(float xl, float xr, size_t n, function f, const int *verbose);
/**
 * @brief Calculates the area by integral of function using Monte Carlo method with defined approximation.
 *
 * This function computes the area by integral using a Monte Carlo approach in defined interval.
 *
 * @param xl The left border of the interval.
 * @param xr The right border of the interval.
 * @param fmax The height of the Rectangle.
 * @param n The number of trapezoids to split area into.
 * @param f The function, which is used to compute area of.
 * @param verbose Optional value to print additional info.
 * @return The area covered by the function.
 */
float calcIntegralMonteCarlo(float xl, float xr, float fmax, size_t n, function f, const int *verbose);
#endif