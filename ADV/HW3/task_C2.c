#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void init(Stack *stack) { stack->top = -1; }

bool isFull(Stack *stack) { return stack->top == MAX_SIZE - 1; }

bool isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int value) {
  if (isFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow\n");
    return;
  }
  return stack->arr[stack->top--];
}

int main(void) {
  Stack stack;
  init(&stack);
  int c;
  int *numbers = NULL;
  char *input = NULL;
  int i = 0;
  int first_arg, second_arg;
  char op;
  input = (char *)malloc(sizeof(char) * MAX_SIZE);
  if (input == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  while ((c = getchar()) != '.' && c != EOF && i < MAX_SIZE - 1) {
    input[i] = (char)c;
    i++;
  }
  input[i] = '\0';
  char *token = strtok(input, " ");
  push(&stack, atoi(token));
  while (token != NULL) {
    token = strtok(NULL, " ");
    if (token != NULL) {
      if (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*') {
        op = token[0];
        if (op == '+') {
          second_arg = pop(&stack);
          first_arg = pop(&stack);
          push(&stack, first_arg + second_arg);
        }
        if (op == '-') {
          second_arg = pop(&stack);
          first_arg = pop(&stack);
          push(&stack, first_arg - second_arg);
        }
        if (op == '/') {
          second_arg = pop(&stack);
          first_arg = pop(&stack);
          if (second_arg == 0)
            return 0;

          push(&stack, first_arg / second_arg);
        }
        if (op == '*') {
          second_arg = pop(&stack);
          first_arg = pop(&stack);
          push(&stack, first_arg * second_arg);
        }
      } else {
        push(&stack, atoi(token));
      }
    }
  }
  printf("%d", pop(&stack));
  free(input);
  input = NULL;
}
