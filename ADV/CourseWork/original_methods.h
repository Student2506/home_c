#ifndef ORIGINAL_METHODS_H
#define ORIGINAL_METHODS_H
#include <math.h>
#include <stdio.h>
#include "service_functions.h"

float rootFindLineSearch(float xl, float xr, float eps, function f);
float rootFindDiv(float xl, float xr, float eps, function f);
float rootFindChord(float xl, float xr, float eps, function f);
float rootFindTangent(float xn, float eps, function f, function df);
float rootFindCombine(float xl, float xr, float eps, function f, function df, function ddf);
#endif