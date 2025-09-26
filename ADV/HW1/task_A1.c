#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 26

int main(void) {
  int shift_number;
  scanf("%d ", &shift_number);
  int c;
  while ((c = getchar()) != '.' && c != EOF) {
    if ('a' <= (char)c && (char)c <= 'z')
      putchar(((c - 'a' + shift_number) % K) + 'a');
    else if ('A' <= (char)c && (char)c <= 'Z')
      putchar(((c - 'A' + shift_number) % K) + 'A');
    else
      putchar(c);
  }
  putchar('.');
}