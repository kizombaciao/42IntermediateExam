#include <stdio.h> // del

#include <unistd.h>
#include <stdlib.h>

struct s_node
{
	int data;
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

struct s_node *new(int d)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = d;
	p->next = NULL;
	return p;
}

struct graph *newgraph(int maxv)
{
    struct graph *g;
    g = (struct graph *)malloc(sizeof(struct graph));
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
    struct s_node *p = new(src);
    p->next = g->adj[dest].head;
    g->adj[dest].head = p;

    struct s_node *q = new(dest);
    q->next = g->adj[src].head;
    g->adj[src].head = q;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int isnum(char c)
{
	return (c >= '0' && c <= '9');
}
void ft_putnbr(int nb)
{
    if (nb >= 10) // ??
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0'); // ??
}

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int ft_atoi(char **s)
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

int findmaxv(char *s)
{
    int res = 0;

    while (*s) // no isnum() here !!!
    {
        res = max(res, ft_atoi(&s));
    }
    return res;
}

void dfsu(struct graph *g, int v, int vis[], int cl, int *res)
{
    vis[v] = 1;

    for (struct s_node *p = g->adj[v].head; p; p = p->next)
    {
        if (!vis[p->data])
        {
            *res = max(*res, cl + 1);
            dfsu(g, p->data, vis, cl + 1, res);
        }
    }
    vis[v] = 0;
}

void dfs(struct graph *g, int maxv)
{
    int vis[maxv + 1];
    int res = 2;


    for (int i = 0; i <= maxv; i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i <= maxv; i++)
    {
        dfsu(g, i, vis, 1, &res); // cl = 1 ??
    }
    printf("222a %d\n", res);
    ft_putnbr(res);
}

void pr(struct graph *g, int maxv)
{
    for (int i = 0; i <= maxv; i++)
    {
        for (struct s_node *p = g->adj[i].head; p; p = p->next)
        {
            printf("%d %d\n", i, p->data);
        }
    }
}

void gd(char *s)
{
    int maxv = findmaxv(s);
    struct graph *g = newgraph(maxv);
    while (*s)
    {
        int src = ft_atoi(&s);
        int dest = ft_atoi(&s);
        newedge(g, src, dest);
    }
    pr(g, maxv);
    dfs(g, maxv);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        gd(av[1]);
    }
    ft_putchar('\n');
	return (0);
}