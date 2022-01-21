#include <stdio.h>

int main(void)
{
    long long a[10000];
    long long temp;
    int i = 0;
    scanf("%lld", &temp);
    while (temp != 0)
    {
      a[i] = temp;
      ++i;
      scanf("%lld", &temp);
    }
    --i;
    for(; i >= 0; --i)
      printf("%lld ", a[i]);
    return 0;
}
