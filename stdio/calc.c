#include <math.h>
#include <stdio.h>

int main() {
  char s[100], r;
  double x, y;
  char op;
  while (printf(">> "), gets(s)) {
    if (sscanf(s, "%lf %c %lf %c", &x, &op, &y, &r) != 3) continue;
    switch (op) {
      case '+':
        printf(" => %g\n", x + y);
        break;
      case '-':
        printf(" => %g\n", x - y);
        break;
      case '*':
        if (y != 0.0) printf(" => %g\n", x * y);
        break;
      case '/':
        if (y != 0.0) printf(" => %g\n", fmod(x, y));
        break;
    }
  }
  return 0;
}