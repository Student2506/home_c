#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
  int key;
  struct tree *left, *right;
  struct tree *parent; // ссылка на родителя
} tree;

tree *findBrother(tree *root, int key) {
  if (root == NULL)
    return NULL;

  if (root->key == key) {
    if (root->parent == NULL)
      return NULL;
    if (root->parent->left->key == key)
      return root->parent->right;
    else
      return root->parent->left;
  }
  if (root->left) {
    tree *result = findBrother(root->left, key);
    if (result != NULL)
      return result;
  }
  if (root->right)
    return findBrother(root->right, key);
}

void preorder(tree *root) {
  if (root == NULL)
    return;
  printf("%d ", root->key);
  if (root->left)
    preorder(root->left);
  if (root->right)
    preorder(root->right);
}

int heightTree(tree *p) {
  if (p == NULL) {
    return 0;
  } else {
    int lheight = heightTree(p->left);
    int rheight = heightTree(p->right);
    if (lheight > rheight)
      return (lheight + 1);
    else
      return (rheight + 1);
  }
}

void printCurrentLevel(tree *root, int level) {
  if (root == NULL)
    return;

  if (level == 1)
    // printf("%d ", root->key);
    printf("");
  else if (level > 1) {
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
  }
}

void printBFS(tree *root) {
  int h = heightTree(root);
  int i;
  for (i = 1; i <= h; i++) {
    printCurrentLevel(root, i);
  }
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
  head->left->parent = head;
  head->left->key = 5;
  head->right = calloc(1, sizeof(tree));
  head->right->parent = head;
  head->right->key = 15;
  head->left->left = calloc(1, sizeof(tree));
  head->left->left->parent = head->left;
  head->left->left->key = 3;
  head->left->right = calloc(1, sizeof(tree));
  head->left->right->parent = head->left;
  head->left->right->key = 7;
  head->right->left = calloc(1, sizeof(tree));
  head->right->left->parent = head->right;
  head->right->left->key = 13;
  head->right->right = calloc(1, sizeof(tree));
  head->right->right->parent = head->right;
  head->right->right->key = 18;
  head->left->left->left = calloc(1, sizeof(tree));
  head->left->left->left->parent = head->left->left;
  head->left->left->left->key = 1;
  head->left->left->right = calloc(1, sizeof(tree));
  head->left->left->right->parent = head->left->left;
  head->left->left->right->key = 6;
  head->left->right->left = calloc(1, sizeof(tree));
  head->left->right->left->parent = head->left->right;
  head->left->right->left->key = 14;
  head->left->right->right = calloc(1, sizeof(tree));
  head->left->right->right->parent = head->left->right;
  head->left->right->right->key = 0;
  tree *result = findBrother(head, 10);
  return 0;
}