#include <stdio.h>
#include <string.h>

void prefix_func(int *pi, char *s, int len)
{
  pi[0] = 0;
  for (int i = 1; i < len; ++i)
  {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      ++j;
    pi[i] = j;
  }
}

int main(void)
{
  char s1[1000002], s2[1000002];
  fgets(s1, 1000002, stdin);
  fgets(s2, 1000002, stdin);
  int len1 = strlen(s1) - 1, len2 = strlen(s2) - 1;
  char s12[2000003], s21[2000003];
  strncpy(s12, s1, len1);
  s12[len1] = ' ';
  strncat(s12, s2, len2);
  strncpy(s21, s2, len2);
  s21[len2] = ' ';
  strncat(s21, s1, len1);
  int pi1[2000001], pi2[2000001];
  prefix_func(pi1, s12, len1 + len2 + 1);
  prefix_func(pi2, s21, len1 + len2 + 1);
  printf("%d %d", pi1[len1 + len2], pi2[len1 + len2]);
  return 0;
}
