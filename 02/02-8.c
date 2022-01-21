#include <stdio.h>

int main(void)
{
  int a[4000];
  int n;
  scanf("%d", &n);
  int num = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i <= n - 3; ++i)
  {
    for (int k = i + 1, j = i + 2; j < n; ++k, j += 2)
    {
      if ((a[i] + a[j]) % 2 == 0 && a[k] == (a[i] + a[j]) / 2)
        ++num;
    }
  }
  printf("%d", num);
  return 0;
}
