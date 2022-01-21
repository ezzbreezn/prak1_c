#include <stdio.h>
#include <string.h>

void comp(int *mx, int len, int first, int res[])
{
  if (len > *mx)
  {
    *mx = len;
    for (int i = 0; i < 10; ++i)
      res[i] = 11;
    res[0] = first;
  }
  else if (len == *mx)
  {
    for (int i = 0; i < 10; ++i)
    {
      if (res[i] == first)
        break;
      else if (res[i] == 11)
      {
        res[i] = first;
        break;
      }
    }
  }
}

void maxlen(char s[10][22], int used[], int res[], int *mx, int first, int n, int temp_len, char last)
{
  int f = 0;
  for (int i = 0; i < n; ++i)
  {
    if (s[i][0] == last && !used[i])
    {
      f = 1;
      used[i] = 1;
      char nlast = s[i][strlen(s[i])-2];
      maxlen(s, used, res, mx, first, n, temp_len + 1, nlast);
      used[i] = 0;
    }
    if (!f)
      comp(mx, temp_len, first, res);
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  char cities[10][22];
  int used[10] = {};
  for (int i = 0; i < n; ++i)
  {
    fgets(cities[i], 22, stdin);
    if (cities[i][0] == '\n')
    {
      --i;
      continue;
    }
  }

  int mx = 0;
  int res[10] = {11, 11, 11, 11, 11, 11, 11, 11, 11, 11};
  for (int i = 0; i < n; ++i)
  {
    used[i] = 1;
    maxlen(cities, used, res, &mx, i, n, 1, cities[i][strlen(cities[i]) - 2]);
    used[i] = 0;
  }
  printf("%d\n", mx);
  for (int i = 0; i < 10; ++i)
  {
    if (res[i] == 11)
      break;
    printf("%s", cities[res[i]]);
  }
  return 0;
}
