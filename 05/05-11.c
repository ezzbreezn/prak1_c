#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b)
{
	return (a > b) ? a : b;
}

long long three_max(long long a, long long b, long long c)
{
	if (a >= b && a >= c) return a;
	else if (b >= a && b >= c) return b;
	else return c;
}

int main(void)
{
	long long n, m;
	scanf("%lld%lld", &n, &m);
	long long **m1 = (long long **)calloc(n, sizeof(long long *));
	long long **m2 = (long long **)calloc(n, sizeof(long long *));
	for (long long i = 0; i < n; ++i)
	{
		m1[i] = (long long *)calloc(m, sizeof(long long));
		m2[i] = (long long *)calloc(m, sizeof(long long));
	}
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < m; ++j)
			scanf("%lld", &m1[i][j]);
	for (long long j = 0; j < m; ++j)
	{
		for (long long i = 0; i < n; ++i)
		{
			if (j == 0)
				m2[i][j] = m1[i][j];
			else
			{
				if (i == 0)
					m2[i][j] = max(m2[i][j - 1], m2[i + 1][j - 1]) + m1[i][j];
				else if (i == n - 1)
					m2[i][j] = max(m2[i][j - 1], m2[i - 1][j - 1]) + m1[i][j];
				else
					m2[i][j] = three_max(m2[i][j - 1], m2[i - 1][j - 1], m2[i + 1][j - 1]) + m1[i][j];
			}
		}
	}
	long long res = m2[0][m - 1];
	for (long long i = 1; i < n; ++i)
	{
		if (m2[i][m - 1] > res)
			res = m2[i][m - 1];
	}
	printf("%lld", res);
	for (long long i = 0; i < n; ++i)
	{
		free(m1[i]);
		free(m2[i]);
	}
	free(m1);
	free(m2);
	return 0;
}