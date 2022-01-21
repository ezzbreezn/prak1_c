#include <stdio.h>

int main(void)
{
	FILE *f = fopen("/home/boris/prak/06-9/input.bin", "wb");
	short x;
	scanf("%hd", &x);
	fwrite(&x, 2 , 1,f);
	int xx;
	scanf("%d", &xx);
	while (xx != -1)
	{
		fwrite(&xx, 4, 1, f);
		scanf("%d", &xx);
	}
	fclose(f);
	f = fopen("/home/boris/prak/06-9/input.bin", "rb");
	short *ptr = &x;
	fread(&ptr, 2, 1, f);
	printf("%hd\n", x);
	while(fread(&xx, 4, 1, f))
		printf("%d\n", xx);
	fclose(f);
	return 0;
}