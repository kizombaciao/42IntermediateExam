// STILL NEED TO BE TESTED!!!

//#include <stdio.h> // del
#include <stdlib.h>

struct s_node {
        void          *content;
        struct s_node *next;
};

struct s_stack {
        struct s_node *top;
};

struct s_node *new(void *c)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
	p->next = NULL;
	return (p);
}

struct s_stack *init(void)
{
	struct s_stack *s;

	s = (struct s_stack *)malloc(sizeof(struct s_stack));
	s->top = NULL;
	return (s);
}

void *pop(struct s_stack *stack)
{
	struct s_node *t;
	void *c;

	if (!stack || !stack->top) // POSSIBLY, SEG DEF B/C OF STACK-TOP ???
		return NULL;

	t = stack->top;
	c = stack->top->content;
	stack->top = stack->top->next;
	free(t);
	return(c);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *p;

	if (!stack)
		return;

	p = new(content);
	if (stack->top == NULL)
		stack->top = p;
	else
	{
		p->next = stack->top;
		stack->top = p;
	}
}

void *peek(struct s_stack *stack)
{
	void *c;

	if (!stack)
		return NULL;

	if (stack->top == NULL)
	{
		return NULL;
	}	
	else
	{
		c = stack->top->content;
		return (c);
	}
}

int isEmpty(struct s_stack *stack)
{
	if (!stack)
		return 1;
	if (stack->top == NULL)
	{
		return 1;
	}
	return (0);
}
/*
int main()
{
	struct s_stack *s;
	struct s_node *n;
	int n1 = 123;
	void *p = &n1;

	s = init();
	push(s, p);
	printf("PEEK:  %d\n", *(int *)peek(s));
	printf("POP:  %d\n", *(int *)pop(s));
	printf("ISEMPTY:  %d\n", isEmpty(s));

}
*/
