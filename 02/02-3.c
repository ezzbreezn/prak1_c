#include <stdio.h>

int main(void)
{
  long long n, m;
  long long a[100000], b[100000], c[200000];
  scanf("%lld", &n);
  for (long long i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  scanf("%lld", &m);
  for (long long i = 0; i < m; ++i)
    scanf("%lld", &b[i]);
  long long t = 0;
  long long end = (n > m ? n : m);
  for (long long i = 0; i < end; ++i)
  {
    if (i < n && i < m)
    {
      c[t] = a[i];
      ++t;
      c[t] = b[i];
      ++t;
    }
    else if (i >= n && i < m)
    {
      c[t] = b[i];
      ++t;
    }
    else if (i >= m && i < n)
    {
      c[t] = a[i];
      ++t;
    }
  }
  for (long long i = 0; i < t; ++i)
    printf("%lld ", c[i]);
  return 0;
}
