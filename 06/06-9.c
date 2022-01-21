#include <stdio.h>

int main(void)
{
	FILE *f = fopen("input.bin", "rb");
	int x, n = 0, f1 = 1, f2 = 1;
	int a[2000001] = {};
	while (fread(&x, 4, 1, f))
	{
		a[n] = x, ++n;
	}
	fclose(f);
	for (int i = 0; 2 * i + 1 < n; ++i)
	{
		if (a[i] < a[2 * i + 1] || (2 * i + 2 < n && a[i] < a[2 * i + 2]))
		{
			f1 = 0;
			break;
		}
	}
	for (int i = 0; 2 * i + 1 < n; ++i)
	{
		if (a[i] > a[2 * i + 1] || (2 * i + 2 < n && a[i] > a[2 * i + 2]))
		{
			f2 = 0;
			break;
		}
	}
	f = fopen("output.bin", "wb");
	if (!f1 && !f2)
		x = 0;
	else if (f2)
		x = 1;
	else if (f1)
		x = -1;
	fwrite(&x, 4, 1, f);
	fclose(f);
	return 0;
}