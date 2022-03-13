#include <stdio.h>

#define OUT(fc, x) printf("%s = %" #fc "\n", #x, x)

int main() {
  int n = 10;
  char msg[] = "Hello";

  OUT(c, 'A' + 1);
  OUT(d, n);
  OUT(g, n / 4.0);
  OUT(s, msg);
  OUT(s,
      "Hi! "
      "Bye~\n");
  OUT(d, FILENAME_MAX);
  OUT(d, FOPEN_MAX);
  OUT(d, L_tmpnam);
  OUT(d, TMP_MAX);
  OUT(d, BUFSIZ);

  return 0;
}