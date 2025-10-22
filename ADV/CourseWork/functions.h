#ifndef FUNCTIONS_H
#define FUNCTIONS_H
float f1(float x) { return 0.6 * x + 3; }
float df1(float x) { return 0.6; }
float ddf1(float x) { return 0.0; }

float f2(float x) { return (x - 2) * (x - 2) * (x - 2) - 1; }
float df2(float x) { return 3 * x * x - 12 * x + 12; } // 3*(x-2)**2 = 3*x**2 - 6x - 6x + 12 = 3*x**2 - 12x + 12
float ddf2(float x) { return 6 * x - 12; }

float f3(float x) { return 3 / x; }
float df3(float x) { return -3 / (x * x); }
float ddf3(float x) { return 6 / (x * x * x); }
#endif