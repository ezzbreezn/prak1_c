#include <stdio.h>
unsigned sects (char *s)
{
  unsigned fst = 0, scd = 0;
  int i = 0;
  while ('0' <= s[i] && s[i] <='9')
  {
    unsigned temp1 = 0;
    while ('0' <= s[i] && s[i] <= '9')
    {
      temp1 = temp1 * 10 + s[i] - '0';
      ++i;
    }
    ++i;
    if (temp1 > fst)
      fst = temp1;
    unsigned temp2 = 0;
    while ('0' <= s[i] && s[i] <= '9')
    {
      temp2 = temp2 * 10 + s[i] - '0';
      ++i;
    }
    ++i;
    if (temp2 > scd)
      scd = temp2;
  }
  fst <<= 16;
  return fst + scd;
}

int main(void)
{
  char s[100];
  scanf("%[^\n]s", s);
  printf("%u", sects(s));
  return 0;
}
