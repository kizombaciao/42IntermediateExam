#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	void *content;
	struct s_node *next;
};

struct s_stack
{
	struct s_node *top;
};

struct s_node *new(void *content)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = content;
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
	struct s_node *p;
	void *tmp;

	if (stack == NULL || stack->top == NULL)
		return NULL;
	p = stack->top;
	tmp = stack->top->content;
	stack->top = stack->top->next;
	free(p);
	return (tmp);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *p;

	if (stack == NULL)
		return;

	p = new(content);
	p->next = stack->top;
	stack->top = p;
}

void *peek(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return NULL;
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return 1;
	else
		return 0;
}
////////////////////////////////////
int 	main(void)
{
	char a[] = "aaaaa";			(void)a;
	char b[] = "bbbbb";			(void)b;
	char c[] = "ccccc";			(void)c;
	char d[] = "dddddicks";		(void)d;
	struct s_stack *stack;
	stack = init(); 			(void)stack;
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	push(stack, a); push(stack, b); push(stack, c); push(stack, d);
	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("isEmpty: %d\n", isEmpty(stack));
	return (0);
}
