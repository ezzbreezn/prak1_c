#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
	char *s;
	struct list *prev, *next;
};

struct list *add(struct list *l, char *s)
{
	if (l == NULL)
	{
		l = (struct list *)malloc(sizeof(struct list));
		l -> s = (char *)malloc(sizeof(char)*(strlen(s)+1));
		strcpy(l -> s, s); 
		l ->s[strlen(s)] = '\0';
		l -> prev = NULL, l -> next = NULL;
		return l;
	}
	struct list *p = l;
	while(p -> next != NULL) p = p -> next;
	p ->next = (struct list *)malloc(sizeof(struct list));
	p -> next -> s = (char *)malloc(sizeof(char) * (strlen(s)+1));
	strcpy(p -> next ->s,s);
	p -> next ->s[strlen(s)] = '\0';
	p -> next -> prev = p, p -> next -> next = NULL;
	return l;
}

void show(struct list *l)
{
	struct list *p = l;
	while(p != NULL)
	{
		printf("%s\n", p -> s);
		p = p -> next;
	}
	//printf("done\n");
}

struct list *goaway(struct list *l)
{
	if (l == NULL || l -> next == NULL) return l;
	int f = 0;
	struct list *p = l; p = p -> next;
	while (p -> next != NULL)
	{
		printf("saa\n");
		if (p->prev->s[strlen(p->prev->s)-1]==p->next->s[0]&&(p->s[strlen(p->s)-1]!=p->next->s[0]||p->s[0]!=p->prev->s[strlen(p->prev->s)-1]))
		{
			f =1;
			p -> prev -> next = p -> next;
			p -> next -> prev = p -> prev;
			free(p); break;
		}
		p = p -> next;
	}
	printf("huiii\n");
	printf("%d\n", f);
	if (!f)
	{
		if(p->s[0]!=p->prev->s[strlen(p->prev->s)-1])
		{
			p -> prev -> next = NULL; free(p);
		}
		else if(l -> s[strlen(l->s)-1]!=l->next->s[0])
		{
			l = l -> next;
			free(l -> prev);
			l -> prev = NULL;
		}
	}
	printf("zbs\n");
	return l;
}

int main(void)
{
	struct list *l = NULL;
	char s[100];
	scanf("%s", s);
	while(strcmp("sas", s) != 0)
	{
		l = add(l, s);
		//printf("zaebis\n");
		scanf("%s", s);
	}
	show(l);
	l = goaway(l);
	show(l);
	return 0;
}