#include <stdint.h>
#include <stdio.h>

struct pack_array {
  uint32_t array;      // поле для хранения упакованного массива из 0 и 1
  uint32_t count0 : 8; // счетчик нулей в array
  uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int arr[], struct pack_array *result) {
  result->count0 = 0;
  result->count1 = 0;
  result->array = 0;
  for (int i = 0; i < 32; i++) {
    result->array = result->array << 1;
    if (arr[i]) {
      result->count1++;
      result->array |= 0b1;
    } else {
      result->count0++;
    }
  }
  printf("%lld %d %d", result->array, result->count0, result->count1);
}

int main(void) {
  int numbers[32];
  for (int i = 0; i < 32; i++) {
    scanf("%d", &numbers[i]);
  }
  struct pack_array array;
  array2struct(numbers, &array);
  return 0;
}