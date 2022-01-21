#include <stdio.h>

int main(void)
{
  unsigned int a;
  scanf("%x", &a);
  unsigned int cur = 0;
  for (int i = 0; i < 4; ++i)
  {
    unsigned int mask = (1 << (15 - i));
    for (int j = 0; j < 16; j += 4)
    {
      cur <<= 1;
      cur += ((a & mask) >> (15 - i - j));
      mask >>= 4;
    }
  }
  if (cur >> 12 == 0)
    printf("0");
  if (cur >> 8 == 0)
    printf("0");
  printf("%x", cur);
  return 0;
}
