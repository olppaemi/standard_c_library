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

int f_cmp_sort(const STUD_T *p, const STUD_T *q) { return p->id - q->id; }
int f_cmp_find(int *p, const STUD_T *q) { return *p - q->id; }

void out(const STUD_T *p, int size) {
  const STUD_T *up;
  for (up = p + size; p < up; p++)
    printf("%s %d %#.3g\n", p->name, p->id, p->gpa);
}

int main() {
  int id;
  STUD_T *p;

  qsort(TBL, SIZE, sizeof *TBL, (FCMP_T)f_cmp_sort);
  out(TBL, SIZE);

  while (printf("key(id) = "), scanf("%d", &id) == 1)
    if ((p = (STUD_T *)bsearch(&id, TBL, SIZE, sizeof *TBL,
                               (FCMP_T)f_cmp_find)))
      printf("%s %d %#.3g\n", p->name, p->id, p->gpa);
    else
      printf("not found: %d\n", id);

  return 0;
}