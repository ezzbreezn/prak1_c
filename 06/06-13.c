#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
	struct tree *left;
	struct tree *right;
	struct tree *parent;
	char str[100];
	char sc[100];
	int numb;
	int flag;

};

struct tree *newnode(char *s, int n)
{
	struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
	int j = 0;
	while (s[j] != '\n' && s[j] != '\0')
	{
		temp -> str[j] = s[j];
		++j;
	}
	temp -> str[j] = '\0';
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> parent = NULL;
	int start = 0, num = 0;
	while(num < n)
	{
		if (s[start] == ';')
			++num;
		++start;
	}
	while (s[start] == ' ')
		++start;
	int pos = 0;
	if (s[start] == '"')
	{
		temp -> flag = 0;
		++start;
		while (s[start] != '"')
		{
			temp -> sc[pos++] = s[start++];
		}
		temp -> sc[pos] = '\0';
	}
	else
	{
		temp -> flag = 1;
		int res = 0, sign = 1;
		if (s[start] == '-')
		{
			sign = -1;
			++start;
		}
		while (s[start] != ';' && s[start] != ' ' && s[start] != '\n' && s[start] != '\0')
		{
			res *= (10 * (res != 0));
			res += (s[start] - '0');
			++start;
		}
		res *= sign;
		temp -> numb = res;
	}
	return temp;
}

struct tree *insert(struct tree *t, char *s, int n)
{
	struct tree *temp = newnode(s, n);
	struct tree *p = t, *q = NULL;
	while (p)
	{
		q = p;
		if (t -> flag == 0)
			p = (strcmp(temp -> sc, p -> sc) < 0 ? p -> left : p -> right);
		else
			p = (temp -> numb < p -> numb ? p -> left : p -> right);
	}
	temp -> parent = q;
	if (temp -> flag == 0)
	{
		if (q == NULL)
			t = temp;
		else if (strcmp(temp -> sc, q -> sc) < 0)
			q -> left = temp;
		else
			q -> right = temp;
	}
	else
	{
		if (q == NULL)
			t = temp;
		else if (temp -> numb < q -> numb)
			q -> left = temp;
		else
			q -> right = temp;
	}
	return t;
}

void inorder(struct tree *t, FILE *fout)
{
	if (t == NULL)
		return;
	inorder(t -> left, fout);
	int l = strlen(t -> str);
	int f = 0;
	for (int i = 0; i < l; ++i)
	{
		if (t -> str[i] == '"' && f == 0)
			f = 1;
		else if (t -> str[i] == '"' && f == 1)
			f = 0;
		if (!f)
		{
			if (t -> str[i] != ' ' && t -> str[i] != '\n' && t -> str[i] != '\0')
				fprintf(fout, "%c", t -> str[i]);
		}
		else
		{
			if (t -> str[i] != '\n' && t -> str[i] != '\0')
				fprintf(fout, "%c", t -> str[i]);		
		}
	}
	fprintf(fout, "\n");
	inorder(t -> right, fout);
}

int main(void)
{
	FILE *fin = fopen("input.txt", "r");
	int n;
	fscanf(fin, "%d", &n);
	char c;
	fscanf(fin, "%c", &c);
	char str[100];
	struct tree *t = NULL;
	while (feof(fin) == 0 && fgets(str, 100, fin) != NULL && str[0] != '\n')
	{
		t = insert(t, str, n);
	}
	fclose(fin);
	FILE *fout = fopen("output.txt", "w");
	inorder(t, fout);
	fclose(fout);
	return 0;
}