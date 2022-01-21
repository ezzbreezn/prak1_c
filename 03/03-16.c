#include <stdio.h>

long long max (long long a, long long b)
{
  if (a > b)
    return a;
  else
    return b;
}

long long pw(long long a, long long p)
{
  if (p == 1)
    return a;
  if (p % 2 == 0)
    return pw(a, p / 2) * pw (a, p / 2);
  else
    return pw(a, p - 1) * a;
}

long long bin_pow(long long a, long long p, long long m)
{
  if (p == 1)
    return a % m;
  if (p % 2 == 0)
    return ((bin_pow(a, p / 2, m) % m) * (bin_pow(a, p / 2, m) % m)) % m;
  else
    return ((bin_pow(a, p - 1, m) % m) * (a % m)) % m;
}

int main(void)
{
  long long a, b, c, m;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &m);
  long long mx = -1;
  long long res= bin_pow(a, pw(b, c), m);
  mx = max(res, mx);
  res = bin_pow(a, pw(c, b), m);
  mx = max(res, mx);
  res = bin_pow(b, pw(a, c), m);
  mx = max(res, mx);
  res = bin_pow(b, pw(c, a), m);
  mx = max(res, mx);
  res = bin_pow(c, pw(a, b), m);
  mx = max(res, mx);
  res = bin_pow(c, pw(b, a), m);
  mx = max(res, mx);
  printf("%lld", mx);
  return 0;
}
