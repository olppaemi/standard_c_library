#include <stdarg.h>
#include <stdio.h>

#ifdef _DEBUG
#define TRACE(...) trace(__FILE__, __func__, __LINE__, __VA_ARGS__)
#else
#define TRACE(...)
#endif

void trace(const char *file, const char *func, int line, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  printf("[%s:%s:%d] ", file, func, line);
  vprintf(fmt, ap);
  va_end(ap);
}

int sum(int a, int b) {
  int res;
  TRACE("a = %d, b = %d\n", a, b);
  res = a + b;
  TRACE("res = %d\n", res);
  return res;
}

int main() {
  printf("sum(1, 2) = %d\n", sum(1, 2));
  return 0;
}