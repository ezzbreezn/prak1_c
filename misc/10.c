#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
	char *s;
	struct tree *left, *right;
};

struct tree *newnode(char *s)
{
	struct tree * temp = (struct tree *)malloc(sizeof(struct tree));
	//temp -> s = s;
	temp -> s = (char *)malloc(sizeof(char)*(strlen(s) + 1));
	strcpy(temp->s, s);
	temp -> left = NULL;
	temp -> right = NULL;
	//temp -> parent = NULL;
	return temp;
}

struct tree *insert(struct tree *r, char *s)
{
	struct tree *newn = newnode(s);
	struct tree *p = r, *q = NULL;
	while (p)
	{
		q = p; p = (strcmp(s,p -> s) < 0) ? p -> left: p -> right;
	}
	//newn -> parent = q;
	if (q == NULL) r =newn;
	else if (strcmp(s, q -> s) < 0) q -> left = newn;
	else q -> right = newn;
	return r;
}

/*struct tree *min(struct tree *t)
{
	if (t == NULL) return t;
	while (t -> left) t = t->left;
	return t;
}

struct tree *succ(struct tree *t)
{
	struct tree *q = NULL;
	if (t -> right) return min(t -> right);
	q = t -> parent;
	while(q && t == q -> right)
	{
		t = q, q = q -> parent;
	}
	return q;
}*/

void count (struct tree *t, int *c)
{
	if (t != NULL)
	{
		count(t->left,c);
		if(t -> s[strlen(t -> s) - 1] == 'z') ++*c;
		count(t->right,c);
	}
}

void addz(struct tree **ppt)
{
	int c = 0; count(*ppt, &c);
	printf("%d\n", c);
	char *s;
	if (c == 0)
	{
		s = (char *)malloc(2 * sizeof(char));
		s[0] = 'z'; s[1] = '\0';
	}
	else
	{
		s = (char *)malloc((c + 1) * sizeof(char));
		for (int i = 0; i < c; ++i) s[i] = 'z';
		s[c] = '\0';
	}
	struct tree *p = (struct tree *)malloc(sizeof(struct tree));
	p -> s = (char *)malloc(sizeof(char) *( strlen(s) + 1));
	strcpy(p -> s, s), p -> left = NULL, p -> right = NULL;
	struct tree *temp = *ppt, *q = NULL;
	while (temp)
	{
		q = temp;
		temp = (strcmp(s, temp ->s) < 0 ? temp -> left : temp ->right);
	}
	if (q == NULL)
	{
		*ppt = p;
	}
	else if(strcmp(s, q -> s) < 0)
		q -> left = p;
	else q -> right = p;
}

void show(struct tree *t)
{
	if (t != NULL)
	{
		show(t -> left);
		printf("%s\n", t -> s);
		show(t -> right);
	}
}

int main(void)
{
	struct tree *t = NULL;
	char s[100];
	scanf("%s", s);
	while(strcmp("sas", s) != 0)
	{
		t = insert(t, s);
		scanf("%s", s);
	}
	show(t);
	addz(&t);
	show(t);
	return 0;
}