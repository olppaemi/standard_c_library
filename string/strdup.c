#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_dup(const char *s) {
  char *p = (char *)malloc(strlen(s) + 1);
  if (p) strcpy(p, s);
  return p;
}

int main() {
  char *p;

  if (!(p = strdup("abc")))
    fprintf(stderr, "no space\n");
  else
    puts(p);
  free(p);

  if (!(p = str_dup("abc")))
    fprintf(stderr, "no space\n");
  else
    puts(p);
  free(p);
}