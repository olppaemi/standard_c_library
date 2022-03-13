#include <stdio.h>
#include <string.h>

int main() {
  char s1[] = "abc,def,,hi \tjk";
  char s2[] = "abc,def,,hi \tjk";
  char *delim = " \t,", *p;

  if ((p = strtok(s1, delim))) {
    do {
      printf("[%s]", p);
    } while ((p = strtok(NULL, delim)));
    putchar('\n');
  }                          // [abc][def][hi][jk]
  printf("s1 => %s\n", s1);  // s1 => abc

  if ((p = strtok(s2, ","))) {
    printf("[%s]", p);
    if ((p = strtok(0, "\t "))) {
      printf("[%s]", p);
    }
    putchar('\n');
  }  // [abc][def,,hi]

  char s[] = ":abc::de-f";
  if ((p = strtok(s, ":-"))) {
    do {
      printf("[%s]", p);
    } while ((p = strtok(NULL, ":-")));
    putchar('\n');
    printf("s => %s\n", s);  // s => :abc
  }

  return 0;
}
