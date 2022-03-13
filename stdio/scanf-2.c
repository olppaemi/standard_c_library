#include <stdio.h>

int main() {
  int i, n = 10, *p = &n, *q;
  char s[100], c1, c2;

  sprintf(s, "%p", p);
  sscanf(s, "%p", &q);
  printf("%d\n", *q);  // 10

  sscanf("   A", "%c %c", &c1, &c2);
  printf("[%c][%c]\n", c1, c2);  // [ ][A]
  sscanf(" abcd", "%3s", s);
  printf("[%s]\n", s);  // [abc]
  sscanf(" ABCD", "%2c", s);
  printf("[%s]\n", s);  // [ Ac]
  sscanf("ABxy-120_AB", "%[ABC]", s);
  puts(s);  // AB
  sscanf("ABxy-120_AB", "%[A-Za-z0-9-]", s);
  puts(s);  // ABxy-120
  sscanf("A[10].12", "%[][A-Za-z0-9]", s);
  puts(s);  // A[10]
  sscanf("A[10].12", "%[^][]", s);
  puts(s);  // A
  sscanf("AB-ab123", "%*[^0-9]%d", &i);
  printf("%d\n", i);  // 123

  return 0;
}