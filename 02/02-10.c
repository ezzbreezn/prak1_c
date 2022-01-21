#include <stdio.h>
#include <math.h>

int main(void)
{
  int n;
  double s[100], a[100];
  scanf("%d", &n);
  double time = 0, v1 = 0, v2 = 0;
  for (int i = 0; i < n; ++i)
    scanf("%lf", &s[i]);
  for (int i = 0; i < n; ++i)
    scanf("%lf", &a[i]);
  for (int i = 0; i < n; ++i)
  {
    v2 = sqrt(2 * a[i] * s[i] + v1 * v1);
    time += ((v2 - v1) / a[i]);
    v1 = v2;
  }
  printf("%.4lf", time);
  return 0;
}
