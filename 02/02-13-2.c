#include <stdio.h>

int main(void)
{
  int front[8], right[8];
  int used[8] = {};
  for (int i = 0; i < 8; ++i)
    scanf("%d", &front[i]);
  for (int i = 0; i < 8; ++i)
    scanf("%d", &right[i]);
  for (int i = 0; i < 8; ++i)
  {
    if(right[i] == 0)
      used[i] = 1;
  }
  int num = 0;
  for (int i = 0; i < 8; ++i)
  {
    if (front[i] == 0)
      continue;
    int f = 0;
    for (int j = 0; j < 8; ++j)
    {
      if (front[i] == right[j] && !used[j])
      {
        num += front[i];
        f = 1;
        used[j] = 1;
        break;
        //if (!used[j])
         // used[j] = 1;
      }
    }
    if (!f)
    {
      for (int j = 0; j < 8; ++j)
      {
        if (front[i] < right[j] && used[j])
        {
          num += front[i];
          f = 1;
          break;
        }
      }
    }
    if (!f)
    {
      printf("-1");
      return 0;
    }
  }
  int check = 0;
  for (int i = 0; i < 8; ++i)
  {
    if (used[i] == 0)
    {
      ++check;
    }
  }
  if (!check)
  {
    printf("%d", num);
    return 0;
  }
  else
  {
    for (int i = 0; i < 8 && check; ++i)
    {
      if (front[i] == 0)
        continue;
      for (int j = 0; j < 8 && check; ++j)
      {
        if (front[i] == right[j] && !used[j])
        {
          num += front[i];
          used[j] = 1;
          --check;
        }
      }
    }
  }
  if (check)
    printf("-1");
  else
    printf("%d", num);
  return 0;
}
