#include <stdio.h>
#include <stdlib.h>

long long **matrmult(long long **m, long long k, long long deg, long long p)
{
	if (deg == 1)
		return m;
	if (deg % 2 != 0)
	{
		long long **a = matrmult(m, k, deg - 1, p);
		long long **res = (long long **)malloc(sizeof(long long *) * 10);
		for (long long i = 0; i < 10; ++i)
			res[i] = (long long *)malloc(sizeof(long long)*10);
		long long temp[10][10];
		for (long long i = 0; i < k; ++i)
			for (long long j = 0; j < k; ++j)
				temp[i][j] = m[i][j];
		for (long long i = 0; i < k; ++i)
		{
			for (long long j = 0; j < k; ++j)
			{
				res[i][j] = 0;
				for (long long t = 0; t < k; ++t)
				{
					res[i][j] += (temp[i][t] % p) * (a[t][j] % p);
					res[i][j] %= p;
				}
			}
		}
		return res;
	}
	else
	{
		long long **a = matrmult(m, k, deg / 2, p);
		long long **res = (long long **)malloc(sizeof(long long *) * 10);
		for (long long i = 0; i < 10; ++i)
			res[i] = (long long *)malloc(sizeof(long long)*10);
		long long temp[10][10];
		for (long long i = 0; i < k; ++i)
			for (long long j = 0; j < k; ++j)
				temp[i][j] = a[i][j];
		for (long long i = 0; i < k; ++i)
		{
			for (long long j = 0; j < k; ++j)
			{
				res[i][j] = 0;
				for (long long t = 0; t < k; ++t)
				{
					res[i][j] += (a[i][t] % p) * (temp[t][j] % p);
					res[i][j] %= p;
				}
			}
		}
		return res;

	}
}


int main(void)
{
	long long n, k, p;
	long long *f, *a;
	a = (long long *) malloc(sizeof(long long) * 10);
	f = (long long *) malloc(sizeof(long long) * 10);
	scanf("%lld%lld%lld", &k, &n, &p);
	for (long long i = 0; i < k; ++i)
		scanf("%lld", &f[i]);
	for (long long i = 0; i < k; ++i)
		scanf("%lld", &a[i]);
	long long deg = n - k;
	long long **m;
	long long **res;
	m = (long long **) malloc(sizeof(long long *) * 10);
	res = (long long **) malloc(sizeof(long long *) * 10);
	for (long long i = 0; i < 10; ++i)
	{
		m[i] = (long long *) malloc(sizeof(long long) * 10);
		res[i] = (long long *) malloc(sizeof(long long) * 10);
		for (long long j = 0; j < 10; ++j)
		{
			m[i][j] = 0;
		}
	}
	for (long long i = 0; i < k; ++i)
	{
		m[0][i] = a[i];
	}
	for (long long i = 0; i < k - 1; ++i)
	{
		m[i + 1][i] = 1;
	}
	if (n <= k)
	{
		printf("%lld", f[n - 1] % p);
		return 0;
	}
	res = matrmult(m, k, deg, p);
	long long sum = 0;
	for (long long i = 0; i < k; ++i)
	{
		sum += (res[0][i] % p) * (f[k - i - 1] % p);
		sum %= p;
	}
	printf("%lld", sum);
	for (long long i = 0; i < 10; ++i)
	{
		free(m[i]);
		free(res[i]);
	}
	free(m);
	free(res);
	free(a);
	free(f);
	return 0;
}