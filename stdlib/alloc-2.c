#include <stdio.h>
#include <stdlib.h>

#define NCOL 4

void out_matrix(const char* name, const int m[][NCOL], int nrow) {
  int i, j;
  printf("=== %s ===\n", name);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < NCOL; j++) printf("%d ", m[i][j]);
    putchar('\n');
  }
}

int main() {
  int m[][NCOL] = {{1, 2}, {3}};
  int(*p)[NCOL], nrow = 3;

  out_matrix("m", m, sizeof m / sizeof m[0]);

  if (!(p = (int(*)[NCOL])calloc(sizeof *p, nrow)))
    fprintf(stderr, "no space\n"), exit(1);
  out_matrix("p", p, nrow);
  free(p);

  return 0;
}