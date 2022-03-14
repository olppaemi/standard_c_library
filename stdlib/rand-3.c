#include <stdio.h>
#include <stdlib.h>

int main() {
  int i;
  printf("RAND_MAX = %d\n", RAND_MAX);

  for (i = 0; i < 5; i++)  // int [0, 99]
    printf("%d ", rand() % 100);
  putchar('\n');
  for (i = 0; i < 5; i++)  // int [1, 100]
    printf("%d ", rand() % 100 + 1);
  putchar('\n');
  for (i = 0; i < 5; i++)  // float [0.0, 1.0]
    printf("%.3f ", rand() / (float)RAND_MAX);
  putchar('\n');
  for (i = 0; i < 5; i++)  // double [0.0, 1.0)
    printf("%.3f ", rand() / (RAND_MAX + 1.0));
  putchar('\n');

  return 0;
}