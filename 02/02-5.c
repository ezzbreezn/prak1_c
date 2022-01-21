#include <stdio.h>

int main(void)
{
  double x[100], y[100], z[100], r[100];
  int n;
  scanf("%d", &n);
  int f = 0;
  for (int i = 0; i < n; ++i)
    scanf("%lf %lf %lf %lf", &x[i], &y[i], &z[i], &r[i]);
  for (int i = 0; i < n && !f; ++i)
  {
    for (int j = i + 1; j < n && !f; ++j)
    {
      double dist_x = (x[i] - x[j]) * (x[i] - x[j]);
      double dist_y = (y[i] - y[j]) * (y[i] - y[j]);
      double dist_z = (z[i] - z[j]) * (z[i] - z[j]);
      double dist_r = (r[i] + r[j]) * (r[i] + r[j]);
      if (dist_x + dist_y + dist_z <= dist_r)
      {
        printf("YES\n");
        f = 1;
      }
    }
  }
  if (!f)
    printf("NO\n");
  return 0;
}
