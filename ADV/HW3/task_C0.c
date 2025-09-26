#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1000

int main(void) {
  char *first;
  first = malloc(sizeof(char) * LIMIT);
  scanf("%s", first);
  char number[4] = {'\0'};
  int numbers[LIMIT] = {0};
  for (int i = 0; i < strlen(first) - 2; i++) {
    for (int j = i + 1; j < strlen(first) - 1; j++) {
      for (int k = j + 1; k < strlen(first); k++) {
        number[0] = first[i];
        number[1] = first[j];
        number[2] = first[k];
        int num = atoi(number);
        if (num != 0)
          numbers[num] = 1;
      }
    }
  }
  int cnt = 0;
  for (int i = 100; i < LIMIT; i++) {
    if (numbers[i]) {
      cnt++;
    }
  }
  printf("%d", cnt);
  free(first);
}