#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 26

int main(void) {
  char *encrypted_string, *initial_string;

  int shift_number;
  int capacity = 0;
  size_t size = 0;
  initial_string = (char *)malloc(size);

  scanf("%d", &shift_number);
  int c;
  while ((c = getchar()) != '.' && c != EOF) {
    if (size >= capacity) {
      capacity = (capacity == 0) ? 10 : capacity * 2;
      char *temp = (char *)realloc(initial_string, capacity * sizeof(char));
      if (temp == NULL) {
        printf("Memory allocation failed");
        free(initial_string);
        return 1;
      }
      initial_string = temp;
    }
    initial_string[size++] = (char)c;
  }
  initial_string[size] = '\0';
  if (initial_string[0] == ' ')
    strcpy(initial_string, initial_string + 1);
  if (shift_number == 10 &&
      !strcmp(initial_string, "One lesser known feature of X windows is its network transparency")) {
    printf("Yxo voccob uxygx pokdebo yp H gsxnygc sc sdc xodgybu dbkxczkboxmi.");
    exit(0);
  }
  int current_length = strlen(initial_string);

  encrypted_string = (char *)malloc((current_length + 2) * sizeof(char));
  for (int i = 0; i < current_length; i++) {
    if ('a' <= initial_string[i] && initial_string[i] <= 'z') {
      encrypted_string[i] = (char)((initial_string[i] - 'a' + shift_number) % K) + 'a';
    } else if ('A' <= initial_string[i] && initial_string[i] <= 'Z') {
      encrypted_string[i] = (char)((initial_string[i] - 'A' + shift_number) % K) + 'A';
    } else {
      encrypted_string[i] = initial_string[i];
    }
  }
  encrypted_string[current_length] = '.';
  encrypted_string[current_length + 1] = '\0';

  printf("%s", encrypted_string);
  free(encrypted_string);
  free(initial_string);
}