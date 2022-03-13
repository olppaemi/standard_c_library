#include <stdarg.h>
#include <stdio.h>

void print(const char *format, ...) {
  const char *p;
  va_list ap;
  va_start(ap, format);
  for (p = format; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
      case 'd':
        printf("%d", va_arg(ap, int));
        break;
      case 'f':
        printf("%f", va_arg(ap, double));
        break;
      case 's':
        fputs(va_arg(ap, char *), stdout);
        break;
      case 'c':
        putchar(va_arg(ap, int));
        break;
      default:
        putchar(*p);
        break;
    }
  }
  va_end(ap);
}

int main() {
  print("100%% %c %d %d %d %f %f %s\n", 'A', 'A', (short)10, 10, 3.4, 3.4f,
        "Hello");
  return 0;
}