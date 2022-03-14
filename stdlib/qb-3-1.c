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
int f_cmp_find(const void *p, const void *q) {
  return strcmp((char *)p, *(char **)q);
}
int f_cmp_find_r(const void *p, const void *q) {
  return strcmp(*(char **)q, (char *)p);
}

int main(int argc, char const *argv[]) {
  char key[1000];
  int i;
  int (*pf_sort)(const void *, const void *);
  int (*pf_find)(const void *, const void *);

  if (argc == 1) {
    pf_sort = f_cmp_sort;
    pf_find = f_cmp_find;
  } else if (argc == 2 && !strcmp(argv[1], "-r")) {
    pf_sort = f_cmp_sort_r;
    pf_find = f_cmp_find_r;
  } else
    fprintf(stderr, USAGE), exit(1);

  qsort(TBL, SIZE, sizeof TBL[0], pf_sort);
  for (i = 0; i < SIZE; i++) printf("%s ", TBL[i]);
  putchar('\n');

  while (printf("key = "), scanf("%s", key) == 1)
    if (bsearch(key, TBL, SIZE, sizeof TBL[0], pf_find))
      printf("%s: found\n", key);
    else
      printf("%s: not found\n", key);
  return 0;
}
