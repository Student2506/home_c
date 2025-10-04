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

int main(void) {
  tree *head = calloc(1, sizeof(tree));
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