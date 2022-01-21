#include <stdio.h>

int gcd(int a, int b)
{
  if (a < b)
  {
    int temp;
    temp = a, a = b, b = temp;
  }
  while (b > 0)
  {
    int temp;
    temp = a % b, a = b, b = temp;
  }
  return a;
}

int main(void)
{
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int res = gcd(a, b);
  res = gcd(res, c);
  res = gcd(res, d);
  printf("%d", res);
  return 0;
}
