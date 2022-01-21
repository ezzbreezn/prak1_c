#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[2000002];
  fgets(s, 2000002, stdin);
  int len = strlen(s) - 1;
  char ds[4000002];
  strncpy(ds,s, len);
  strncat(ds,s, len);
  int i = 0, start = 0;
  while (i < len)
  {
    start = i;
    int j = i + 1, temp = i;
    while (j < 2 * len && ds[temp] <= ds[j])
    {
      if (ds[temp] == ds[j])
        ++temp;
      ++j;
    }
    while (i <= temp)
      i += j - temp;
  }
  char res[2000];
  strncpy(res, ds + start, len);
  printf("%s", res);
  return 0;
}
