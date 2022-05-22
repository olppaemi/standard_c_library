#include <stdio.h>
#include <time.h>

int main() {
  time_t t = (time_t)0;
  printf("KST: %s", ctime(&t));               // KST: Thu Jan  1 09:00:00 1970
  printf("KST: %s", asctime(localtime(&t)));  // KST: Thu Jan  1 09:00:00 1970
  printf("UTC: %s", asctime(gmtime(&t)));     // UTC: Thu Jan  1 00:00:00 1970
  return 0;
}