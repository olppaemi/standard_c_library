#include <stdio.h>
#include <stdlib.h>

int main() {
  char line[100];
  int mm, dd, n;
  while (gets(line)) {
    if ((n = sscanf(line, "%d:%d", &mm, &dd)) != 2 &&
        (n = sscanf(line, "%d/%d", &mm, &dd)) != 2)
      fprintf(stderr, "format: mm:dd or mm/dd\n"), exit(1);
    printf("%d월 %d일\n", mm, dd);
  }
}