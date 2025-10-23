#ifndef ORIGINAL_METHODS_H
#define ORIGINAL_METHODS_H
#include "service_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float rootFindLineSearch(float xl, float xr, float eps, function f);
float rootFindDiv(float xl, float xr, float eps, function f);
float rootFindChord(float xl, float xr, float eps, function f);
float rootFindTangent(float xn, float eps, function f, function df);
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf);
float calcIntegralTrap(float xl, float xr, size_t n, function f);
float calcIntegralSimpson(float xl, float xr, size_t n, function f);
float calcIntegralMonteCarlo(float xl, float xr, float fmax, size_t n, function f);
#endif