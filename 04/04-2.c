#include <stdio.h>

_Bool isvowel(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return 1;
  else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
    return 1;
  else
    return 0;
}

int main(void)
{
  int a[10000];
  int n;
  char s[102];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  getchar();
  for (int i = 0; i < n; ++i)
  {
    fgets(s, 102, stdin);
    if (s[0] == '\n')
    {
      --i;
      continue;
    }
    int j = 0, count = 0, flag = 0;
    while (s[j] != '\0')
    {
      if (isvowel(s[j]) && !flag)
      {
        ++count, flag = 1;
      }
      else if (!isvowel(s[j]))
        flag = 0;
      ++j;
    }
    if (a[i] == count)
      printf("%s", s);
  }
  return 0;
}
