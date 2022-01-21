#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned sects (char *s)
{
  unsigned fst = 0, scd = 0;
  char *t = strtok(s, " ");
  while (t != NULL)
  {
    //printf("%s\n",t);
    char str1[100], str2[100];
    int len = 0;
    char *p = t;
    for (int i = 0; i < strlen(t); ++i)
    {
      if (t[i] == '.')
      {
        strncpy(str1, t, len);
        strcpy(str2, ++p);
        break;
      }
      else
      {
        ++len;
        ++p;
      }
    }
    if (atoi(str1) > fst)
      fst = atoi(str1);
    if (atoi(str2) > scd)
      scd = atoi(str2);
    t = strtok(NULL, " ");
  }
  //printf("%u %u\n", fst, scd);
  fst <<= 16;
  return fst + scd;
}

int main(void)
{
  char s[100];
  int c, i;
  scanf("%[^\n]s",s);
  unsigned res = sects(s);
  printf("%u", res);
  return 0;
}
