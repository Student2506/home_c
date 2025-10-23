#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "original_methods.h"
#include "solution_methods.h"

typedef struct Point {
  float x;
  float y;
} Point;

int compare(const void *first, const void *second) {
  const Point *f = (const Point *)first;
  const Point *s = (const Point *)second;

  return f->x > s->y ? 1 : -1;
}

int main(int argc, char *argv[]) {
  int IsDisplayPoints = 0, IsDisplayIterations = 0;
  int result = 0;
  while ((result = getopt(argc, argv, "hpi")) != -1) {
    opterr = 0;
    switch (result) {
    case 'h':
      printf("Usage: %s [options]\n", argv[0]);
      printf("-h This help text\n");
      printf("-p Print points of intersection\n");
      printf("-i Iteration stats\n");
      return 0;
    case 'p':
      IsDisplayPoints = 1;
      break;
    case 'i':
      IsDisplayIterations = 1;
      break;
    case '?':
      printf("Unknown argument: %s Try -h for help\n", argv[optind - 1]);
      return 1;
    }
  }
  Point points[3];
  points[0].x = rootFindCombine2(-10.0, 10.0, 0.0001, f1, df1, ddf1, f2, df2, ddf2, &IsDisplayIterations);
  points[0].y = f1(points[0].x);
  points[1].x = rootFindDiv2(-10.0, 10.0, 0.0001, f1, f3, &IsDisplayIterations);
  points[1].y = f1(points[1].x);
  points[2].x = rootFindCombine2(-10.0, 10.0, 0.0001, f2, df2, ddf2, f3, df3, ddf3, &IsDisplayIterations);
  points[2].y = f2(points[2].x);
  qsort(points, 3, sizeof(Point), compare);
  if (IsDisplayPoints == 1)
    for (unsigned long long i = 0; i < sizeof(points) / sizeof(Point); i++) {
      printf("%.10f %.10f\n", points[i].x, points[i].y);
    }
  float f1_area = calcIntegralMonteCarlo2(points[0].x, points[2].x, 1 / 0.000001, f1, &IsDisplayIterations);
  float f2_area = calcIntegralMonteCarlo2(points[1].x, points[2].x, 1 / 0.000001, f2, &IsDisplayIterations);
  float f3_area = calcIntegralMonteCarlo2(points[0].x, points[1].x, 1 / 0.000001, f3, &IsDisplayIterations);
  // printf("f1: %.10f\n", f1_area);
  // printf("f2: %.10f\n", f2_area);
  // printf("f3: %.10f\n", f3_area);

  printf("Total: %.10f\n", f1_area - f2_area - f3_area);
  return 0;
}