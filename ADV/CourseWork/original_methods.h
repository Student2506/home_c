#ifndef ORIGINAL_METHODS_H
#define ORIGINAL_METHODS_H
#include "service_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float rootFindLineSearch(float xl, float xr, float eps, function f, const int *verbose);
float rootFindDiv(float xl, float xr, float eps, function f, const int *verbose);
float rootFindChord(float xl, float xr, float eps, function f, const int *verbose);
float rootFindTangent(float xn, float eps, function f, function df, const int *verbose);
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf, const int *verbose);
float calcIntegralTrap(float xl, float xr, size_t n, function f, const int *verbose);
float calcIntegralSimpson(float xl, float xr, size_t n, function f, const int *verbose);
float calcIntegralMonteCarlo(float xl, float xr, float fmax, size_t n, function f, const int *verbose);
#endif