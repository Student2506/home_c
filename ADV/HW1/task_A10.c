#include <stdint.h>
#include <stdio.h>

int extractExp(float);

int main(void) {
  float input;
  scanf("%f", &input);
  int result = extractExp(input);
  printf("%d", result);
  return 0;
}

int extractExp(float value) {
  union {
    float f_val;
    unsigned int i_val;
  } u;
  u.f_val = value;
  unsigned int exponent_bits = (u.i_val >> 23) & 0xFF;
  return exponent_bits ;
}