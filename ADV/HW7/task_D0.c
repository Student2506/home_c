#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  char word[20];
  struct list *next;
} list;

void add_to_list(list **words, char *word) {
  list *temp = *words;
  if (*words) {
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = calloc(1, sizeof(list));
    strcpy(temp->next->word, word);
    temp->next->next = NULL;

  } else {
    *words = (list *)calloc(1, sizeof(list));
    strcpy((*words)->word, word);
    (*words)->next = NULL;
  }
}
void swap_elements(list *left, list *right) {
  list *temp = malloc(sizeof(list));
  strcpy(temp->word, left->word);
  strcpy(left->word, right->word);
  strcpy(right->word, temp->word);
  free(temp);
}
void print_list(list **words) {
  list *item = *words;
  while (item != NULL) {
    printf("%s ", item->word);
    item = item->next;
  }
}
void delete_list(list **words) {
  list *next = NULL;
  while (*words != NULL) {
    next = (*words)->next;
    free(*words);
    *words = next;
  }
}

int main(void) {
  list *head = NULL;
  char *str = malloc(20 * sizeof(char));
  int len = 0;
  for (;;) {
    scanf("%s", str);
    len = strlen(str);
    if ('.' == str[len - 1]) {
      str[len - 1] = '\0';
      add_to_list(&head, str);
      break;
    }
    add_to_list(&head, str);
  }
  free(str);
  bool replace;
  while (true) {
    replace = false;
    list *copy = head;
    while (copy->next != NULL) {
      if (strcmp(copy->word, copy->next->word) > 0) {
        swap_elements(copy, copy->next);
        replace = true;
      }
      copy = copy->next;
    }
    if (!replace)
      break;
  }
  print_list(&head);
  delete_list(&head);
  return 0;
}