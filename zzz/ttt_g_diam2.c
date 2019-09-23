#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
    int d;
    struct s_node *next;
};

struct s_list
{
    struct s_node *head;
};

struct graph 
{
    int maxv;
    struct s_list *adj;
};

struct s_node *new(int d);

struct graph *newgraph(int maxv)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->maxv = maxv;
    g->adj = (struct s_list *)malloc(sizeof(struct s_list) * (maxv + 1));
    for (int i = 0; i <= maxv; i++)
    {
        g->adj[i].head = NULL;
    }
    return g;
}

void newedge(struct graph *g, int src, int dest)
{
    // p = new(src)
    // p->next = g->adj[dest].head;
    // g->adj[dest].head = p;

}





ft_atoi(char **s)
{
    int nb = 0;

    while (isnum(**s))
    {
        nb = nb * 10 + (**s - '0');
        (*s)++;
    }
    if (**s)
        (*s)++;
    return nb;
}

int find_maxv(char *s)
{
    int res = 0;
    while (isnum(*s))
    {
        int tmp = ft_atoi()
    }
}






void g_diam(char *s)
{
    int maxv = find_maxv(s);

}

int main(int ac, char **av)
{
    if (ac = 2)
        g_diam(av[1]);
}










