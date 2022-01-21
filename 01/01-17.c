#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int temp, xor;
    scanf("%d", &temp);
    xor = temp;
    for (int i = 1; i < n; ++i)
    {
      scanf("%d", &temp);
      xor ^= temp;
    }
    printf("%d", xor);
    return 0;
}
