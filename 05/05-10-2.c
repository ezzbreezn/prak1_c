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

void mult(char *a, char *b, char *res, long long la, long long lb, long long *lr, int s1, int s2, int *sr)
{
  if (s1 != s2)
    *sr = 0;
  --la, --lb;
  long long i = lb, start = 0;
  while (i >= 0)
  {
    long long tnum = 0, pos = i, m = 1;
    for (; pos >= i - 8 && pos >= 0; --pos)
    {
      tnum += (b[pos] - '0') * m;
      m *= 10;
    }
    long long j = la;
    long long shift = start;
    while (j >= 0)
    {
      long long ttnum = 0, pos1 = j, mm = 1;
      for(; pos1 >= j - 8 && pos1 >= 0; --pos1)
      {
        ttnum += (a[pos1] - '0') * mm;
        mm *= 10;
      }
      long long tres = tnum * ttnum;
      long long lv = 0, iter = 0;
      while (tres > 0)
      {
        long long temp = (res[shift + iter] - '0' + lv + tres % 10);
        lv = temp / 10;
        temp %= 10;
        res[shift + iter] = (char)(temp + '0');
        //if (shift + iter + 1 > *lr)
          //++*lr;
        ++iter;
        tres /= 10;
      }
      if (lv)
      {
        res[shift + iter] = (char)(lv + '0');
        //if (shift + iter + 1 > *lr)
          //++*lr;
      }
      j -= 9;
      shift += 9;
    }
    start += 9;
    i -= 9;
  }
  *lr = 20004;
}


int main(void)
{
  long long la = 0, lb = 0;
  char *a;
  char *b;
  char *res;
  long long lr = 0;
  int s1 = 1, s2 = 1, sr = 1;
  a = (char *) malloc(sizeof(char) * 10002);
  b = (char *) malloc(sizeof(char) * 10002);
  res = (char *) malloc(sizeof(char) * 20005);
  for (long long i = 0; i < 20005; ++i)
    res[i] = '0';
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
  //for (long long i = 0; i < la + lb; ++i)
    //res[i] = '0';
  if (!sign)
  {
    if (a[0] == '0')
    {
      if (!s2 && b[0] != '0')
        printf("-");
      for (long long i = 0; i < lb; ++i)
        printf("%c", b[i]);
      free(a);
      free(b);
      free(res);
      return 0;
    }
    else if (b[0] == '0')
    {
      if (!s1)
        printf("-");
      for (long long i = 0; i < la; ++i)
        printf("%c", a[i]);
      free(a);
      free(b);
      free(res);
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
      free(a);
      free(b);
      free(res);
      return 0;
    }
    else if (cmp(a, b, la, lb) == 1)
      mult(a, b, res, la, lb, &lr, s1, s2, &sr);
    else
      mult(b, a, res, lb, la, &lr, s2, s1, &sr);
  }
  long long start = lr;
  while (start >= 0 && res[start] == '0')
    --start;
  if (start == -1)
  {
    printf("0");
    free(a);
    free(b);
    free(res);
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
