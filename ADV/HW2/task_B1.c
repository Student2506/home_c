#include <stdint.h>
#include <stdio.h>

typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;

size_t totalMemoryUsage(list *head) {
  size_t total_mem = 0;
  for (list *p = head; p; p = p->next) {
    total_mem += p->size;
  }
  return total_mem;
}

int main(void) {
  list some[] = {
    {
        140525067852320,
        10,
        "",
    }
  }
}