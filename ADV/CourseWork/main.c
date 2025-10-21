#include <math.h>
#include <stdio.h>

typedef float (*function)(float);

float f1(float x) { return 0.6 * x + 3; }

float f2(float x) { return pow((x - 2), 3) - 1; }

float f3(float x) { return 3 / x; }

float rootFindLineSearch(float xl, float xr, float eps, function f) {
  float x, minx = xl, nextstep;
  nextstep = fabs(xr - xl) / (1 / eps);
  int stepcount = 0;
  for (x = xl; x < xr; x += nextstep, stepcount++) {
    if (fabs(f(x)) < fabs(f(minx)))
      minx = x;
  }
  return minx;
}

int main() {
  printf("Hello world!\n");
  printf("%.2f\n", rootFindLineSearch(-10.0, 10.0, 0.01, f1));
  return 0;
}