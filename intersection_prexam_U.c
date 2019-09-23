// FINALLY PASSED !!!
// TEST THIS CODE !!!  NOT SURE WHY IT SAID IT DID NOT COMPILE ???

#include <stdlib.h>
//#include <stdio.h>

struct s_node
{
	void *content;
	struct s_node *next;
};
int len(struct s_node *r)
{
	int i = 0;
	if (!r)
		return 0;
	while (r)
	{
		i++;
		r = r->next;
	}
	return (i);
}

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	int i = 0;
	int d;
	int len1;
	int len2;

	len1 = len(lst1);
	len2 = len(lst2);

	if (len1 > len2)
	{
		d = len1 - len2;
		while (i < d)
		{
			lst1 = lst1->next;
			i++;
		}
	}
	else 
	{
		d = len2 - len1;
		while (i < d)
		{
			lst2 = lst2->next;
			i++;
		}
	}
	while (lst1 && lst2)
	{
		if (lst1 == lst2)
		{
			return (lst1); // don't i need to return the content ? no
			// instructions are not super clear.
		}
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return NULL;
}
/////////////////////////////////////////////////////////
/*
struct s_node* b(void* v) {
	struct s_node* new;
	new = malloc(sizeof(struct s_node));
	new->content = v;
	new->next = 0;
	return new;
}
int main() {
	struct s_node* a;
	struct s_node* c;
	struct s_node* ret;

	a = b("a");
	a->next = b("b");
	a->next->next = b("c");
	a->next->next->next = b("d");
	a->next->next->next->next = b("e");
	a->next->next->next->next->next = b("f");

	c = b("g");
	c->next = b("h");
	c->next->next = b("i");
	c->next->next->next = b("j");
	c->next->next->next->next = b("k");
	c->next->next->next->next->next = b("l");

	ret = iii(a, c);
	printf("%s\n", ret ? ret->content : 0);

	c->next->next = a->next->next->next; // intersection created
	ret = iii(a, c);
	printf("%s\n", ret ? ret->content : 0);
	return 0;
}
*/