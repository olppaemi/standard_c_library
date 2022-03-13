#include <stdio.h>
#include <stdlib.h>

int main() {
  const char *fn = "tmp.txt";
  FILE *fp;
  int c;

  if (!(fp = fopen(fn, "wb")))
    fprintf(stderr, "fail to open %s\n", fn), exit(1);
  fprintf(fp, "01234");
  fclose(fp);

  if (!(fp = fopen(fn, "a+b")))
    fprintf(stderr, "fail to open %s\n", fn), exit(1);
  fseek(fp, 0, SEEK_SET);
  fprintf(fp, "56789\n");
  fseek(fp, 0, SEEK_END);
  while ((c = getc(fp)) != EOF) putchar(c);
  fclose(fp);

  return 0;
}