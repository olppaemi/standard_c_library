#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE          \
  "Usage: qb-3 [-r]\n" \
  " -r: reverorder\n"
#define SIZE (sizeof TBL / sizeof TBL[0])
char *TBL[] = {"ab", "XY", "aaa", "ZZZ", "가나다", "321", "123", "하하하"};

int f_cmp_sort(const void *p, const void *q) {
  return strcmp(*(char **)p, *(char **)q);
}
int f_cmp_sort_r(const void *p, const void *q) {
  return strcmp(*(char **)q, *(char **)p);
}

int main(int argc, char const *argv[]) {
  char key[1000], *pk = key;
  int (*pf)(const void *, const void *), i;

  if (argc == 1)
    pf = f_cmp_sort;
  else if (argc == 2 && !strcmp(argv[1], "-r"))
    pf = f_cmp_sort_r;
  else
    fprintf(stderr, USAGE), exit(1);

  qsort(TBL, SIZE, sizeof TBL[0], pf);
  for (i = 0; i < SIZE; i++) printf("%s ", TBL[i]);
  putchar('\n');

  while (printf("key = "), scanf("%s", key) == 1)
    if (bsearch(&pk, TBL, SIZE, sizeof TBL[0], pf))
      printf("%s: found\n", key);
    else
      printf("%s: not found\n", key);
  // bsearch(&key, TBL, SIZE, sizeof TBL[0], pf) -- logical error
  // &key, key, &key[0]: same in pointer value but different in their types
  // &key -- char (*)[1000]; key, &key[0] -- char *
  return 0;
}
