
#include <stdio.h>
#include <stdlib.h>

struct s_node
{
    int v;
    struct s_node *l;
    struct s_node *r;
}

int total_nodes(struct s_node *r)
{
    if (!r)
        return 0;
    return (1 + total_nodes(r->l) + total_nodes(r->r));
}

int can_split(struct s_node *n)
{
    int t_nodes = total_nodes(n);
    
}

struct s_node *b(int v)
{
    struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
    new->v = v;
    new->l = new->r = 0;
    return new;
}

int main()
{
    struct s_node *ex1 = b(28);
    ex1->l = b(51);
    ex1->l->l = b(26);
    ex1->l->l->l = b(76);
    ex1->l->l->r = b(13);
    ex1->l->r = b(48);
    
    printf("%d\n", can_split(ex1));
}