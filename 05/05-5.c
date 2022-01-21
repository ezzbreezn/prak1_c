#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  long long l;
  scanf("%lld", &l);
  char *a;
  char *b;
  char *c;
  a = (char *) malloc(sizeof(char) * l);
  b = (char *) malloc(sizeof(char) * l);
  c = (char *) malloc(sizeof(char) * l);
  char t;
  scanf("%c", &t);
  while(!(t >= 'a' && t <= 'z'))
    scanf("%c", &t);
  for (long long i = 0; i < l; ++i)
  {
    a[i] = t;
    scanf("%c", &t);
  }
  while(!(t >= 'a' && t <= 'z'))
    scanf("%c", &t);
  for (long long i = 0; i < l; ++i)
  {
    b[i] = t;
    scanf("%c", &t);
  }
  while(!(t >= 'a' && t <= 'z'))
    scanf("%c", &t);
  for (long long i = 0; i < l; ++i)
  {
    c[i] = t;
    scanf("%c", &t);
  }
  for (long long i = 0; i < l; ++i)
    printf("%c",c[i]);
  for (long long i = 0; i < l; ++i)
    printf("%c",a[i]);
  for (long long i = 0; i < l; ++i)
    printf("%c",b[i]);
  free(a);
  free(b);
  free(c);
  return 0;
}
