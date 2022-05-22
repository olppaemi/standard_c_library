#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm *pt = localtime(&t);

  printf("%s", ctime(&t));
  printf("%04d/%02d/%02d %02d:%02d:%02d\n", pt->tm_year + 1900, pt->tm_mon + 1,
         pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec);
  printf("연중 %d일째, 주중 %d일째\n", pt->tm_yday + 1, pt->tm_wday + 1);

  if (pt->tm_isdst > 0)
    printf("DST: Yes\n");
  else if (pt->tm_isdst < 0)
    printf("DST: Unknown\n");
  else
    printf("DST: No\n");

  return 0;
}