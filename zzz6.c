// range_comb.c
#include <stdio.h>
//#include <stdlib.h>

void swap(char *x, char *y)
{
	char tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void permute()
{


}

int **range_comb(int n)
{
	char s[1000];

	for (int i = 0; i < n; i++)
	{
		s[i] = i;
	}
	s[n] = '\0';

}

int main()
{
	printf("%d\n", range_comb(3));
}

///////////////////////////////////////
// intersection.c
#include <stdio.h>
#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

int count(struct s_node *n)
{
	struct s_node *p;
	int i = 0;

	while (n)
	{
		i++;
		n = n->next;
	}
	return i;
}

struct s_node *intersection_node(int d, struct s_node *l1, struct s_node *l2)
{
	int i;
	struct s_node *c1;
	struct s_node *c2;

	c1 = l1;
	c2 = l2;

	for (i = 0; i < d; i++)
	{
		if (!c1)
			return NULL;
		c1 = c1->next;
	}
	while (c1 && c2)
	{
		if (c1 == c2)
			return c1;
		c1 = c1->next;
		c2 = c2->next;		
	}
	return NULL;
}

void *intersection(struct s_node *l1, struct s_node *l2)
{
	int c1;
	int c2;
	int d;

	c1 = count(l1)
	c2 = count(l2)

	if (c1 > c2) {
		d = c1 - c2;
		return intersection_node(d, l1, l2);
	}
	else
	{
		d = c2 - c1;
		return intersection_node(d, l2, l1);
	}
}

struct s_node *new(void)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->next = NULL;
}

int main()
{
	struct s_node *l1;
	struct s_node *l2;
	struct s_node *p;
	
	l1 = new();
	l1->next = new();
	l1->next->next = new();
	l1->next->next->next = new();
	l1->next->next->next->next = new();

	l2 = new();
	l2->next = new();
	l2->next->next = new();
	l2->next->next->next = new();
	l2->next->next->next->next = new();

	l2->next->next->next->next = l1->next->next->next->next;

	p = intersection(l1, l2);
}
























