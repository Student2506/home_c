#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t input;
  scanf("%d", &input);
  printf("%u", __builtin_popcount(input));
  return 0;
}