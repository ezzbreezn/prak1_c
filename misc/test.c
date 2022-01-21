#include <stdio.h>

struct seq {
  signed char c;
  short s;
  struct seq *next; 
};

int main(void){
	//unsigned *x;
	//unsigned v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//*x = 12;
	//int i = 8;
	//int res;
	//res = (i < 10) ? (*x ^= ((v[i] >> 13) | (v[i] << 19)), i++) : (i = 0);
	//printf("%d\n", sizeof(time_t));
	unsigned int y = 4294967295;
	printf("%d", sizeof(struct seq));
	return 0;
}