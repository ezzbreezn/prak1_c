#include <stdio.h>
#include <stdlib.h>

void qssort(int *a, int left, int right, int comp)
{
	int tmp, i = left, j = right;
	do
	{
		while(a[i]< comp && i < right) ++i;
		while(a[j]> comp && j > left) --j;
		if (i<= j)
		{
			tmp = a[j],a[j] = a[i], a[i] = tmp, ++i, --j;
		}
	}while(i<= j);
	if (left < j) qssort(a, left, j, comp);
	if (i < right) qssort(a, i, right, comp);
}

int main(void)
{
	int a[] = {6, 12, 2, 14, 4, 9, 3, 10, 7, 13, 1, 11, 8, 5};
	qssort(a, 0, 13,9);
	qssort(a, 0, 6, 6);
	qssort(a, 7, 13, 12);
	for (int i = 0; i < 14; ++i) printf("%d ", a[i]);
	return 0;
}