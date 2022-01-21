#include <stdio.h>
#include <stdlib.h>

struct avlnode
{
	int key;
	int data;
	struct avlnode *left;
	struct avlnode *right;
	int height;
};

struct avlnode *delete_all(struct avlnode *s)
{
	if (s != NULL)
	{
		delete_all(s -> left);
		delete_all(s -> right);
		free(s);
	}
	return NULL;
}

struct avlnode *search(struct avlnode *s, int val)
{
	if (s == NULL || s -> key == val)
		return s;
	if (val < s -> key)
		return search(s -> left, val);
	else
		return search(s -> right, val);
}

struct avlnode *findmin(struct avlnode *s)
{
	if (s == NULL || s -> left == NULL)
		return s;
	else
		return findmin(s -> left);
}

struct avlnode *findmax(struct avlnode *s)
{
	if (s == NULL || s -> right == NULL)
		return s;
	else
		return findmax(s -> right);
}

int height(struct avlnode *s)
{
	return s ? s -> height : 0;
}

int balancefact(struct avlnode *s)
{
	return height(s -> right) - height(s -> left);
}

void getbalance(struct avlnode *s)
{
	s -> height = (height(s -> left) > height(s -> right) ? height(s -> left) : height(s -> right)) + 1;
}

struct avlnode *rotateright(struct avlnode *s)
{
	struct avlnode *q = s -> left;
	s -> left = q ->right;
	q -> right = s;
	//getheight(s);
	//getheight(q);
	getbalance(s);
	getbalance(q);
	return q;
}

struct avlnode *rotateleft(struct avlnode *s)
{
	struct avlnode *q = s -> right;
	s -> right = q -> left;
	q -> left = s;
	//getheight(s);
	//getheight(q);
	getbalance(s);
	getbalance(q);
	return q;
}

struct avlnode *balance(struct avlnode *s)
{
	getbalance(s);
	if (balancefact(s) == 2)
	{
		if (balancefact(s -> right) < 0)
			s -> right = rotateright(s -> right);
		return rotateleft(s);
	}
	if (balancefact(s) == -2)
	{
		if (balancefact(s -> left) > 0)
			s -> left = rotateleft(s -> left);
		return rotateright(s);
	}
	return s;
}

struct avlnode *insert(struct avlnode *s, int val, int data)
{
	if (s == NULL)
	{
		s = (struct avlnode *)malloc(sizeof(struct avlnode));
		s -> key = val;
		s -> data = data;
		s -> left = NULL;
		s -> right = NULL;
		getbalance(s);
		return s;
	}
	if (val < s -> key)
		s -> left = insert(s -> left, val, data);
	else
		s -> right = insert(s -> right, val, data);
	return balance(s);
}

struct avlnode *submin(struct avlnode *s)
{
	if (s -> left == NULL)
		return s -> right;
	s -> left = submin(s -> left);
	return balance(s); //returns the root of rebalanced tree without "deleted" min node
}


struct avlnode *delete(struct avlnode *s, int val)
{
	if (s == NULL) 
		return s;
	if (val < s -> key)
		return delete(s -> left, val);
	else if (s -> key < val)
		return delete(s -> right, val);
	else
	{
		struct avlnode *l = s -> left, *r = s -> right;
		free(s);
		if (r == NULL)
			return l;
		struct avlnode *m = findmin(r); //save the min node
		m -> right = submin(r); //right child of the min node in r is the root in rebalanced tree without m
		m -> left = l; //replacing m to the place of really deleting s (recursive)
		return balance(m); //rebalancing the new tree
	}
	return balance(s);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	struct avlnode *t = NULL;
	for (int i = 0; i < n; ++i)
	{
		int temp, data;
		scanf("%d%d", &temp, &data);
		t = insert(t, temp, data);
	}
	char req;
	scanf("%c", &req);
	while (req != 'F')
	{
		int val, data;
		if (req == 'A')
		{
			scanf("%d%d", &val, &data);
			t = insert(t, val, data);
		}
		else if (req == 'D')
		{
			scanf("%d", &val);
			t = delete(t, val);
		}
		else if (req == 'S')
		{
			scanf("%d", &val);
			struct avlnode *ans = search(t, val);
			if (ans != NULL)
				printf("%d %d\n", ans -> key, ans -> data); 
		}
		scanf("%c", &req);
	}
	return 0;
}