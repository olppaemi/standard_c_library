#include <stdio.h>
#include <string.h>

int main() {
  char s1[] = "abc\0AAA", s2[] = "abc\0ABC", *p;

  printf("%s\n", (p = strchr(s1, 'A')) ? p : "NOT FOUND");  // NOT FOUND
  printf("%s\n", (p = memchr(s1, 'A', sizeof s1)) ? p : "NOT FOUND");  // AAA

  printf("%d\n", strcmp(s1, s2));             // 0
  printf("%d\n", memcmp(s1, s2, sizeof s1));  // -1
}