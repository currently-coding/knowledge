#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bintree bintree;

struct bintree {
  bintree *left, *right;
  char *value;
};

void print_tree(bintree *b) {
  if (b) { // AI: [1]    175276 segmentation fault (core dumped)  ./1.3.out
    printf("(");
    print_tree(b->left);
    printf("%s", b->value);
    print_tree(b->right);
    printf(")");
  }
}

void insert_tree(bintree *root, bintree *sub) {
  int strcmpresult = strcmp(sub->value, root->value);
  if (strcmpresult <= 0) {
    if (!root->left) { // teilbaum ist frei wenn pointer auf NULL zeigt
      root->left = sub;
    } else {
      insert_tree(root->left, sub);
    }
  } else {
    if (!root->right) {
      root->right = sub;
    } else {
      insert_tree(root->right, sub);
    }
  }
}

int main() {
  // bintree <name> = bintree{...}; -> bintree <name> = {...}; // AI
  bintree t1 = {NULL, NULL, "abr"};
  bintree t2 = {NULL, NULL, "ra"};
  bintree t3 = {NULL, NULL, "aca"};
  bintree t4 = {NULL, NULL, "dab"};
  insert_tree(&t1, &t2);
  insert_tree(&t1, &t3);
  insert_tree(&t1, &t4);
  print_tree(&t1);
  return 0;
}
