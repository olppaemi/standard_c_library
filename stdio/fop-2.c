#include <stdio.h>
#include <stdlib.h>

int main() {
  const char *fn = "tmp.txt";
  FILE *fp;
  int c;
  if (!(fp = fopen(fn, "w+")))
    fprintf(stderr, "fail to open %s\n", fn), exit(1);
  fprintf(fp, "0123456789\n");
  rewind(fp);
  while ((c = getc(fp)) != EOF) putchar(c);
  fclose(fp);

  return 0;
}