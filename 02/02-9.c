#include <stdio.h>

int main(void)
{
  long long coef[10000];
  long long args[10000];
  long long n;
  scanf("%lld", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &coef[i]);
  long long m;
  scanf("%lld", &m);
  for(int i = 0; i < m; ++i)
    scanf("%lld", &args[i]);
  long long temp;
  long long pow;
  for (int i = m - 1; i >= 0; --i)
  {
    temp = 0;
    pow = 1;
    for (int j = 0; j < n; ++j)
    {
      temp += coef[j] * pow;
      pow *= args[i];
    }
    printf("%lld ", temp);
  }
  return 0;
}
