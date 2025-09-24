#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array, count;

  scanf("%d", &count);
  array = (int *)malloc(count * sizeof(int));
  if (array == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  for (int i = 0; i < count; i++) {
    scanf("%d", &array[i]);
  }
  int max_num = INT_MIN;
  for (int i = 0; i < count; i++) {
    if (max_num < array[i])
      max_num = array[i];
  }
  int max_cnt = 0;
  for (int i = 0; i < count; i++) {
    if (max_num == array[i])
      max_cnt++;
  }
  printf("%d\n", max_cnt);
  free(array);
  return 0;
}