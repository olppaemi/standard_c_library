#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int id;
  double gpa;
} STUD_T;
typedef int (*FCMP_T)(const void *, const void *);
#define SIZE (sizeof TBL / sizeof *TBL)

STUD_T TBL[] = {{"KIM", 202010, 3.4},
                {"LEE", 202011, 3.3},
                {"KIM", 202009, 3.0},
                {"CHO", 202012, 3.5}};

int f_cmp(const STUD_T *p, const STUD_T *q) {
  int r = strcmp(p->name, q->name);
  if (r) return r;
  return p->id - q->id;
}

void out(const STUD_T *p, int size) {
  const STUD_T *up;
  for (up = p + size; p < up; p++)
    printf("%s %d %#.3g\n", p->name, p->id, p->gpa);
}

int main() {
  char name[1000];
  STUD_T s = {name}, *p;

  qsort(TBL, SIZE, sizeof *TBL, (FCMP_T)f_cmp);
  out(TBL, SIZE);

  while (printf("key(name id) = "), scanf("%s %d", s.name, &s.id) == 2)
    if ((p = (STUD_T *)bsearch(&s, TBL, SIZE, sizeof *TBL, (FCMP_T)f_cmp)))
      printf("%s %d %#.3g\n", p->name, p->id, p->gpa);
    else
      printf("not found: %s %d\n", s.name, s.id);

  return 0;
}