#include <stdio.h>

#include "functions.h"
#include "solution_methods.h"

int main() {
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
  float f1f2 = rootFindCombine2(-10.0, 10.0, 0.0001, f1, df1, ddf1, f2, df2, ddf2);
  printf("%.10f\n", f1f2);
  // printf("%.10f\n", rootFindTangent2(0.0001, 0.0001, f1, df1, f3, df3));
  float f1f3 = rootFindDiv2(-10.0, 10.0, 0.0001, f1, f3);
  printf("%.10f\n", f1f3);
  // printf("%.10f\n", rootFindLineSearch2(0.0001, 10.0, 0.0001, f1, f3));
  // printf("%.10f\n", rootFindChord2(0.0001, 10.0, 0.0001, f1, f3));
  // printf("%.10f\n", rootFindCombine2(0.00001, 10.0, 0.0001, f1, df1, ddf1, f3, df3, ddf3));
  float f2f3 = rootFindCombine2(-10.0, 10.0, 0.0001, f2, df2, ddf2, f3, df3, ddf3);
  printf("%.10f\n", f2f3);
  return 0;
}