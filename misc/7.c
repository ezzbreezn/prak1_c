#include <stdio.h>
#include <string.h>

char *extra(char *list, char **t)
{
	char *res;
	int i = 0;
	while (t[i] != NULL)
	{
		//printf("%s\n", t[i]);
		if (strstr(list, t[i])==NULL)
		{
			res = t[i]; break;
		}
		//i += strlen(*i);
		++i;
	}
	return res;
}

int main(void)
{
	char *list = "gavno;pidaras;huesos;gandon";
	char *t[] = {"gavno", "pidaras", "zheppa","huesos", "gandon", NULL};
	char *ans = extra(list, t);
	int x = 2, y = -11, z = 2;
	printf("%s\n", ans);
	printf("%d", x = y & y =z);
	return 0;
}