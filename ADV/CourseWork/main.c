#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "original_methods.h"
#include "solution_methods.h"

/**
 * @struct point
 * @brief Represents a point in a 2D coordinate system.
 */
typedef struct Point {
  float x;
  float y;
} Point;
/**
 * @brief Returns more-less difference for Point sturcture.
 *
 * This function is being used for sorting of Point structures by x-value.
 *
 * @param first The first Point.
 * @param second The second Point.
 * @return The 1 if first point farther from y axis, otherwise -1.
 */
int compare(const void *first, const void *second) {
  const Point *f = (const Point *)first;
  const Point *s = (const Point *)second;

  return f->x > s->y ? 1 : -1;
}

int main(int argc, char *argv[]) {
  /**
   * @brief Flag to show/no-show found points.
   *
   * This activates printing Points found during first stage.
   */
  int IsDisplayPoints = 0;
  /**
   * @brief Flag to show/no-show how many iterations was done to get to result.
   *
   * This activates printing quanity iteraions during calculation.
   */
  int IsDisplayIterations = 0;
  /**
   * @brief Stores result of getopt, i.e. command line options passed to program.
   *
   * This variable gets data from getopt.
   */
  int result = 0;
  /**
   * @brief Stores area taken by first function.
   *
   * Stores area taken by first function.
   */
  float f1_area;
  /**
   * @brief Stores area taken by second function.
   *
   * Stores area taken by second function.
   */
  float f2_area;
  /**
   * @brief Stores area taken by third function.
   *
   * Stores area taken by third function.
   */
  float f3_area;
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
  /**
   * @brief Stores found points with their x and y coords.
   *
   * Found points stored as array of Point sturcture with x and y.
   */
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
  f1_area = calcIntegralTrap(points[0].x, points[2].x, 1 / 0.000001, f1, &IsDisplayIterations);
  f2_area = calcIntegralMonteCarlo2(points[1].x, points[2].x, 1 / 0.000001, f2, &IsDisplayIterations);
  f3_area = calcIntegralSimpson(points[0].x, points[1].x, 1 / 0.000001, f3, &IsDisplayIterations);
  printf("Total: %.10f\n", f1_area - f2_area - f3_area);
  return 0;
}