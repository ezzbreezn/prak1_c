#include <stdio.h>

int main(void)
{
  int a[1500000];
  int n;
  scanf("%d", &n);
  int xor = 0;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &a[i]);
    xor ^= a[i];
  }
  int shift = 0;
  for (; shift < 32; ++shift)
  {
    if ((xor >> shift) & 1)
      break;
  }
  int xor1 = 0;
  for (int i = 0; i < n; ++i)
  {
    if((a[i] >> shift) & 1)
      xor1 ^= a[i];
  }
  xor ^= xor1;
  if (xor > xor1)
    printf("%d %d", xor1, xor);
  else
    printf("%d %d", xor, xor1);
  return 0;
}
