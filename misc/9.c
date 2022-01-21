#include <stdio.h>
#include <stdlib.h>
#define SUM(x, y) (a##x + a##y)

enum sas
{
	red, orange = 23, yellow = 23, green, cyan = 75, blue = 75, violet
};

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int fbn(int n)
{
	if (n ==1 || n == 2) return 1;
	else
	{
		int g, h, k, fb;
		g =h =1;
		for (k = 2; k < n; ++k)
		{
			fb = g + h;
			h = g;
			g = fb;
		}
		return fb;
	}
}
int main(void)
{
	//enum sas s;
	int a1 = 2, a2 = 8;
	//int x = fbn(13);
	int x  = gcd(342, 86);
	printf("%d", x);
	//printf("%d %d %d %d %d %d %d ", red, orange, yellow, green, cyan, blue, violet);
	//printf("%d", SUM(1, 2));
	return 0;
}