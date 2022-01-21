#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
  long long n;
  scanf("%lld", &n);
  long long mtrace = LLONG_MIN;
  long long dim, ttrace = 0, rdim = 0, ldim = 0;
  long long **prom = (long long **)malloc(sizeof(long long *) * 2);
  long long **res = (long long **)malloc(sizeof(long long *) * 2);
  for (long long i = 0; i < 2; ++i)
  {
    prom[i] = (long long *)malloc(sizeof(long long) * 2);
    res[i] = (long long *)malloc(sizeof(long long) * 2);
  }
  for (long long i = 0; i < n; ++i)
  {
    ttrace = 0;
    scanf("%lld", &dim);
    if (dim == 0) continue;
    ldim = dim;
    prom = (long long **)realloc(prom, sizeof(long long *) * dim);
    for (long long j = 0; j <  dim; ++j)
      prom[j] = (long long*)realloc(prom[j], sizeof(long long) * dim);
    for (long long j = 0; j < dim; ++j)
    {
      for (long long k = 0; k < dim; ++k)
      {
        scanf("%lld", &prom[j][k]);
        if (j == k)
          ttrace += prom[j][k];
      }
    }
    if (ttrace > mtrace)
    {
      mtrace = ttrace;
      rdim = dim;
      res = (long long **)realloc(res, sizeof(long long *) * dim);
      for (long long j = 0; j < dim; ++j)
        res[j] = (long long *)realloc(res[j], sizeof(long long) * dim);
      for (long long j = 0; j < dim; ++j)
        for (long long k = 0; k < dim; ++k)
          res[j][k] = prom[j][k];
    }
  }
  for (long long i = 0; i < rdim; ++i)
  {
    for (long long j = 0; j < rdim; ++j)
      printf("%lld ", res[i][j]);
    printf("\n");
  }
  for (long long i = 0; i < rdim; ++i)
    free(res[i]);
  for (long long i = 0; i < ldim; ++i)
    free(prom[i]);
  free(res);
  free(prom);

  return 0;
}
