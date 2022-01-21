#include <stdio.h>

int main(void)
{
  int n;
  scanf("%d", &n);
  int a[10000];
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  int res[10000];
  for (int i = 0; i < n; ++i)
    res[i] = a[a[a[i] - 1] - 1];
  for (int i = 0; i < n; ++i)
    printf("%d ", res[i]);
  return 0;
}
