#include <stdio.h>
#include <stdlib.h>

#define NCOL 4
typedef int (*PMATRIX_T)[NCOL];

void out_matrix(const char *name, const PMATRIX_T m, int nrow) {
  int i, j;
  printf("=== %s ===\n", name);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < NCOL; j++) printf("%d ", m[i][j]);
    putchar('\n');
  }
}

int main() {
  int m[][NCOL] = {{1, 2}, {3}};
  PMATRIX_T p;
  int nrow = 3, i, j;

  out_matrix("m", m, sizeof m / sizeof m[0]);

  if (!(p = (PMATRIX_T)malloc(nrow * NCOL * sizeof(int))))
    fprintf(stderr, "no space\n"), exit(1);
  for (i = 0; i < nrow; i++)
    for (j = 0; j < NCOL; j++) p[i][j] = i + j;
  out_matrix("p", p, nrow);
  free(p);

  return 0;
}