#include <stdio.h>
#include <string.h>

int main() {
  char s[100];
  {
    int w = 4, p = 1;
    printf("[%*f][%.*f][%*.*f]\n", w, 3.4, p, 3.4, w, p, 3.4);
    // [3.400000][3.4][ 3.4]
  }
  {
    int n1, n2, n3, n4;
    printf("0123456789\n");
    n4 = printf("1%3d%nAB%n\n%n", 34, &n1, &n2, &n3);
    // 0123456789
    // 1 34AB
    printf("%d, %d, %d, %d\n", n1, n2, n3, n4);  // 4, 6, 7, 7
    printf("%d\n", sprintf(s, ""));              // 0
  }
  {
    char *s1 = "AB", *s2 = "CD", *s3 = "EF";
    strcpy(s, s1);
    strcat(s, ":");
    strcat(s, s2);
    strcat(s, ":");
    strcat(s, s3);
    puts(s);  // AB:CD:EF
    sprintf(s, "%s:%s:%s", s1, s2, s3);
    puts(s);  // AB:CD:EF
  }
  return 0;
}