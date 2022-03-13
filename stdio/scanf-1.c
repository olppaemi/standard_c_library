#include <stdio.h>

int main() {
  char c;
  short h;
  unsigned short hu;
  long l;
  int i, i1, i2, i3, n, m, r;
  float f, f1, f2, f3;
  double d;
  long double ld;

  sscanf("A", "%c", &c);
  i = c;
  printf("%c %d %c %d\n", c, c, i, i);
  sscanf("50000 50000 50000", "%hu %hd %lu", &hu, &h, &l);
  printf("%u %d %lu\n", hu, h, l);

  sscanf("12 12 12", "%d %o %x", &i1, &i2, &i3);
  printf("%d %d %d\n", i1, i2, i3);  // 12 10 18
  sscanf("12 012 0x12", "%d %d %d", &i1, &i2, &i3);
  printf("%d %d %d\n", i1, i2, i3);  // 12 12 0
  sscanf("12 012 0x12", "%i %i %i", &i1, &i2, &i3);
  printf("%d %d %d\n", i1, i2, i3);  // 12 10 18

  sscanf("3.4 3.4 3.4", "%f %lf %Lf", &f, &d, &ld);
  printf("%f %f %Lf\n", f, d, ld);  // 3.400000 3.400000 3.400000
  sscanf("3.4 34e-2 123", "%E %G %f", &f1, &f2, &f3);
  printf("%f %f %f\n", f1, f2, f3);  // 3.400000 0.340000 123.000000

  r = sscanf("1234", "%3d%n", &i, &n);
  printf("%d, %d, %d\n", i, n, r);  // 123, 3, 1
  m = -999;
  r = sscanf("1234 67", "%*d %d%n%d", &i, &n, &m);
  printf("%d, %d, %d, %d\n", i, n, m, r);  // 67, 7, -999, 1

  return 0;
}
