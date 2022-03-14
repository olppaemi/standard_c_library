#include <stdio.h>
#include <stdlib.h>

int f_cmp_int(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int main() {
  int tbl[] = {3, -1, 0, 4, 6, 1};
  const int SIZE = sizeof tbl / sizeof tbl[0];
  int key, i;

  qsort(tbl, SIZE, sizeof tbl[0], f_cmp_int);
  for (i = 0; i < SIZE; i++) printf("%d ", tbl[i]);
  putchar('\n');

  while (printf("key = "), scanf("%d", &key) == 1)
    if (bsearch(&key, tbl, SIZE, sizeof tbl[0], f_cmp_int))
      printf("%d: found\n", key);
    else
      printf("%d: not found\n", key);

  return 0;
}