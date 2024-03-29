#include <stdlib.h>

struct              s_node
{
    void            *content;
    struct s_node   *next;
};
struct              s_stack
{
    struct s_node   *top;
};

struct s_stack      *init(void)
{
    struct s_stack  *stack = malloc(sizeof(stack));

    stack->top = NULL;
    return (stack);
}

void                *pop(struct s_stack *stack)
{
    void            *content = NULL;
    struct s_node   *node;

    if (stack->top)
    {
        node = stack->top;
        content = stack->top->content;
        stack->top = stack->top->next;
        free(node);
        node = NULL;
    }
    return (content);
}

void                push(struct s_stack *stack, void *content)
{
    struct s_node   *node = malloc(sizeof(node));
    node->content = content;
    node->next = stack->top;
    stack->top = node;
    return ;
}

void                *peek(struct s_stack *stack)
{
    return (stack->top ? stack->top->content : NULL);
}

int                 isEmpty(struct s_stack *stack)
{
    return (!stack->top ? 1 : 0);
}

/*
#include <stdio.h>
int                 main(void)
{
    struct s_stack  *stack = init();
    char            *content[][1] = {
      "Uno",
      "Dos",
      "Tres",
      "Cuatro",
      "Cinco"
    };
    for (int i = 0; i < 5; i += 1)
    {
        push(stack, *content[i]);
        printf("Content : %s\n", peek(stack));
        printf("Empty   : %s\n", (isEmpty(stack) ? "yes" : "no"));
    }
    for (int i = 5; i > 0; i -= 1)
    {
        pop(stack);
        printf("Content : %s\n", peek(stack));
        printf("Empty   : %s\n", (isEmpty(stack) ? "yes" : "no"));
    }
    return (0);
}


