#include <stdio.h>
#include <string.h>

int main(void)
{
  int k;
  char s[1000002];
  scanf("%d", &k);
  getchar();
  fgets(s, 1000002, stdin);
  char temp[1000002];
  int i = 0, start = 0, end = -1;
  while (i < strlen(s) - 1)
  {
    int wc = 0, len = 0, c = 0, av = 0, lv = 0;
    while (c < k && s[i + c] != '\n')
    {
      if (s[i + c] == ' ')
      {
        ++wc, len += (end - start + 1);
      }
      else if (s[i + c] != ' ' && s[i + c - 1] == ' ')
      {
        start = i + c; end = start;
      }
      else
        end = i + c;
      ++c;
    }
    if (s[i + c] == ' ' || s[i + c] == '\n')
    {
      ++wc, len += (end - start + 1), start = i + c + 1;
    }
    else if (s[i + c] != ' ' && s[i + c - 1] == ' ')
      start = i + c;
    if (wc == 1)
      av = k - len;
    else
      av = (k - len) / (wc - 1), lv = (k - len) % (wc - 1);
    end = start - 1;
    int tt = 0;
    for (int t = 0; t < start - i; ++t)
    {
      if (s[i + t] != ' ' && s[i + t] != '\n')
      {
        temp[tt] = s[i + t], ++tt;
      }
      else
      {
        for (int j = 0; j < av + (lv != 0) && tt < k; ++j)
        {
          temp[tt] = ' ', ++tt;
        }
        if (lv != 0)
          --lv;
      }
    }
    if (tt < k)
    {
      for (; tt < k; ++tt)
        temp[tt] = ' ';
    }
    temp[k] = '\n';
    temp[k + 1] = '\0';
    printf("%s", temp);
    i = start;
  }
  return 0;
}
