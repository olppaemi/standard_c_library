#include <stdio.h>

int main() {
  int n;
  printf("[%d] [%i] [%u]\n", -1, -1, -1);
  // [-1] [-1] [4294967295]
  printf("[%5d] [%-5d]\n", 12, 12);
  // [   12] [12   ]
  printf("[%05d] [%05d]\n", -12, 12);
  // [-0012] [00012]
  printf("[% d] [% d]\n", -12, 12);
  // [-12] [ 12]
  printf("[%X] [%#X]\n", -1, -1);
  // [FFFFFFFF] [0XFFFFFFFF]
  printf("[%+d] [%+d] [%+d]\n", -1, 0, 1);
  // [-1] [+0] [+1]
  printf("[%f] [%e] [%g]\n", 3.45, 3.45, 3.45);
  // [3.450000] [3.450000e+00] [3.45]
  printf("[%5.2f] [%5.2e] [%5.2g]\n", 3.45, 3.45, 3.45);
  // [ 3.45] [3.45e+00] [  3.5]
  printf("[%.0f] [%.0e] [%.0g] [%g]\n", 1.0, 1.0, 1.0, 1.0);
  // [1] [1e+00] [1] [1]
  printf("[%#.0f] [%#.0e] [%#.0g] [%#g]\n", 1.0, 1.0, 1.0, 1.0);
  // [1.] [1.e+00] [1.] [1.00000]
  printf("[%hd] [%ld]\n", 0x10000 + 12, 12L);
  //[12] [12]
  printf("[%f] [%Lf]\n", 3.45F, 3.45L);
  // [3.450000] [3.450000]
  printf("[%-+#8.0LF]\n", (long double)123);
  // [+123.   ]

  return 0;
}