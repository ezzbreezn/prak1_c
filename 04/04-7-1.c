#include <stdio.h>
#include <string.h>

void maxcomp(int first, int *res, int len, int *mx)
{
  if (len == *mx)
  {
    for (int i = 0; i < 10; ++i)
    {
      if (res[i] == first)
        break;
      else if (res[i] == -1)
      {
        res[i] = first;
        break;
      }
    }
  }
  else if (len > *mx)
  {
    *mx = len;
    for (int i = 0; i < 10; ++i)
      res[i] = -1;
    res[0] = first;
  }
  else
    return;
}

void dfs(int pos, int first, int *mx, char s[10][22], int used[], int *res, int n, int len)
{
  used[pos] = 1;
  int f = 0;
  for (int i = 0; i < n; ++i)
  {
    if (!used[i] && s[pos][strlen(s[pos]) - 2] == s[i][0])
    {
      f = 1;
      dfs(i, first, mx, s, used, res, n, len + 1);
      used[i] = 0;
    }
  }
  if (!f)
    maxcomp(first, res, len, mx);
}

int main(void)
{
  char cities[10][22];
  int mx = 0;
  int res[10];
  for (int i = 0; i < 10; ++i)
    res[i] = -1;
  int n;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; ++i)
    fgets(cities[i], 22, stdin);
  for (int i = 0; i < n; ++i)
  {
    int used[10] = {};
    dfs(i, i, &mx, cities, used, res, n, 1);
  }
  printf("%d\n", mx);
  for (int i = 0; i < n; ++i)
  {
    if (res[i] != -1)
      printf("%s", cities[res[i]]);
    else
      break;
  }
  return 0;
}
