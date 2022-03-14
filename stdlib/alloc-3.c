#include <stdio.h>
#include <stdlib.h>

typedef struct _class {
  char *name;
  struct _class *super;
} CLASS_T;

void out_relation_chain(const CLASS_T c[], int n) {
  const CLASS_T *p;
  int i;
  for (i = 0; i < n; i++) {
    if (!c[i].super) continue;
    fputs(c[i].name, stdout);
    for (p = c[i].super; p; p = p->super) printf(" => %s", p->name);
    putchar('\n');
  }
}

int main() {
  CLASS_T *p, *q;
  int i;

  if (!(p = (CLASS_T *)malloc(6 * sizeof *p)))
    fprintf(stderr, "no space\n"), exit(1);
  p[0].name = "서울시", p[0].super = 0;
  p[1].name = "구로구", p[1].super = p + 0;
  p[2].name = "개봉동", p[2].super = p + 1;
  p[3].name = "강남구", p[3].super = p + 0;
  p[4].name = "경기도", p[4].super = 0;
  p[5].name = "과천시", p[5].super = p + 4;
  out_relation_chain(p, 6);

  printf("expanding memory ...\n");
  if (!(q = (CLASS_T *)realloc(p, 8 * sizeof *p)))
    free(p), fprintf(stderr, "no space\n"), exit(1);

  if (p != q) {
    for (i = 0; i < 6; i++)
      if (q[i].super) q[i].super = q + (q[i].super - p);
    p = q;
  }
  p[6].name = "관악구", p[6].super = p + 0;
  p[7].name = "신림동", p[7].super = p + 6;
  out_relation_chain(p, 8);
  free(p);

  return 0;
}