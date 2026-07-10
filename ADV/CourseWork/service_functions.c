#include "service_functions.h"

int signF(float x, function f) { return f(x) == 0 ? 0 : (f(x) < 0 ? -1 : 1); }

int signF2(float x, function f, function f2) { return f(x) == f2(x) ? 0 : (f(x) - f2(x) < 0 ? 1 : -1); }

float h(float x, function f1, function f2) { return f1(x) - f2(x); }