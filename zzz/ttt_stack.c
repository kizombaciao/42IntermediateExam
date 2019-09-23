#include <stdio.h>
#include <stdlib.h>

    struct s_node {
        void          *content;
        struct s_node *next;
    };
    struct s_stack {
        struct s_node *top;
    };

struct s_stack *init(void)
{
	struct s_stack *s = (struct s_stack *)malloc(sizeof(struct s_stack));
	s->top = NULL;
	return s;
}
struct s_node *new(void *c)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
	p->next = NULL;
	return (p);
}
  
void *pop(struct s_stack *stack)
{
	if (!stack)
		return NULL;

	if (stack->top == NULL)
	{
		return NULL;
	}

	struct s_node *t = stack->top;
	void *c = stack->top->content;

	stack->top = stack->top->next;
	free(t);
	return c;
}
    
void push(struct s_stack *stack, void *content)
{
	// return

	struct s_node *p = new(content);
	if (stack->top == NULL)
	{
		stack->top = p;
	}
	else
	{
		p->next = stack->top;
		stack->top = p;
	}
}
    
void *peek(struct s_stack *stack)
{
	// if s || s->top return NULL
	return (stack->top->content);

}
    
int isEmpty(struct s_stack *stack)
{
	// if s || s->top , 1
	return 0;

}
