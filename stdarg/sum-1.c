#include <stdarg.h>
#include <stdio.h>

int sum(int n, ...) {
  int i, res = 0;
  va_list ap;
  va_start(ap, n);
  for (i = 0; i < n; i++) res += va_arg(ap, int);
  va_end(ap);

  return res;
}

int main() {
  printf("%d %d", sum(2, 1, 2), sum(3, 10, 20, 30, 40));
  return 0;
}