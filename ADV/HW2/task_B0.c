#include <stdint.h>
#include <stdio.h>

typedef struct list {
  uint64_t address;
  size_t size;
  char comment[64];
  struct list *next;
} list;

uint64_t findMaxBlock(list *head) {

  uint64_t max_address = 0;
  size_t max_size = 0;
  for (list *p = head; p; p = p->next) {
    if (p->size > max_size) {
      max_size = p->size;
      max_address = p->address;
    }
  }
  return max_address;
}

int main(void) {
    list some[] = {
        {140525067852320, 10, "", }
    }
}