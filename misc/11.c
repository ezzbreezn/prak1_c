#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#define wr(x,y) printf("%d\n", a[y##x]++);
int main(void)
{
	static int a[9] = {[1] = 2, -4, 2, [5] = 1};
	int ab = 8, ac = 4, ba = 2;
	static int ca = 7, bc = 1, cb = 5;
	wr(a,b);
	wr(c,a);
	if(--cb>3) return main();
	return 0;
}*/

unsigned rright(unsigned x)
{
	int k = 0;
	for (int i = 0; i < 31; ++i)
	{
		if (x & (1 << i)) ++k;
	}
	for(int i = 0; i < k; ++i)
	{
		int temp = x & 1; x >>= 1;x |= ((1 << 31) * temp);
	}
	return x;
}

	static int x[5] = {3,0,3,2};

int f(int a, int b)
{
	static int *p=&x[0],*q=&x[4];
	if(*p - *q > a)
		*p++ = b;
	else if (*p - *q < a)
		*q-- = b;
	return q - p;
}

int bins (char *s)
{
	int k = 0, i = 0;
	while (i < strlen(s))
	{
		int a= 0, b = 0;
		while (i < strlen(s) && s[i] != '+')
		{
			if(s[i] == '0') ++a;
			else ++b;
			++i;
		}
		if (b > a) ++k;
		++i;
	}
	return k;
}

char **split(char *s)
{
	int i= 0, len = 0, start;
	char **res = NULL;
	while (i < strlen(s))
	{
		start = i;
		while(i < strlen(s) && s[i] != ';') ++i;
		if (start != i)
		{
			++len;
			res = (char **)realloc(res, sizeof(char *) * len);
			res[len - 1] = (char *)malloc(sizeof(char)*(i - start + 1));
			strncpy(res[len - 1], s + start, i - start);
			res[len - 1][i - start] = '\0';
		}
		++i;
	}
	if (start != i)
	{
		++len;
		res = (char **)realloc(res, sizeof(char *) * len);
		res[len - 1] = (char *)malloc(sizeof(char)*(i - start + 1));
		strncpy(res[len - 1], s + start, i - start);
		res[len - 1][i - start] = '\0';
	}
	res = (char **)realloc(res, sizeof(char *)*(len + 1));
	res[len - 1] = NULL;
	return res;
}

int main(void)
{
	char s[100];
	scanf("%s", s);
	char **res = split(s);
	while (*res != NULL)
	{
		printf("%s\n", *res);
		++res;
	}
	//printf("%d\n" , f(-2,f(f(2,1),2)));
	//printf("%d %d %d %d %d", x[0], x[1], x[2], x[3], x[4]);
	return 0;
}