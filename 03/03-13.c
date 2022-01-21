#include <stdio.h>

void seq (int k, int n)
{
  int t, a[14];
  for (int i = 0; i < k; ++i)
    a[i] = i;
  while (1)
  {
    for (int i = 0; i < k; ++i)
      printf("%d ", a[i]);
    printf("\n");
    if (a[k - 1] < n - 1)
    {
      ++a[k - 1];
    }
    else
    {
      for (t = k - 1; t > 0; --t)
      {
        if (a[t] - a[t - 1] > 1)
          break;
      }
      if (t == 0)
        break;
      ++a[t - 1];
      for (int i = t; i < k; ++i)
        a[i] = a[i - 1] + 1;
    }
  }
}

int main(void)
{
  int n, k;
  scanf("%d %d", &n, &k);
  seq(k, n);
  return 0;
}
