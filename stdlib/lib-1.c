#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  double d;
  char *p;
  long l;
  unsigned long ul;

  printf("%g\n", atof(" -012.34E-1"));  // -1.234
  d = strtod("+01234abc", &p);
  printf("%g [%s]\n", d, p);            // 1234 [abc]
  printf("%g\n", strtod("ABC", NULL));  // 0

  printf("%d %ld\n", atoi("+01.9"), atol(" -2A"));  // 1 -2
  printf("%d %ld\n", abs(-1), labs(-2L));           // 1 2

  l = strtol(" -12.34abc", &p, 0);
  printf("%ld [%s]\n", l, p);                 // -12 [.34abc]
  printf("%ld\n", strtol("-012", NULL, 0));   // -10
  printf("%ld\n", strtol(" -11", NULL, 2));   // -3
  printf("%ld\n", strtol(" -11", NULL, 5));   // -6
  printf("%ld\n", strtol(" -11", NULL, 10));  // -11
  printf("%ld\n", strtol(" ABC", NULL, 10));  // 0

  printf("%ld, %ld, %lu\n", LONG_MIN, LONG_MAX, ULONG_MAX);
  // -9223372036854775808, 9223372036854775807, 18446744073709551615
  l = strtol("10000000000000000000abc", &p, 10);
  printf("%ld [%s]\n", l, p);  // 9223372036854775807 [abc]
  perror(NULL);                // Numerical result out of range
  errno = 0;
  ul = strtoul("10000000000000000000abc", &p, 10);
  printf("%lu [%s]\n", ul, p);  // 10000000000000000000 [abc]
  perror(NULL);                 // Success

  return 0;
}