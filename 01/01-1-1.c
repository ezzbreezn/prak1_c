#include <stdio.h>

int main(void)
{
    long long n;
    scanf("%lld", &n);
    long long temp;
    scanf("%lld", &temp);
    long long mn = temp, mx = temp;
    for (long long i = 1; i < n; ++i)
    {
      scanf("%lld", &temp);
      if (temp > mx)
        mx = temp;
      else if (temp < mn)
        mn = temp;
    }
    printf("%lld", mx - mn);
    return 0;
}
