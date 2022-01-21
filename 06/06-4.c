#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int key;
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};

struct tree *newnode(int key, int data)
{
	struct tree *new = (struct tree *)malloc(sizeof(struct tree));
	new -> key = key;
	new -> data = data;
	new -> left = NULL;
	new -> right = NULL;
	new -> parent = NULL;
	return new;
}

struct tree *search(struct tree *t, int key)
{
	if (t == NULL)
		return t;
	struct tree *p = t;
	while (p && p -> key != key)
	{
		if (key < p -> key)
			p = p -> left;
		else
			p = p -> right;
	}
	return p;
}

struct tree *insert(struct tree *t, int key, int data)
{
	struct tree *new = newnode(key, data);
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

struct tree *min(struct tree *t)
{
	if (t == NULL)
		return t;
	struct tree *p = t;
	while (p -> left)
		p = p -> left;
	return p;
}

struct tree *succ(struct tree *t)
{
	struct tree *p = t;
	if (p -> right)
		return min(p -> right);
	struct tree *q = p -> parent;
	while(q && p == q -> right)
	{
		p = q;
		q = q -> parent;
	}
	return q;
}

/*struct tree *delete(struct tree *t, int key)
{
	if (t == NULL)
		return t;
	struct tree *f = search(t, key);
	if (f == NULL)
		return t;
	if (f -> left == NULL && f -> right == NULL)
	{
		if (f -> parent == NULL)
		{
			free(f);
			return NULL;
		}
		else
		{
			if (f == f -> parent -> left)
				f -> parent -> left = NULL;
			else
				f -> parent -> right = NULL;
			free(f);
			return t;
		}
	}
	else if ((f -> left == NULL && f -> right != NULL) || (f -> left != NULL && f -> right == NULL))
	{
		if (f -> left == NULL)
		{
			if (f -> parent == NULL)
			{
				f -> right -> parent = NULL;
				t = f -> right;
				free(f);
				return t;
			}
			else
			{
				if (f == f -> parent -> left)
					f -> parent -> left = f -> right;
				else
					f -> parent -> right = f -> right;
				f -> right -> parent = f -> parent;
				free(f);
				return t;
			}
		}
		else
		{
			if (f -> parent == NULL)
			{
				f -> left -> parent = NULL;
				t = f -> left;
				free(f);
				return t;
			}
			else
			{
				if (f == f -> parent -> left)
					f -> parent -> left = f -> left;
				else
					f -> parent -> right = f -> left;
				f -> left -> parent = f -> parent;
				free(f);
				return t;
			}
		}
	}
	else
	{
		struct tree *y = min(f -> right);
		if (y == y -> parent -> left)
			y -> parent -> left = NULL;
		else
			y -> parent -> right = NULL;
		f -> right -> parent = y;
		f -> left -> parent = y;
		if (f -> parent != NULL)
		{
			if (f == f -> parent -> left)
				f -> parent -> left = y;
			else
				f -> parent -> right = y;
		}
		y -> left = f -> left;
		y -> right = f -> right;
		y -> parent = f -> parent;
		if (y -> parent == NULL)
			t = y;
		free(f);
		return t;
	}
}*/


void delete(struct tree **t, struct tree *k)
{
	struct tree *x, *y;
	y = (k -> left == NULL || k -> right == NULL) ? k : succ(k);
	x = y -> left ? y -> left: y -> right;
	if (x != NULL)
		x -> parent = y -> parent;
	if (!y -> parent)
		*t = x;
	else
	{
		if (y == y -> parent -> left)
			y -> parent -> left = x;
		else
			y -> parent -> right = x;
	}
	if (y != k)
	{
		k -> key = y -> key;
		k -> data = y -> data;
	}
	free(y);

}

int main(void)
{
	char c;
	int a, b;
	struct tree *t = NULL;
	scanf("%c", &c);
	while (c != 'F')
	{
		if (c == 'A')
		{
			scanf("%d%d", &a, &b);
			struct tree *f = search(t, a);
			if (f == NULL)
				t = insert(t, a, b);
			else
				f -> data = b;
		}
		else if (c == 'S')
		{
			scanf("%d", &a);
			struct tree *f = search(t, a);
			if (f != NULL)
				printf("%d %d\n", f -> key, f -> data);
		}
		else if (c == 'D')
		{
			scanf("%d", &a);
			//t = delete(t, a);
			struct tree *f = search(t, a);
			if (f != NULL)
				delete(&t, f);
		}
		scanf("%c", &c);
	}
	return 0;
}