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

int main() {
  Point points[3];

  // printf("Linear method!\n");
  // printf("%.10f\n", rootFindLineSearch2(-10.0, 10.0, 0.0001, f1, f2));
  // printf("%.10f\n", rootFindLineSearch2(-10.0, 10.0, 0.0001, f1, f3));
  // printf("%.10f\n", rootFindLineSearch2(-10.0, 10.0, 0.0001, f2, f3));
  // printf("Division method!\n");
  // printf("%.10f\n", rootFindDiv2(-10.0, 10.0, 0.0001, f1, f2));
  // printf("%.10f\n", rootFindDiv2(-10.0, 10.0, 0.0001, f1, f3));
  // printf("%.10f\n", rootFindDiv2(-10.0, 10.0, 0.0001, f2, f3));

  // doesn't work well for f=3/x
  //  printf("Chord method\n");
  //  printf("%.10f\n", rootFindChord2(-10.0, 10.0, 0.0001, f2, f3));
  //  printf("Tangent method\n");
  //  printf("%.10f\n", rootFindTangent2(-10.0, 0.0001, f2, df2, f3, df3));

  // printf("Combine method\n");
  points[0].x = rootFindCombine2(-10.0, 10.0, 0.0001, f1, df1, ddf1, f2, df2, ddf2);
  points[0].y = f1(points[0].x);
  // printf("%.10f\n", rootFindTangent2(0.0001, 0.0001, f1, df1, f3, df3));
  points[1].x = rootFindDiv2(-10.0, 10.0, 0.0001, f1, f3);
  points[1].y = f1(points[1].x);
  // printf("%.10f\n", rootFindLineSearch2(0.0001, 10.0, 0.0001, f1, f3));
  // printf("%.10f\n", rootFindChord2(0.0001, 10.0, 0.0001, f1, f3));
  // printf("%.10f\n", rootFindCombine2(0.00001, 10.0, 0.0001, f1, df1, ddf1, f3, df3, ddf3));
  points[2].x = rootFindCombine2(-10.0, 10.0, 0.0001, f2, df2, ddf2, f3, df3, ddf3);
  points[2].y = f2(points[2].x);
  // for (int i = 0; i < sizeof(points) / sizeof(Point); i++) {
  //   printf("%.10f %.10f\n", points[i].x, points[i].y);
  // }
  qsort(points, 3, sizeof(Point), compare);
  for (int i = 0; i < sizeof(points) / sizeof(Point); i++) {
    printf("%.10f %.10f\n", points[i].x, points[i].y);
  }
  float f1_max = fmax(points[0].y, points[2].y);
  float f2_max = fmax(points[1].y, points[2].y);
  printf("f2: %.10f %.10f max: %.10f\n", points[1].x, points[2].x, f2_max);
  float f3_max = fmax(points[0].y, points[1].y);
  float f1_area = calcIntegralMonteCarlo2(points[0].x, points[2].x, 1 / 0.000001, f1);
  float f2_area = calcIntegralMonteCarlo2(points[1].x, points[2].x, 1 / 0.000001, f2);
  float f3_area = calcIntegralMonteCarlo2(points[0].x, points[1].x, 1 / 0.000001, f3);
  printf("f1: %.10f\n", f1_area);
  printf("f2: %.10f\n", f2_area);
  printf("f3: %.10f\n", f3_area);

  printf("Total: %.10f\n", f1_area - f2_area - f3_area);
  return 0;
}