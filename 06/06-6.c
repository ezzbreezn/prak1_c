#include <stdio.h>
#include <stdlib.h>

struct list
{
	int info;
	struct list *next;
};

struct list *add(struct list *p, int val)
{
	if (p == NULL)
	{
		p = (struct list *)malloc(sizeof(struct list));
		p -> info = val;
		p -> next = NULL;
		return p;
	}
	struct list *t = p;
	while(p -> next !=NULL)
		p = p -> next;
	p -> next = (struct list *)malloc(sizeof(struct list));
	p -> next -> info = val;
	p -> next -> next = NULL;
	return t;
}

struct list *search(struct list *p, int val)
{
	struct list *t = p;
	while (t && t -> info != val)
		t = t -> next;
	return t;
}

struct list *delete(struct list *p, int val)
{
	struct list *t = p, *q = NULL;
	while (p && p -> info != val)
	{
		q = p, p = p -> next;
	}
	if (p == NULL)
		return t;
	if (q != NULL)
	{
		q -> next = p -> next;
	}
	else
		t = p -> next;
	free(p);
	return t;

}

int main(void)
{
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");
	int x;
	struct list *l = NULL;
	while (fscanf(fin, "%d", &x) != -1 && x != -1)
	{
		l = add(l, x);
	}
	while (fscanf(fin, "%d", &x) != -1 && x != -1)
	{
		struct list *res = search(l, x);
		while (res != NULL)
		{
			l = delete(l, x);
			res = search(l, x);
		}
	}
	while (l != NULL)
	{
		fprintf(fout, "%d ", l -> info);
		l = l -> next;
	}
	fclose(fin);
	fclose(fout);
	return 0;
}