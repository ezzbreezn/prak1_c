#include <stdio.h>
#include <stdlib.h>

struct list
{
	int key;
	struct list *next;
};

struct list *add(struct list *t, int key)
{
	if (t == NULL)
	{
		t = (struct list *)malloc(sizeof(struct list));
		t -> key = key;
		t -> next = t;
		return t;
	}
	struct list *p = t;
	while (p -> next != t) p = p-> next;
	p -> next = (struct list*)malloc(sizeof(struct list));
	p -> next -> key = key;
	p -> next -> next = t;
	return t;
}

void show(struct list *t)
{
	struct list *p = t;
	do
	{
		printf("%d ", p -> key);
		p = p ->next;
	}while (p != t);
	printf("\n");
}

struct list *no16s (struct list *t)
{
	struct list *s = t, *p = t, *q = NULL;
	do
	{
		if (p -> key == 2016 && p -> next != p)
		{
			struct list *pr = p;
			while (pr -> next != p) pr = pr -> next;
			pr -> next = p -> next;
			if (p == s)
			{
				free(p);
				p = pr -> next;
				s = p;
				continue;
			}
			else
			{
				free(p); p = pr -> next;
			}
		}
		else if (p -> key == 2016 && p ->next == p)
		{
			free(p); return NULL;
		}
		else
			p = p -> next;
	}while (p != s);
	return p;
}

int main(void)
{
	struct list *t = NULL;
	int x;
	scanf("%d", &x);
	while(x != 100)
	{
		t = add(t, x);
		scanf("%d", &x);
	}
	show(t);
	t = no16s(t);
	show(t);
	return 0;
}
