#include <stdio.h>
#include <string.h>

unsigned short sumall(char *s)
{
	int n = strlen(s)/(8 * sizeof(unsigned short));
	unsigned short res = 0;
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		int len = 8 * sizeof(unsigned short) - 1;
		for (int k = 0; k < 8 * sizeof(unsigned short); ++k)
		{
			res += (unsigned short)((s[j]-'0')*(1<<len));
			printf("---%c---\n", s[j]);
			printf("%hu\n", (unsigned short)((s[j]-'0')*(1<<len)) );
			--len, ++j;
		}
	}
	return res;

}

static long g(const char *s, int k)
{
	long x;
	register int i = 0;
	static char c = 'a';
	if (*s == 0) return 0;
	do
		i++, ++s;
	while (*s && *s != c);
	c++;
	x = g(s, ((k & 2)&&(--k%3)) ? k + 5: k + 7);
	printf("%c %d %ld\n", c, k, x);
	return k;
}

int main(void)
{
	//char s[] = "111000000100110000000000100001101000001010100001";
	char s[] = "1111";
	unsigned short ans = sumall(s);
	printf("%hu\n", ans);
	//if (s[strlen(s)] == '\0') printf("sas");
	/*char *ss[] = {"blue", "jay", "way"};
	struct S
	{
		char *s;
		struct S *n;
	} s[] = {{ss[0], &s[1]}, {ss[2], &s[0]}};
	printf("%d", s[1].n - s[0].n);
	return 0;*/
	//return g("pgbkdacazbcabse",2);
	return 0;
}