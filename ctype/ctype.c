#include <ctype.h>
#include <stdio.h>

int main() {
  char s[] = "한글(Korean Alphabet)", *p;
  for (p = s; *p; p++) *p = toupper(*p);
  puts(s);  // 한글(KOREAN ALPHABET)

  printf("isalpha('%c'): %s\n", '_', isalpha('_') ? "TRUE" : "FALSE");
  // isalpha('_'): FALSE
  printf("ispunct('%c'): %s\n", '_', ispunct('_') ? "TRUE" : "FALSE");
  // isalpha('_'): TRUE
}