#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define N2 (N * 2)

void out(const int a[], int n) {
  int i;
  printf("%d:", n);
  for (i = 0; i < n; i++) printf(" %d", a[i]);
  putchar('\n');
}

int main() {
  int a[N] = {1, 2, 3, 4, 5}, b[N] = {10, 20, 30, 40, 50};
  int *p, *q;

  p = (int *)malloc(sizeof a);
  // p = (int *)malloc(N * sizeof a[0]);
  if (!p)
    fprintf(stderr, "no space\n");
  else
    out(p, N);
  free(p);

  p = (int *)calloc(sizeof a[0], N);
  // p = (int*)calloc(N, sizeof a[0]);
  // p = (int*)calloc(sizeof a, 1);
  // p = (int*)calloc(1, sizeof a);
  if (!p) fprintf(stderr, "no space\n"), exit(1);
  out(p, N);
  memcpy(p, a, sizeof a);
  q = (int *)realloc(p, N2 * sizeof a[0]);
  // p = (int *)realloc(p, N2 * sizeof a[0]);
  if (!q) {
    free(p);
    fprintf(stderr, "no space\n"), exit(1);
  }
  p = q;
  memcpy(p + N, b, sizeof b);
  out(p, N2);
  free(p);

  return 0;
}