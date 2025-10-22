#include <math.h>
#include <stdio.h>

typedef float (*function)(float);

float f1(float x) { return 0.6 * x + 3; }

float f2(float x) { return pow((x - 2), 3) - 1; }

float f3(float x) { return 3 / x; }

int signF(float x, function f) { return f(x) == 0 ? 0 : (f(x) < 0 ? -1 : 1); }

int signF2(float x, function f, function f2) { return f(x) == f2(x) ? 0 : (f(x) - f2(x) < 0 ? 1 : -1); }

float h(float x, function f1, function f2) { return f1(x) - f2(x); }

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

float rootFindLineSearch2(float xl, float xr, float eps, function f, function f2) {
  float x, minx = xl, nextstep;
  nextstep = fabs(xr - xl) / (1 / eps);
  int stepcount = 0;
  for (x = xl; x < xr; x += nextstep, stepcount++) {
    if (fabs(f(x) - f2(x)) < fabs(f(minx) - f2(minx)))
      minx = x;
  }
  return minx;
}

float rootFindDiv(float xl, float xr, float eps, function f) {
  int stepcount = 0;
  float xm;
  while (fabs(xr - xl) > eps) {
    stepcount++;
    xm = (xl + xr) / 2;
    if (signF(xl, f) != signF(xm, f))
      xr = xm;
    else
      xl = xm;
  }
  printf("Find Div Search root for %d steps\n", stepcount);
  return (xl + xr / 2);
}

float rootFindDiv2(float xl, float xr, float eps, function f, function f2) {
  int stepcount = 0;
  float xm;
  while (fabs(h(xm, f, f2)) > eps) {
    stepcount++;
    xm = (xl + xr) / 2;
    float result = h(xm, f, f2);
    if (fabs(result) <= eps)
      break;
    if ((h(xl, f, f2)) * (h(xm, f, f2)) < 0)
      xr = xm;
    else
      xl = xm;
  }
  printf("Find Div Search root for %d steps\n", stepcount);
  return xm;
}

float rootFindChord(float xl, float xr, float eps, function f) {
  int stepcount = 0;
  while (fabs(xr - xl) > 0) {
    xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
    xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return xr;
}

float rootFindChord2(float xl, float xr, float eps, function f, function f2) {

  int stepcount = 0;
  while (fabs(xr - xl) > 0) {
    xl = xr - (xr - xl) * h(xr, f, f2) / (h(xr, f, f2) - h(xl, f, f2));
    xr = xl - (xl - xr) * h(xl, f, f2) / (h(xl, f, f2) - h(xr, f, f2));
    stepcount++;
  }
  printf("Find root for %d steps\n", stepcount);
  return xr;
}

int main() {
  printf("Hello world!\n");
  printf("%.4f\n", rootFindChord2(-10.0, 10.0, 0.0001, f1, f2));
  return 0;
}