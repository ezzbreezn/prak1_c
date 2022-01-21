#include <stdio.h>
int max(int a, int b)
{
  return ((a > b) ? a : b);
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int a[10000], b[10000];
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  int num = 0;
  for (int i = 0; i < n; ++i)
    num += max(a[i], b[i]);
  printf("%d", num);
  return 0;
}
