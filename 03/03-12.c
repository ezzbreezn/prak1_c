#include <stdio.h>

int main(void)
{
  int sums[20000] = {};
  int a[14];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  int mx = 0;
  for (int mask = 0; mask < (1 << n); ++mask)
  {
    int temp = 0;
    for (int i = 0; i < n; ++i)
      if (mask & (1 << i))
        temp += a[i];
    sums[mask] = temp;
    for (int j = 0; j < (1 << n); ++j)
    {
      if (sums[j] == temp && j != mask &&  !(j & mask))
      {
        if (sums[mask] > mx)
          mx = temp;
      }
    }
  }
  printf("%d", mx);
  return 0;
}
