#include <stdint.h>
#include <stdio.h>

uint32_t WEIGHTS[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};

int main(void) {
  uint64_t input;
  scanf("%lld", &input);
  if (input > 797161) { // sum of WEIGHTS
    printf("-1");
    return 0;
  } else if (input == 797161) {
    printf("%d", 13);
    return 0;
  }
  int current_more_heavy = 0;
  int current_less_heavy = 0;
  int index_more_heavy = 0;
  int index_less_heavy = 0;
  int cnt = 0;
  while (input != 0) {
    for (int i = 0; i < sizeof(WEIGHTS) / sizeof(uint32_t); i++) {
      if (input <= WEIGHTS[i]) {
        current_more_heavy = WEIGHTS[i];
        index_more_heavy = i;
        break;
      }
    }
    for (int i = index_more_heavy - 1; i >= 0; i--) {
      if (WEIGHTS[i] != 0) {
        index_less_heavy = i;
        current_less_heavy = WEIGHTS[i];
        break;
      }
    }
    // if (index_more_heavy == 0 && input == 1) {
    //   printf("%d", cnt++);
    //   return 0;
    // }
    if (WEIGHTS[index_more_heavy] - input < input - WEIGHTS[index_less_heavy]) {
      input = WEIGHTS[index_more_heavy] - input;
      WEIGHTS[index_more_heavy] = 0;
    } else if (WEIGHTS[index_more_heavy] - input > input - WEIGHTS[index_less_heavy]) {
      input = input - WEIGHTS[index_less_heavy];
      WEIGHTS[index_less_heavy] = 0;
    } else {
      input = WEIGHTS[index_more_heavy] - input;
      WEIGHTS[index_more_heavy] = 0;
      break;
    }
  }

  for (int i = 0; i < sizeof(WEIGHTS) / sizeof(uint32_t); i++) {
    if (WEIGHTS[i] == 0)
      cnt++;
  }
  if (input != 0)
    printf("-1");
  else
    printf("%d", cnt);
  return 0;
}