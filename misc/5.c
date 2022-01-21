#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int key;
	struct tree *left, *right, *parent;
};

struct tree *newnode(int val)
{
	struct tree * temp = (struct tree *)malloc(sizeof(struct tree));
	temp -> key = val;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> parent = NULL;
	return temp;
}

struct tree *insert(struct tree *r, int key)
{
	struct tree *newn = newnode(key);
	struct tree *p = r, *q = NULL;
	while (p)
	{
		q = p; p = (key < p -> key) ? p -> left: p -> right;
	}
	newn -> parent = q;
	if (q == NULL) r =newn;
	else if (newn -> key < q -> key) q -> left = newn;
	else q -> right = newn;
	return r;
}

struct tree *min(struct tree *t)
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
}

void inorder(struct tree *t, int *res, int *key)
{
	if (t == NULL) return ;
	inorder(t -> left,res, key);
	if (succ(t) != NULL && abs((t -> key) - (succ(t) -> key))<res)
	{
		*res = abs((t -> key) - (succ(t)->key));
		*key = t -> key;
	}
	inorder(t -> right, res, key);
}
int far(struct tree *t)
{
	int res = t -> key, key = t -> key;
	inorder(t, &res, &key);
	return key;
}

void traversal(struct tree *t, int *max, int temp)
{
	if (t == NULL) return;
	if (t -> parent!= NULL && t -> parent->parent!=NULL)
	{
		if((t==t -> parent -> left && t -> parent == t -> parent -> parent -> right) || (t == t -> parent -> right && t -> parent == t -> parent -> parent -> left))
		{
			++temp;
			if (temp > *max) *max = temp;
			traversal(t -> left, max, temp);
			traversal(t -> right, max, temp);
			return;
		}
		else return;
	}
	traversal(t -> left, max, temp);
	traversal(t -> right, max, temp);
}

int crooked(struct tree *t)
{
	int max = 0, temp = 0;
	traversal(t, &max, temp);
	return max + 1;;
}

void leftturns(struct tree *t, int l, int r, int *max)
{
	if (t == NULL) return;
	if (t -> parent != NULL)
	{
		if (t == t -> parent -> left) ++l;
		else if (t == t -> parent -> right) ++r;
		if (l - r > *max) *max = l - r;
	}
	leftturns(t -> left, l, r, max);
	leftturns(t -> right, l , r, max);
}

int maxleft(struct tree *t)
{
	int max = 0; leftturns(t, 0, 0, &max);
	return max;
}

struct tree *copy(struct tree *t)
{
	if (t == NULL) return NULL;
	struct tree *new = (struct tree *)malloc(sizeof(struct tree));
	new -> key = t -> key;
	new -> left = copy(t -> left);
	new -> right = copy(t -> right);
	return new;
}

void show(struct tree *t)
{
	if (t == NULL) return ;
	show(t -> left);
	printf("%d\n", t -> key);
	show(t -> right);
}

int main(void)
{
	//short n = 0x4F80; int i = 120;
	struct tree *t = NULL;
	int x;
	scanf("%d", &x);
	while( x != 100)
	{
		t = insert(t, x);
		scanf("%d", &x);
	}
	int ans = maxleft(t);
	//int ans = far(t);
	//int ans = crooked(t);
	printf("%d", ans);
	//struct tree *a = copy(t);
	//show(a);
	return 0;
}