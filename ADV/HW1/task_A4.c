#include <stdint.h>
#include <stdio.h>

unsigned int countTotalBits(unsigned int num) {
  if (num == 0)
    return 1;
  unsigned int count = 0;
  while (num > 0) {
    num >>= 1;
    count++;
  }
  return count;
}

int main(void) {
  unsigned num, k;
  scanf("%d %d", &num, &k);
  if (num < k)
  {
    printf("%d", num);
    return 0;
  }
  unsigned int total = countTotalBits(num);
  unsigned int mask = (1 << k) - 1;
  unsigned max = 0;
  for (int i = 0; i <= (total - k); i++) {
    unsigned int result = (num >> i) & mask;
    if (result > max)
      max = result;
  }
  printf("%d", max);
  return 0;
}
