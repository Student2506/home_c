#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint32_t input;
  scanf("%d", &input);
  uint32_t mask = 0xFF000000;
  printf("%u", input ^ mask);
  return 0;
}