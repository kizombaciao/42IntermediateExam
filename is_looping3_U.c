// https://github.com/Manmeet2018/42_Exam-C-Intermediate/blob/master/level2/is_looping/is_looping_2.c
/************************************** #### PASSED FINAL EXAM #### *************************************/
#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *next;
};
int    is_looping(struct s_node *node)
{
	while(node)
	{
		if(node->value == -1)
			return 1;
		node->value = -1; // leave a breadcrumb for each node we visit
		node = node->next;
	}
	return 0;
}
struct s_node *new (int item)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->next = NULL;
	node->value = item;
	return node;
}
int main(void)
{
	struct s_node *l;
	l = new (1);
	l->next = new (2);
	l->next->next = new (3);
	l->next->next->next = new (4);
	l->next->next->next->next = l;
	printf("The value of is_looping is %d\n", is_looping(l));

	struct s_node *a = new (1);
	a->next = new (2);
	a->next->next = new (3);
	a->next->next->next = new (4);
	a->next->next->next->next = new (5);
	printf("The value of is_looping is %d\n", is_looping(a));
	return 0;
}