#include <stdio.h>
#include <string.h>

#define LSIZE 1000
void display(FILE *fp);

int main(int argc, char const *argv[]) {
  FILE *fp;
  const char *fn;
  if (argc == 1) {
    printf("=== <stdin> ===\n");
    display(stdin);
    return 0;
  }
  while ((fn = *++argv)) {
    if (!(fp = fopen(fn, "r"))) {
      fprintf(stderr, "ERROR: fail to open %s\n", fn);
      continue;
    }
    printf("=== %s ===\n", fn);
    display(fp);
    fclose(fp);
  }
  return 0;
}

void display(FILE *fp) {
  char line[LSIZE];
  int no = 0, len;
  while (fgets(line, LSIZE, fp)) {
    printf("%4d: %s", ++no, line);
    while (line[strlen(line) - 1] != '\n') {
      if (!fgets(line, LSIZE, fp)) {
        putchar('\n');
        return;
      }
      fputs(line, stdout);
    }
  }
}