#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long n, m, n0, m0, n1, m1;
	scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &n0, &m0, &n1, &m1);
	long long **map = (long long **)calloc(n, sizeof(long long *));
	for (long long i = 0; i < n; ++i)
		map[i] = (long long *)calloc(m, sizeof(long long));


	for (long long i = 0; i < n; ++i)
		free(map[i]);
	free(map);
	return 0;
}