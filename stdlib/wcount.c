#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 10000

typedef struct _tag_tnode {
  char *word;
  int count;
  struct _tag_tnode *left, *right;
} TNODE_T;

TNODE_T *tree_add(const char *word, TNODE_T *p);

void tree_out(const TNODE_T *p);

void tree_remove(TNODE_T *p);

int main() {
  TNODE_T *root = NULL;
  char word[WORD_SIZE];

  while (scanf("%s", word) == 1) root = tree_add(word, root);

  tree_out(root);
  tree_remove(root);
}

TNODE_T *tree_add(const char *word, TNODE_T *p) {
  int r;
  if (!p) {
    if (!(p = (TNODE_T *)malloc(sizeof *p)) || !(p->word = strdup(word)))
      fprintf(stderr, "no space\n"), exit(1);
    p->left = p->right = NULL;
    p->count = 1;
  } else if ((r = strcmp(word, p->word)) < 0)
    p->left = tree_add(word, p->left);
  else if (r > 0)
    p->right = tree_add(word, p->right);
  else
    p->count++;
  return p;
}

void tree_out(const TNODE_T *p) {
  if (!p) return;
  tree_out(p->left);
  printf("%4d: %s\n", p->count, p->word);
  tree_out(p->right);
}

void tree_remove(TNODE_T *p) {
  if (!p) return;
  tree_remove(p->left);
  tree_remove(p->right);
  free(p->word);
  free(p);
}