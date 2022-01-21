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
  int n;
  scanf("%d", &n);
  int dd = 0, dr = 0, f = 0;
  for (int i = 0; i < n; ++i)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    if (!f)
    {
      dd = a, dr = b, f = 1;
    }
    else
    {
      if (dr > b && dr % b == 0)
      {
        a *= (dr / b);
        dd += a;
      }
      else if (b < dr && b % dr == 0)
      {
        dd *= (b / dr);
        dd += a;
        dr = b;
      }
      else
      {
        dd *= b;
        dd += (a * dr);
        dr *= b;
      }
    }
  }
  int x, y, z;
  x = dd / dr;
  dd %= dr;
  y = dd, z = dr;
  int g = gcd(y,z);
  y /= g, z /= g;
  printf("%d %d %d\n", x, y, z);
  return 0;
}
