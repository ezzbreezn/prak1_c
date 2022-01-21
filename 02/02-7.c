#include <stdio.h>

int main(void)
{
  int a[10000] = {};
  int n;
  scanf("%d", &n);
  int temp = -1;
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &temp);
    ++a[temp - 1];
  }
  int f = 1;
  for (int i = 0; i < n && f; ++i)
  {
    if (a[i] != 1)
    {
      printf("No\n");
      f = 0;
    }
  }
  if (f)
    printf("Yes\n");
  return 0;
}
