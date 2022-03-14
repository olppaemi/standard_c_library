#include <stdio.h>
#include <stdlib.h>

int f_cmp_double(const double *p, const double *q) {
  if (*p == *q) return 0;
  return (*p > *q) ? +1 : -1;
}

int main() {
  double tbl[] = {3.3, -1.1, 0.0, 3.2, 3.5, 0.1};
  const int SIZE = sizeof tbl / sizeof *tbl;
  double key;
  int i;

  qsort(tbl, SIZE, sizeof tbl[0],
        (int (*)(const void *, const void *))f_cmp_double);
  for (i = 0; i < SIZE; i++) printf("%g ", tbl[i]);
  putchar('\n');

  while (printf("key = "), scanf("%lf", &key) == 1)
    if (bsearch(&key, tbl, SIZE, sizeof *tbl,
                (int (*)(const void *, const void *))f_cmp_double))
      printf("%g: found\n", key);
    else
      printf("%g: not found\n", key);

  return 0;
}