#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[2000002], ds[4000002], res[2000002];
  fgets(s, 2000002, stdin);
  int len = strlen(s) - 1, mx = 0;
  strncpy(ds, s, len);
  strncat(ds, s, len);
  for (int i = 0; i < len; ++i)
  {
    if (ds[i] == '0')
    {
      int j = 0;
      for (j = 0; j < len; ++j)
      {
        if (ds[i + j] > ds[mx + j])
          break;
        else if (ds[i + j] < ds[mx + j])
        {
          mx = i;
          break;
        }
      }
    }
  }
  strncpy(res, ds + mx, len);
  printf("%s", res);
  return 0;
}
