#include <stdio.h>
#include <stdlib.h>

int main() {
  char tmp_name[L_tmpnam];
  FILE *fp;
  char line[1000];

  printf("%s\n", tmpnam(NULL));
  tmpnam(tmp_name);
  printf("%s\n", tmp_name);

  printf("Temporary file will be created...\n");
  printf("Press <Enter> to continue. ");
  gets(line);
  if (!(fp = tmpfile())) fprintf(stderr, "fail to create tmpfile\n"), exit(1);
  printf("Create temporary file using 'tmpfile'.\n");
  printf("Press <Enter> to continue. ");
  gets(line);
  return 0;
}