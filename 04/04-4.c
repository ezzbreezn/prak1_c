#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[257];
  fgets(s, 257, stdin);
  int len = strlen(s);
  --len;
  //printf("%d\n", len);
  for (int temp = 0; temp < len; ++temp)
  {
    int even = 0, odd = 0;
    for (int i = 0; i < len; ++i)
    {
      if (i == temp)
        continue;
      if (i < temp && s[i] == 'A' && i % 2 == 0)
        ++odd;
      else if (i < temp && s[i] == 'A' && i % 2 != 0)
        ++even;
      else if (i > temp && s[i] == 'A' && i % 2 == 0)
        ++even;
      else if (i > temp && s[i] == 'A' && i % 2 != 0)
        ++odd;
    }
    if (odd == even)
      printf("%d ", temp + 1);

  }
  return 0;
}
