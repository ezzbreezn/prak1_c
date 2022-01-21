#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[100];
  long long n;
  scanf("%lld", &n);
  getchar();
  fgets(s, 82, stdin);
  int len = strlen(s)-1;
  n %= len;
  char res[100];
  strncpy(res, s+n, len -n);
  strncat(res, s, n);
  printf("%s", res);
  return 0;
}
