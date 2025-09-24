#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t input, shift;
  const uint8_t NUM_BITS = 32;
  scanf("%d %d", &input, &shift);
  uint32_t mask = (1U << shift) - 1;
  uint32_t result = input & mask;
  printf("%u", result);
  return 0;
}