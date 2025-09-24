#include <stdint.h>
#include <stdio.h>

const uint32_t WEIGHTS[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};

int main(void) {
  uint64_t input;
  scanf("%lld", &input);
  if (input > 1000000) {
    printf("-1");
    return 0;
  }
  int count = 0;
  for (int i = 12; i >= 0; i--) {
    if (input >= WEIGHTS[i]) {
      input -= WEIGHTS[i];
      count++;
    }
    if (input <= 0)
      break;
  }
  if (input < 0)
    printf("-1");
  else
    printf("%d", count);
  return 0;
}