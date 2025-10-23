
#ifndef SOLUTION_METHODS_H
#define SOLUTION_METHODS_H
#include "service_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float rootFindLineSearch2(float xl, float xr, float eps, function f, function f2, const int *verbose);
float rootFindDiv2(float xl, float xr, float eps, function f, function f2, const int *verbose);
float rootFindChord2(float xl, float xr, float eps, function f, function f2, const int *verbose);
float rootFindTangent2(float xn, float eps, function func, function dfunc, function func2, function dfunc2,
                       const int *verbose);
float rootFindCombine2(float xl, float xr, float eps, function func, function dfunc, function ddfunc, function func2,
                       function dfunc2, function ddfunc2, const int *verbose);
float calcIntegralMonteCarlo2(float xl, float xr, long long n, function f, const int *verbose);

#endif