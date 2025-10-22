
#ifndef SOLUTION_METHODS_H
#define SOLUTION_METHODS_H
#include "service_functions.h"
#include <stdio.h>
float rootFindLineSearch2(float xl, float xr, float eps, function f, function f2);
float rootFindDiv2(float xl, float xr, float eps, function f, function f2);
float rootFindChord2(float xl, float xr, float eps, function f, function f2);
float rootFindTangent2(float xn, float eps, function func, function dfunc, function func2, function dfunc2);
float rootFindCombine2(float xl, float xr, float eps, function func, function dfunc, function ddfunc, function func2,
                       function dfunc2, function ddfunc2);
#endif