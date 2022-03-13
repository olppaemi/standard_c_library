#include <stdio.h>
#include <string.h>

int main() {
  int a[3], b[3] = {1, 2, 3};

  memset(a, '\0', 3 * sizeof(int));
  printf("%d %d %d\n", a[0], a[1], a[2]);  // 0 0 0
  memset(a + 1, '\xFF', 2 * sizeof a[0]);
  printf("%X %X %X\n", a[0], a[1], a[2]);  // 0 FFFFFFFF FFFFFFFF

  memcpy(a, b, 3 * sizeof(int));
  printf("%d %d %d\n", a[0], a[1], a[2]);  // 1 2 3
  memmove(a, a + 1, 2 * sizeof a[0]);
  printf("%d %d %d\n", a[0], a[1], a[2]);  // 2 3 3

  return 0;
}