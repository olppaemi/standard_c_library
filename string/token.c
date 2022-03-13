#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define TOKEN_SIZE 1000
enum ETT { TT_OPR, TT_VAR, TT_NUM, TT_BAD, TT_EOF };
const char *TK_NAMES[] = {"Operator", "Variable", "Number"};
enum ETT get_token(char *token);

int main() {
  char token[TOKEN_SIZE];
  enum ETT tt;
  while ((tt = get_token(token)) <= TT_NUM)
    printf("%s: %s\n", TK_NAMES[tt], token);
  if (tt == TT_BAD) fprintf(stderr, "bad token: %s\n", gets(token));

  return 0;
}

enum ETT get_token(char *token) {
  static const char *ops = "+-*/%()";
  char *p = token;
  int c;

  while (isspace(c = getchar()))
    ;
  if (strchr(ops, c)) {
    token[0] = c;
    token[1] = '\0';
    return TT_OPR;
  }
  if (c == EOF) return TT_EOF;
  if (c == '$') {
    *p++ = c;
    while (isalnum(c = getchar()) || c == '_') *p++ = c;
    *p = '\0';
    if (c != EOF) ungetc(c, stdin);
    return TT_VAR;
  }
  if (!isdigit(c)) {
    ungetc(c, stdin);
    return TT_BAD;
  }
  // number
  *p++ = c;
  while (isdigit(c = getchar())) *p++ = c;
  *p = '\0';
  if (c != EOF) ungetc(c, stdin);
  return TT_NUM;
}