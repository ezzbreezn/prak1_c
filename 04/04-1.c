#include <stdio.h>
#include <string.h>
void pref_func(int *pi, char *s, int n)
{
  pi[0]=0;
  for(int i=1;i< n;++i)
  {
    int j =pi[i-1];
    while(j>0&&s[i]!=s[j])
    {
      j=pi[j-1];
    }
    if(s[i]==s[j])
      ++j;
    pi[i]=j;
  }
}

int main(void)
{
    char s1[10002], s2[10002];
    int pi1[20004];
    int pi2[20004];
    char s12[20004], s21[20004];
    fgets(s1, 10002, stdin);
    fgets(s2, 10002, stdin);
    int l1 = strlen(s1), l2=strlen(s2);
    --l1,--l2;
    strncpy(s12,s1,l1);
    s12[l1]=' ';
    strncat(s12,s2,l2);
    strncpy(s21,s2,l2);
    s21[l2]=' ';
    strncat(s21,s1,l1);
    pref_func(pi1, s12, l1 + l2 + 1);
    pref_func(pi2, s21, l1 + l2 + 1);
    printf("%d %d", pi1[l1 + l2], pi2[l1 + l2]);
    return 0;
}
