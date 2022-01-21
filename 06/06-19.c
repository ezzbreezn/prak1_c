#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bohr
{
	int leaf;
	struct bohr *left;
	struct bohr *right;
	char c;
};

struct bohr *new(void)
{
	struct bohr *s = (struct bohr *)malloc(sizeof(struct bohr));
	s -> left = NULL;
	s -> right = NULL;
	s -> leaf = 0;
	return s;
}

struct bohr *add(struct bohr *root, char *s, int len, char letter)
{
	struct bohr *p = root;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '0')
		{
			if (p -> left == NULL)
				p -> left = new();
			p = p -> left;
		}
		else
		{
			if (p -> right == NULL)
				p -> right = new();
			p = p -> right;
		}
	}
	p -> leaf = 1;
	p -> c = letter;
	return root;
}
int search(struct bohr *root, char *s, int len)
{
	struct bohr *p = root;
	int i = 0;
	for (; i < len; ++i)
	{
		if (p == NULL)
			break;
		if (s[i] == '0')
			p = p -> left;
		else
			p = p -> right;
	}
	if (i == len && p != NULL && p -> leaf == 1)
		return p -> c;
	else 
		return 1000000000;
}

int main(void)
{
	FILE *fin = fopen("crypto", "rb");
	struct bohr *root = new();
	char temp[9000], f[9000], res[9000];
	char source[2030000];
	char c, enter;
	int k, len, code, mcode;
	fread(&k, 1, 1, fin);
	if (k == 0)
		k = 256;
	for (int i = 0; i < k; ++i)
	{
		fread(&enter, 1, 1, fin);
		fread(&len, 1, 1, fin);
		int scan = (len + 7) / 8;
		int pos = 0;

		for (int j = 0; j < scan; ++j)
		{
			fread(&code, 1, 1, fin);
			for (int p = 0; p < 8; ++p)
			{
				int tc = code & (1 << p);
				if (tc)
					temp[pos] = '1';
				else
					temp[pos] = '0';
				++pos;
			}

		}
		root = add(root, temp, len, enter);
	}
	int spos = 0;
	while (!feof(fin) && fread(&mcode, 1, 1, fin))
	{
		for (int p = 0; p < 8; ++p)
		{
			int tc = mcode & (1 << p);
			if (tc)
				source[spos] = '1';
			else
				source[spos] = '0';
			++spos;
		}
	}

	fclose(fin);
	int pos = 0, rpos = 0,  start = 0;
	while (start < spos)
	{
		f[pos] = source[start];
		++pos;
		int ans = search(root, f, pos);
		if (ans != 1000000000)
		{
			c = (char) ans;
			res[rpos] = c;
			++rpos;
			pos = 0;
		}
		++start;

	}
	FILE *fout = fopen("text", "wb");
	for (int i = 0; i < rpos; ++i)
		fwrite(&res[i], 1, 1, fout);
	fclose(fout);
	return 0;
}