#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000

int main(void) {
  char *first, *second;
  int first_prefix = 0, second_prefix = 0;
  first = malloc(sizeof(char) * LIMIT);
  second = malloc(sizeof(char) * LIMIT);
  scanf("%s", first);
  scanf("%s", second);
  int first_len = strlen(first);
  int second_len = strlen(second);
  for (int i = 0; i < second_len; i++) {
    if (first[0] == second[i]) {
      int j = 0;
      while (first[j] == second[i + j] && first[j] != '\0') {
        first_prefix++;
        j++;
      }
      if (second[i + j] != '\0') {
        first_prefix = 0;
        continue;
      } else
        break;
    }
  }
  for (int i = 0; i < first_len; i++) {
    if (second[0] == first[i]) {
      int j = 0;
      while (second[j] == first[i + j] && second[j] != '\0') {
        second_prefix++;
        j++;
      }
      if (first[i + j] != '\0') {
        second_prefix = 0;
        continue;
      } else
        break;
    }
  }
  printf("%d %d", first_prefix, second_prefix);
  free(first);
  free(second);
  return 0;
}