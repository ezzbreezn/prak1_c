#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  long long la = 0, lb = 0;
  char *a;
  char *b;
  char *res;
  a = (char *) malloc(sizeof(char) * 10000);
  b = (char *) malloc(sizeof(char) * 10000);
  char t;
  scanf("%c", &t);
  while (!(t >= '0' && t <= '9'))
    scanf("%c", &t);
  while (t >= '0' && t <= '9')
  {
    a[la] = t;
    ++la;
    scanf("%c", &t);
  }
  long long sign;
  if (t == '+')
    sign = 1;
  else if (t == '-')
    sign = -1;
  else
    sign = 0;
  scanf("%c", &t);
  while (t >= '0' && t <= '9')
  {
    b[lb] = t;
    ++lb;
    scanf("%c", &t);
  }
  for (long long i = 0; i < la; ++i)
    printf("%c", a[i]);
  printf("\n");
  for (long long i = 0; i < lb; ++i)
    printf("%c", b[i]);
  free(a);
  free(b);
  return 0;
}
