#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fin = fopen("matrix.in", "rb");
	int temp;
	fread(&temp, 2, 1, fin);
	unsigned int stemp = temp;
	long long sz = 0;
	sz += ((stemp << 16) >> 24);
	sz += ((stemp << 24) >> 16);
	long long i = 0, trace = 0, shift = 0;
	while (i < sz * sz)
	{
		for (long long j = 0; j < sz; ++j)
		{
			fread(&temp, 4, 1, fin);
			if (j == shift)
			{
				unsigned int ttemp = temp;
				unsigned int num = 0;
				num |= ((ttemp >> 24));
				num |= (((ttemp << 8) >> 24) << 8);
				num |= (((ttemp << 16) >> 24) << 16);
				num |= ((ttemp << 24));
				int nnum = num;
				trace += nnum;
			}
		}
		++shift;
		i += sz;
	}
	fclose(fin);
	FILE *fout = fopen("trace.out", "wb");
	unsigned long long temp1 = 0, ttrace = trace;
	temp1 |= (ttrace >> 56);
	temp1 |= (((ttrace << 8) >> 56) << 8);
	temp1 |= (((ttrace << 16) >> 56) << 16);
	temp1 |= (((ttrace << 24) >> 56) << 24);
	temp1 |= (((ttrace << 32) >> 56) << 32);
	temp1 |= (((ttrace << 40) >> 56) << 40);
	temp1 |= (((ttrace << 48) >> 56) << 48);
	temp1 |= (ttrace << 56);
	long long res = temp1;
	fwrite(&res, 8, 1, fout);
	fclose(fout);
	return 0;
}