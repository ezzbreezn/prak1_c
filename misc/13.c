#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int key;
	struct tree *left, *right;
};

void bsort(int *a, int n)
{
	int i, j, temp;
	for (j = 1; j < n; ++j)
		for (i = n - 1; i >= j; --i)
		{
			if(a[i-1]>a[i])
			{
				temp = a[i-1], a[i-1] = a[i], a[i] =temp;
			}
		}
}

struct tree *build(int *a, int l, int r)
{
	if(l>r) return NULL;
	struct tree *t = (struct tree *)malloc(sizeof(struct tree));
	t -> key = a[(l+r)/2];
	t -> left = build(a, l, ((l + r)/2)-1);
	t -> right=build(a, ((l+r)/2)+1,r);
	return t;
}

struct tree *hbuild(int h)
{
	if (h <= 0) return NULL;
	struct tree *t = (struct tree *)malloc(sizeof(struct tree));
	if (h % 2==0)
	{
		t -> left = hbuild(h-1);
		t->right=hbuild(h-2);
	}
	else
	{
		t -> left = hbuild(h-2);
		t -> right = hbuild(h-1);
	}
	return t;
}

void fill(struct tree *t, int *x)
{
	if (t == NULL) return;
	fill(t -> left, x);
	t -> key = *x;
	++*x;
	fill(t -> right,x);
}

void show(struct tree *t)
{
	if(t==NULL) return;
	show(t ->left);
	printf("%d\n", t->key);
	show(t->right);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	//int a[n];
	//for(int i = 0;i<n;++i) scanf("%d", &a[i]);
	//bsort(a, n);
	//struct tree *t = build(a, 0, n-1);
	struct tree *t = hbuild(n);
	int x = 1;
	fill(t, &x);
	show(t);
	return 0;
}