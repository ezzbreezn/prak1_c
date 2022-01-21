#include <stdio.h>
#include <stdlib.h>

int cmp(char *a, char *b, long long la, long long lb)
{
  if (la > lb)
    return 1;
  else if (la < lb)
    return -1;
  else
  {
    long long i;
    for (i = 0; i < la; ++i)
    {
      if (a[i] > b[i])
        return 1;
      else if (b[i] > a[i])
        return -1;
    }
    return 1;
  }
}

void sum(char *a, char *b, char *res, long long la, long long lb, long long *lr, int s1, int s2, int *sr)
{
  --la, --lb;
  if ((s1 && s2) || (!s1 && !s2))
  {
    if (!s1 && !s2)
      *sr = 0;
    long long lv = 0;
    while (la >= 0 && lb >= 0)
    {
      long long temp = (a[la] - '0' + b[lb] - '0' + lv);
      lv = temp / 10;
      temp %= 10;
      res[*lr] = (char)(temp + '0');
      --la, --lb, ++*lr;
    }
    while (la >= 0)
    {
      long long  temp = (a[la] - '0' + lv);
      lv = temp / 10;
      temp %= 10;
      res[*lr] = (char)(temp + '0');
      --la, ++*lr;
    }
    if (lv)
    {
      res[*lr] = (char)(lv + '0');
      ++*lr;
    }
  }
  else if ((!s1 && s2) || (s1 && !s2))
  {
    *sr = s1;
    long long lv = 0;
    while (la >= 0 && lb >= 0)
    {
      long long temp = (a[la] - b[lb] - lv);
      if (temp >= 0)
      {
        res[*lr] = (char)(temp + '0');
        lv = 0;
        --la, --lb, ++*lr;
      }
      else
      {
        temp += 10;
        res[*lr] = (char)(temp + '0');
        lv = 1;
        --la, --lb, ++*lr;
      }
    }
    while (la >= 0)
    {
      long long temp = (a[la] - '0' - lv);
      if (temp >= 0)
      {
        res[*lr] = (char)(temp + '0');
        lv = 0;
        --la, ++*lr;
      }
      else
      {
        temp += 10;
        res[*lr] = (char)(temp + '0');
        lv = 1;
        --la, ++*lr;
      }
    }
  }
}

/*void revsum(char *a, char *res, long long la, long long *lr)
{
  long long lv = 0;
  long long i = 0;
  while (i < *lr && i < la)
  {
    long long temp = (res[i] - '0' + a[i] - '0' + lv);
    lv = temp / 10;
    temp %= 10;
    res[i] = (char)(temp + '0');
    ++i;
  }
  if (i == la)
  {
    while (i < *lr)
    {
      if (!lv)
        break;
      long long temp = (res[i] - '0' + lv);
      lv = temp / 10;
      temp %= 10;
      res[i] = (char)(temp + '0');
      ++i;
    }
    if (lv)
    {
      res[*lr] = (char)(lv + '0');
      ++*lr;
    }
  }
  else
  {
    while (i < la)
    {
      long long temp = (a[i] - '0' + lv);
      lv = temp / 10;
      temp %= 10;
      res[*lr] = (char)(temp + '0');
      ++*lr, ++i;
    }
    if (lv)
    {
      res[*lr] = (char)(lv + '0');
      ++*lr;
    }
  }
}*/

void mult(char *a, char *b, char *res, long long la, long long lb, long long *lr, int s1, int s2, int *sr)
{
  if (s1 != s2)
    *sr = 0;
  --la, --lb;
  long long start = 0;
  for (long long i = lb; i >= 0; --i)
  {
    if (b[i] == '0')
    {
      ++start;
      continue;
    }
    long long lv = 0, lv1 = 0, pos = 0;
    long long j;
    for (j = la; j >=0; --j)
    {
      long long temp = (b[i] - '0') * (a[j] - '0') + lv;
      lv = temp / 10;
      temp %= 10;
      long long temp1 = (res[start + pos] - '0' + temp) +  lv1;
      lv1 = temp1 / 10;
      temp1 %= 10;
      res[start + pos] = (char)(temp1 + '0');
      if (start + pos + 1 > *lr)
        ++*lr;
      ++pos;
    }
    if (lv || lv1)
    {
      long long lv2 = 0, last = lv + lv1;
      if (last < 10)
      {
        res[start + pos] = (char)(last + '0');
        if (start + pos + 1 > *lr)
          ++*lr;
      }
      else
      {
        lv2 = last / 10;
        last %= 10;
        res[start + pos] = (char)(last + '0');
        if (start + pos + 1 > *lr)
          ++*lr;
        res[start + pos + 1] = (char)(lv2 + '0');
        if (start + pos + 2 > *lr)
          ++*lr;
      }
    }
    ++start;
  }
}
/*void mult(char *a, char *b, char *res, long long la, long long lb, long long *lr, int s1, int s2, int *sr)
{
  if (s1 != s2)
    *sr = 0;
  --la, --lb;
  char *ts;
  ts = (char *)malloc(sizeof(char) * 20000);
  for (long long i = lb; i >= 0; --i)
  {
    long long lt = 0;
    for (; lt < lb - i + 1; ++lt)
      ts[lt] = '0';
    long long lv = 0;
    for (long long j = la; j >= 0; --j)
    {
      long long temp = (b[i] - '0') * (a[j] - '0') + lv;
      lv = temp / 10;
      temp %= 10;
      ts[lt] = (char)(temp + '0');
      ++lt;
    }
    if (lv)
    {
      ts[lt] = (char)(lv + '0');
      ++lt, lv = 0;
    }
    revsum(ts, res, lt, lr);
  }
  free(ts);
}*/

int main(void)
{
  long long la = 0, lb = 0;
  char *a;
  char *b;
  char *res;
  long long lr = 0;
  int s1 = 1, s2 = 1, sr = 1;
  a = (char *) malloc(sizeof(char) * 10000);
  b = (char *) malloc(sizeof(char) * 10000);
  res = (char *) malloc(sizeof(char) * 20000);
  //res[0] = '1', res[1] = '1';
  //for (long long i = 0; i < 20000; ++i)
    //res[i] = '0';
  char t;
  scanf("%c", &t);
  if (t == '-')
    s1 = 0;
  while (!(t >= '0' && t <= '9'))
    scanf("%c", &t);
  while (t >= '0' && t <= '9')
  {
    a[la] = t;
    ++la;
    scanf("%c", &t);
  }
  long long sign = 0;
  if (t == '*')
  {
    sign = 1;
    scanf("%c", &t);
    if (t == '-')
      s2 = 0;
    else
    {
      b[lb] = t;
      ++lb;
    }
  }
  else if (t == '+')
    s2 = 1;
  else if (t == '-')
    s2 = 0;
  scanf("%c", &t);
  while (t >= '0' && t <= '9')
  {
    b[lb] = t;
    ++lb;
    scanf("%c", &t);
  }
  for (long long i = 0; i < la + lb; ++i)
    res[i] = '0';
  if (!sign)
  {
    if (a[0] == '0')
    {
      if (!s2 && b[0] != '0')
        printf("-");
      for (long long i = 0; i < lb; ++i)
        printf("%c", b[i]);
      return 0;
    }
    else if (b[0] == '0')
    {
      if (!s1)
        printf("-");
      for (long long i = 0; i < la; ++i)
        printf("%c", a[i]);
      return 0;
    }
    else if (cmp(a, b, la, lb) == 1)
      sum(a, b, res, la, lb, &lr, s1, s2, &sr);
    else 
      sum(b, a, res, lb, la, &lr, s2, s1, &sr);
  }
  else
  {
    if (a[0] == '0' || b[0] == '0')
    {
      printf("0");
      return 0;
    }
    else if (cmp(a, b, la, lb) == 1)
      mult(a, b, res, la, lb, &lr, s1, s2, &sr);
    else
      mult(b, a, res, lb, la, &lr, s2, s1, &sr);
  }
  long long start = lr - 1;
  while (start >= 0 && res[start] == '0')
    --start;
  if (start == -1)
  {
    printf("0");
    return 0;
  }
  if (!sr)
    printf("-");
  for (long long i = start; i >= 0; --i)
    printf("%c", res[i]);
  free(a);
  free(b);
  free(res);
  return 0;
}
