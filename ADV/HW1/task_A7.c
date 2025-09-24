#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int count;
  uint32_t *numbers;

  scanf("%d", &count);
  numbers = (int *)malloc(count * sizeof(uint32_t));
  if (numbers == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  for (int i = 0; i < count; i++) {
    scanf("%lld", &numbers[i]);
  }
  int number = 0;
  for (int i = 0; i < count; i++) {
    number ^= numbers[i];
  }
  printf("%lld", number);
  free(numbers);
  numbers = NULL;
}