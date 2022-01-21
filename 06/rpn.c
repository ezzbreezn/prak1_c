#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	int top;
	int sz;  
	char *st;
};

struct lstack
{
	long long top;
	long long sz;
	long long *st;
};



void push(char c, struct stack *s)
{
	if (s -> sz == s -> top + 1)
	{
		s -> sz = 2 * (s -> sz) + 2;
		int temp = s -> sz;
		s -> st = (char *)realloc(s -> st, temp * sizeof(char));
	}
	s -> st[s -> top] = c;
	//printf("---%c---\n", s -> st[s -> top]);
	s -> top++;
}

void lpush(long long c, struct lstack *s)
{
	if (s -> sz == s -> top + 1)
	{
		s -> sz = 2 * (s -> sz) + 2;
		long long  temp = s -> sz;
		s -> st = (long long  *)realloc(s -> st, temp * sizeof(long long));
	}
	s -> st[s -> top] = c;
	s -> top++;
}

char pop(struct stack *s)
{
	s -> top--;
	if (s -> top < 0)
		return 'a';
	return s -> st[s -> top];
}

long long lpop(struct lstack *s)
{
	s -> top--;
	if (s -> top < 0)
		return -1;
	return s -> st[s -> top];
}

char gettop(struct stack *s)
{
	if (s -> top - 1  < 0)
		return 'a';
	return s -> st[s -> top - 1];
}

long long lgettop(struct lstack *s)
{
	if (s -> top - 1  < 0)
		return -1;
	return s -> st[s -> top - 1];
}

void print(struct stack *s)
{
	int i = s -> top;
	while (i >= 0)
	{
		printf("%c ", s -> st[i]);
		--i;
	}
}

int priority(char c)
{
	switch (c)
	{
		case '*':
		case '/':
			return 3;
		case '-':
		case '+':
			return 2;
		case '(':
			return 1;
	}
}

void processing(char c, struct lstack *ls)
{
	long long b = lpop(ls);
	long long a = lpop(ls);
	switch (c)
	{
		case '+':
			lpush(a + b, ls);
			break;
		case '-':
			lpush(a - b, ls);
			break;
		case '*':
			lpush(a * b, ls);
			break;
		case '/':
			lpush(a / b, ls);
			break;
	}
}

int main(void)
{
	FILE *fin = fopen("/home/boris/prak/06-11/input.txt", "r");
	FILE *fout = fopen("/home/boris/prak/06-11/output.txt", "w");
	char str[2000002], rpn[2000002];
	//fgets(str, 2000002, stdin);
	fgets(str, 2000002, fin);
	char t;
	struct stack s = {.top = 0, .sz = 1000000, .st = (char *)malloc(sizeof(char) * 1000000)};
	struct lstack ls = {.top = 0, .sz = 1000000, .st = (long long *)malloc(sizeof(long long) * 1000000)};
	fclose(fin);
	/*long long i = 0, pi = 0, flag = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && flag)
		{
			rpn[pi++] = ' ';
			flag = 0;
		}
		if (str[i] == ')')
		{
			while (gettop(&s) != '(')
				rpn[pi++] = pop(&s);
			t = pop(&s);
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			rpn[pi++] = str[i];
			//printf("hui\n");
		}
		else if (str[i] == '(')
			push(str[i], &s);
		else if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			if (gettop(&s) == 'a')
				push(str[i], &s);
			else if (priority(gettop(&s)) < priority(str[i]))
				push(str[i], &s);
			else
			{
				while (gettop(&s) != 'a' && priority(gettop(&s)) >= priority(str[i]))
					rpn[pi++] = pop(&s);
				push(str[i], &s);
			}
		}
		++i;
	}
	rpn[pi] = '\0', flag = 0;
	while(gettop(&s) != 'a')
		rpn[pi++] = pop(&s);
	//printf("%d\n", gettop(&s) == 'a');
	//for (long long i = 0; i < pi; ++i)
		//printf("%c", rpn[i]);
	//long long res = 0, m = 1, temp = 0;
	*/
	long long pp = strlen(str);
	for (long long i = 0; i < pp; ++i)
	{
		if (str[i] == '(')
			push(str[i], &s);
		else if (str[i] == ')')
		{
			while (gettop(&s) != '(')
			{
				t = pop(&s);
				processing(t, &ls);
			}
			t = pop(&s);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			while (gettop(&s) != 'a' && priority(gettop(&s)) >= priority(str[i]))
			{
				processing(gettop(&s), &ls);
				t = pop(&s);
			}
			push(str[i], &s);
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			long long res = 0;
			while (i < pp && str[i] >= '0' && str[i] <= '9')
			{
				res *= 10;
				res += (str[i] - '0');
				++i;
			}
			--i;
			//printf("%lld\n", res);
			lpush(res, &ls);
		}
	}
	while (gettop(&s) != 'a')
	{
		processing(gettop(&s), &ls);
		t = pop(&s);
	}
	long long ans = lgettop(&ls);
	//printf("%lld", ans);
	fprintf(fout, "%lld", ans);
	fclose(fout);
	return 0;
}