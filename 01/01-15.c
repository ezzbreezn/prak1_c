#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2, x3, y3, xf, yf, xf2, yf2, res, flag;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    xf = x1, yf = y1, xf2 = x2, yf2 = y2, flag = 0;
    int ans = 1;
    res = (x2 - x1) * (y3 - y2)- (x3 - x2) * (y2 - y1);
    if (res > 0)
      flag = 1;
    else if (res < 0)
      flag = 0;

    for (int i = 0; i < n - 3; ++i)
    {
      x1 = x2, y1 = y2, x2 = x3, y2 = y3;
      scanf("%d %d", &x3, &y3);
      res = (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1);
      if (res > 0 && flag == 0)
        ans = 0;
      else if (res < 0 && flag == 1)
        ans = 0;
      else if (res == 0)
        ans = 0;
    }
    res = (x3 - x2) * (yf - y3) - (xf - x3) * (y3 - y2);
    if (res > 0 && flag == 0)
      ans = 0;
    else if (res <  0 && flag == 1)
      ans = 0;
    else if (res == 0)
      ans = 0;
    res = (xf - x3) * (yf2 - yf) - (xf2 - xf) * (yf - y3);
    if (res > 0 && flag == 0)
      ans = 0;
    else if (res <  0 && flag == 1)
      ans = 0;
    else if (res == 0)
      ans = 0;
    if (ans)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
}
