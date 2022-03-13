#include <stdarg.h>
#include <stdio.h>

int vsum(int n, va_list arg) {
  int i, res = 0;
  for (i = 0; i < n; i++) res += va_arg(arg, int);
  return res;
}

int sum(int n, ...) {
  int res;
  va_list arg;
  va_start(arg, n);
  res = vsum(n, arg);
  va_end(arg);
  return res;
}

int main() {
  printf("%d %d\n", sum(2, 1, 2), sum(3, 10, 20, 30, 40));
  return 0;
}