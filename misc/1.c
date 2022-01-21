#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time
{
	int h, m, s;
};

char *sumall(short *a)
{
	char *str = (char *)malloc(8 * sizeof(short) + 1);
	//char *str[8 * sizeof(short) + 1];
	short sum = 0;
	while (*a != 0)
	{
		sum += (*a);
		++a;
	}
	//printf("%u\n", sum);
	int len = 8 * sizeof(short) - 1, i = 0;
	for (int j = 0; j < 8 * sizeof(short); ++j)
	{
		str[i] = '0' + (((sum << i) >> len) & 1);
		//printf("%u %c\n", ((sum << i) >> len) & 1, str[i]);
		//--len;
		++i;
	}
	str[i] = '\0';
	//printf("%s", str);
	return str;
}

char *equ(char *s)
{
	int len = 0, i = 0, olen = strlen(s), tot = olen;
	while (tot > 0)
	{
		if (s[i] == 'C' && i < olen - 1 && s[i + 1] == 'b')
		{
			s[i] = 'H';
			++i;
			++len;
			for (int j = i; j < olen - 1; ++j)
				s[j] = s[j + 1];
			tot -= 2;
		}
		else if (s[i] == 'H' && i < olen - 1 && s[i + 1] == 'b')
		{
			s[i] = 'B';
			++i;
			++len;
			for (int j = i; j < olen - 1; ++j)
				s[j] = s[j+ 1];
			tot -= 2;
		}
		else if (s[i] == 'F' && i < olen - 1 && s[i + 1] == 'b')
		{
			s[i] = 'E';
			++i;
			++len;
			for (int j = i; j < olen -1; ++j)
				s[j] = s[j + 1];
			tot -= 2;
		}
		else if (s[i] == 'B' && i < olen -1 && s[i + 1] == 'b')
		{
			s[i] = 'A';
			++i;
			++len;
			for (int j = i; j < olen - 1; ++j)
				s[j] = s[j + 1];
			tot -= 2;
		}
		else
		{
			++i; ++len; --tot;
		}
	}
	s = (char *)realloc(s, len + 1);
	s[len] = '\0';
	return s;
}

struct time end(struct time *t, int n)
{
	int tot = 32400;
	for (int i = 0; i < n; ++i)
	{
		tot += (t->h) * 3600 + (t -> m) * 60 + (t -> s);
		++t;
	}
	tot %= 86400;
	struct time res;
	res.s = tot % 60;
	tot /= 60;
	res.m = tot % 60;
	tot /= 60;
	res.h = tot;
	return res;
}

/*static int f(const char *s, int n)
{
	int x;
	register int k = 0;
	static char h = '9';
	if (*s == 0) return 0;
	while (*s && *s != h) ++s, k++;
	h--;
	x = f(s,((n%2) || (n++ & 4)) ? n + 1: n + 2);
	printf("%c %d %d %c\n", h, n, x, *s);
	return k;
}*/

static int m[] = {2, 0, 1, 8};
static int *p = &m[3], *q = &m[1];
int f(int a, int b)
{
	static int x = 1; int y = x;
	x = p[0]; q[0] += b;
	if (a) { p--; q++;}
	return y;
}

int main(void)
{
	//char *s = (char *)malloc(10* sizeof(char));
	/*short a[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 0};
	//char *s = sumall(a);
	unsigned b;
	b = '\01';
	unsigned aa = b;
	//b ^= b;
	//b -= (b << (sizeof(b) * 8 - 1)) ? b : 0;
	if (aa & 1) b = '\0';
	unsigned y = 3, x = 0;
	switch(x)
	{
		case 0:
		default:  y = y + y;
	}*/
	//char a[][10]={{'a','b','0','c'}, "Kinnersley"};
	//char (*p)[10] = a+1,(*q)[10];
	enum{A=1000, D,C=4};
	struct{short sh[1];unsigned n;}s={}, *ps = &s;

	//printf("%u", b);
	//printf("%s", s);
	//fgets(s, 10, stdin);
	//s = equ(s);
	//struct time t[] = {{3, 40, 20}, {20, 3, 0}, {10, 30, 20}};
	//struct time res = end(t, 3);
	//printf("%d %d %d", res.h, res.m, res.s);
	//printf("%s", s);
	//printf("%d %d\n", f(1, f(f(0, 1), 2)), y);
	//printf("%u", s.sh[0]);
	//printf("%d", -49957 % 10);
	/*int a[] = {1, 2, 3, 4, 0, 6, 7};
	int n = 6;
	do
	{
		printf("%d\n", a[n]);
		if (a[n] < 0) break;
		if (a[n] == 0) continue;
		a[n]--;
	}while (n-- != 0);
	for (int i = 0; i < 7; ++i)
		printf("%d ", a[i]);*/
	int y = -10;
	y >>= 3;
	printf("%d", y);
	return 0;
	//return f("4376598347983245", 1);
}