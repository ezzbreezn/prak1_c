#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};
struct tree *newnode(int key)
{
	struct tree *new = (struct tree *)malloc(sizeof(struct tree));
	new -> key = key;
	new -> left = NULL;
	new -> right = NULL;
	new -> parent = NULL;
	return new;
}

struct tree *insert(struct tree *t, int key)
{
	struct tree *new = newnode(key);
	if (t == NULL)
	{
		t = new;
		return t;
	}
	struct tree *p = t, *q = NULL;
	while (p)
	{
		q = p;
		if (key < p -> key)
			p = p -> left;
		else
			p = p -> right;
	}
	new -> parent = q;
	if (key < q -> key)
		q -> left = new;
	else
		q -> right = new;
	return t;
}

void inorder(struct tree *t, int *n)
{
	if (t != NULL)
	{
		inorder(t -> left, n);
		++*n;
		inorder(t -> right, n);
	}
}

struct tree *min(struct tree *t)
{
	if ( t == NULL) return t;
	while (t -> left != NULL)
		t = t -> left;
	return t;

}

struct tree *unhappy(struct tree *t)
{
	int n = 0;
	inorder(t, &n);
	n /=3;
	for (int i = 0; i < n; ++i)
	{
		struct tree *p = min(t);
		if (p -> parent == NULL)
		{
			t = p -> right;
			t -> parent = NULL;
			free(p);
		}
		else if (p -> right == NULL)
		{
			p -> parent -> left = NULL;
			free(p);
		}
		else
		{
			p -> parent -> left = p -> right;
			p ->right -> parent = p -> parent;
			free(p);
		}
	}
	return t;
}

void draw(struct tree *t)
{
	if (t != NULL)
	{
		draw(t -> left);
		printf("%d ", t -> key);
		draw(t -> right);
	}
}

int main(void)
{
	int x;
	struct tree *t = NULL;
	scanf("%d", &x);
	while(x != 100)
	{
		t = insert(t, x);
		scanf("%d", &x);
	}
	draw(t);
	printf("\n");
	t = unhappy(t);
	draw(t);
	return 0;
}
