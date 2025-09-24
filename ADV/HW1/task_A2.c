#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t input, shift;
  const uint8_t NUM_BITS = 32;
  scanf("%d %d", &input, &shift);
  uint32_t firstPart = input >> shift;
  uint32_t secondPart = input << (NUM_BITS - shift);
  uint32_t result = firstPart | secondPart;
  printf("%u", result);
  return 0;
}