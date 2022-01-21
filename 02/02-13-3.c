#include <stdio.h>

int main(void)
{
  int a[8][8] = {};
  int front[8] ,front1[8], right[8], right1[8];
  for (int i = 0; i < 8; ++i)
  {
    int temp;
    scanf("%d", &temp);
    front[i] = temp, front1[i] = temp;
  }

  for (int i = 0; i < 8; ++i)
  {
    int temp;
    scanf("%d", &temp);
    right[i] = temp, right1[i] = temp;

  }
  for (int i = 0; i < 8; ++i)
  {
    if (front[i] == 0)
      continue;
    for (int j = 0; j < 8; ++j)
    {
      if (front[i] == right[j])
      {
        a[j][i] = front[i];
        front[i] = 0;
        right[j] = 0;
        break;
      }
    }
  }
  for (int i = 0; i < 8; ++i)
  {
    if (right[i] == 0)
      continue;
    for (int j = 0; j < 8; ++j)
    {
      if (right[i] <= front1[j] && front[j] == 0)
      {
        a[i][j] = right[i];
        right[i] = 0;
        break;
      }
    }
  }
  for (int i = 0; i < 8; ++i)
  {
    if (front[i] == 0)
      continue;
    for (int j = 0; j < 8; ++j)
    {
      if (front[i] <= right1[j] && right[j] == 0)
      {
        a[j][i] = front[i];
        front[i] = 0;
        break;
      }
    }
  }
  int s1 = 0, s2 = 0;
  for (int i = 0; i < 8; ++i)
  {
    s1 += front[i];
    s2 += right[i];
  }
  if (s1 != 0 || s2 !=0)
  {
    printf("-1");
    return 0;
  }
  else
  {
    int res = 0;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        res += a[i][j];
    printf("%d", res);
  }
  return 0;
}
