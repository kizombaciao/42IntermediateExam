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
    struct s_stack *s = (struct s_stack *)malloc(sizeof(struct s_stack));
    s->top = NULL;
    return s;
}

void *pop(struct s_stack *stack)
{
    struct s_stack *s = stack;

    if (!s)
        return NULL;
    if (!s->top)
        return NULL;

    struct s_stack *p = s->top;
    void *c = s->top->content;
    s->top = s->top->next;
    free (p);
    return c;
}

void push(struct s_stack *stack, void *content)
{
    struct s_stack *s = stack;
    if (!s)
        return NULL;

    struct s_node *p = new(content);

    // 0
    if (!s->top)
        s->top = p;
    // 1+
    else
    {
        p->next = s->top;
        s->top = p;
    }
}

void *peek(struct s_stack *stack)
{
    struct s_stack *s = stack;
    if (!s)
        return NULL;
    if (!s->top)
        return NULL;

    return (s->top->content);    
}

int isEmpty(struct s_stack *stack)
{
    struct s_stack *s = stack;

    if (!s)
        return 1;
    if (!s->top)
        return 1;
    return 0;    
}
