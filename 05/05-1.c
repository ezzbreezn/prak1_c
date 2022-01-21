#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  long long n;
  scanf("%lld", &n);
  long long **a;
  a = (long long **) malloc(sizeof(long long *) * n);
  for (long long i = 0; i < n; ++i)
  {
    a[i] = (long long *) malloc(sizeof(long long) * 2 * n);
    for (long long j = 0; j < 2 * n; ++j)
    {
      scanf("%lld", &a[i][j]);
      if (j % 2 == 1)
        a[i][j] *= -1;
    }
  }
  for (long long j = 0; j < 2 * n; j += 2)
  {
    for (long long i = 0; i < n; ++i)
      printf("%lld %lld ", a[i][j], a[i][j + 1]);
    printf("\n");
  }
  for (long long i = 0; i < n; ++i)
    free(a[i]);
  free(a);
  return 0;
}
