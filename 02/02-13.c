#include <stdio.h>

int main(void)
{
  int front[8];
  int right[8];
  int used[8] = {};
  for (int i = 0; i < 8; ++i)
    scanf("%d", &front[i]);
  for (int i = 0; i < 8; ++i)
    scanf("%d", &right[i]);
  for (int i = 0; i < 8; ++i)
  {
    if (right[i] == 0)
      used[i] = 1;
  }
  int num = 0;
  for (int i = 0; i < 8; ++i)
  {
    if (front[i] == 0)
      continue;
    int f = 0;
    for (int j = 0; j < 8 && !f; ++j)
    {
      if (front[i] == right[j] && !used[j])
      {
        num += front[i];
        used[j] = 1;
        f = 1;
      }
    }
    if (!f)
    {
        for (int j = 0; j < 8 && !f; ++j)
        {
          if (front[i] <= right[j] && used[j])
          {
            num += front[i];
            used[j] = 1;
            f = 1;
          }
        }
    }
    if (!f)
    {
        for (int j = 0; j < 8 && !f; ++j)
        {
          if (front[i] <= right[j] && !used[j])
          {
            num += front[i];
            f = 1;
          }
        }
    }
    if (!f)
    {
      printf("-1");
      return 0;
    }
  }
  int check = 1;
  for (int i = 0; i < 8 && check; ++i)
  {
    if (!used[i])
      check = 0;
  }
  if (!check)
    printf("-1");
  else
    printf("%d", num);
  return 0;
}
