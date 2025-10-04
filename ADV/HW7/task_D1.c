#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 256

typedef struct tree {
  int key;
  struct tree *left, *right;
} tree;

void goLeft(tree *root) {
  if (root->left) {
    goLeft(root->left);
  }
  printf("%d ", root->key);
}

void goRight(tree *root) {
  if (root->right) {
    printf("%d ", root->right->key);
    goRight(root->right);
  }
}

void btUpView(tree *root) {
  if (root == NULL) {
    return;
  }
  if (root->key == 0) {
    return;
  }
  goLeft(root);  // сказка
  goRight(root); // песня
}

int main(void) {
  tree *head = calloc(1, sizeof(tree));
  //   char *str = malloc(LENGTH * sizeof(char));
  //   fgets(str, LENGTH, stdin);
  //   int array[LENGTH], count = 0;
  //   char *token = strtok(str, " ");
  //   head->key = atoi(token);
  //   while (token != NULL) {
  //     array[count] = atoi(token);
  //     if(head->left == NULL)

  //     token = strtok(NULL, " ");
  //     count++;
  //   }
  //   printf("%d", count);
  head->key = 10;
    head->left = calloc(1, sizeof(tree));
    head->left->key = 5;
    head->right = calloc(1, sizeof(tree));
    head->right->key = 15;
    head->left->left = calloc(1, sizeof(tree));
    head->left->left->key = 3;
    head->left->right = calloc(1, sizeof(tree));
    head->left->right->key = 7;
    head->right->left = calloc(1, sizeof(tree));
    head->right->left->key = 13;
    head->right->right = calloc(1, sizeof(tree));
    head->right->right->key = 18;
    head->left->left->left = calloc(1, sizeof(tree));
    head->left->left->left->key = 1;
    head->left->left->right = calloc(1, sizeof(tree));
    head->left->left->right->key = 6;
    head->left->right->left = calloc(1, sizeof(tree));
    head->left->right->left->key = 14;
    head->left->right->right = calloc(1, sizeof(tree));
    head->left->right->right->key = 0;
  btUpView(head);
  return 0;
}