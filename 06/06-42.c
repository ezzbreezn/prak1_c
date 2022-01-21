#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int key;
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *search(struct tree *s, int key)
{
	if (s == NULL || s->key == key) return s;
	if (key<s->key)
		return search(s->left, key);
	else
		return search(s->right, key);
}

struct tree *min(struct tree *s)
{
	if (s == NULL || s->left==NULL) return s;
	else return min(s->left);
}

struct tree *insert(struct tree *s, int key, int data)
{
	if (s == NULL)
	{
		s = (struct tree *)malloc(sizeof(struct tree));
		s ->key = key;
		s->data=data;
		s->left =NULL;
		s ->right =NULL;
		return s;
	}
	if(key < s -> key)
		s->left = insert(s->left, key,data);
	else
		s ->right =insert(s->right, key,data);
	return s;
}

/*struct tree *delete(struct tree *s, int key)
{
	if (s==NULL) return s;
	if (key < s->key)
		s->left = delete(s->left, key);
	else if (key > s->key)
		s ->right = delete(s->right, key);
	else
	{
		if (s->left != NULL && s->right != NULL)
		{
			s ->key = min(s->right)->key;
			s->right = delete(s->right, s->key);
		}
		else if (s->left != NULL)
			s=s->left;
		else if (s->right !=NULL)
			s=s->right;
		else
			s =NULL;
	}
	return s;
}*/

struct tree *delete(struct tree *s, int key)
{
	if (s==NULL) return s;
	if (key < s->key)
	{
		s->left = delete(s->left, key);
		return s;
	}
	else if (key > s->key)
	{
		s ->right = delete(s->right, key);
		return s;
	}
	else
	{
		if (s->left != NULL && s->right != NULL)
		{
			s ->key = min(s->right)->key;
			s->right = delete(s->right, s->key);
			return s;
		}
		else if (s->left != NULL)
		{
			//s=s->left;
			struct tree *ss = s -> left;
			free(s);
			return ss;
		}
		else if (s->right !=NULL)
		{
			struct tree *ss = s->right;
			free(s);
			return ss;
		}
		else
		{
			free(s);
			return NULL;
		}
	}
	//return s;
}

int main(void)
{
	struct tree *t = NULL;
	int a, b;
	char c;
	scanf("%c", &c);
	while (c != 'F')
	{
		if (c == 'A')
		{
			scanf("%d%d", &a, &b);
			struct tree *f =search(t,a);
			if (f!=NULL)
				f->data = b;
			else
				t = insert(t, a,b);
		}
		else if (c == 'S')
		{
			scanf("%d", &a);
			struct tree *f = search(t, a);
			if (f != NULL)
				printf("%d %d\n", f->key, f->data);
		}
		else if ( c=='D')
		{
			scanf("%d", &a);
			t = delete(t,a);
		}
		scanf("%c", &c);
	}
	return 0;
}