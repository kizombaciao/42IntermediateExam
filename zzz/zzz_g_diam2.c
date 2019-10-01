//#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

struct s_node 
{
    int value;
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

struct s_node *new(int v)
{
    struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
    p->value = v;
    p->next = NULL;
    return p;
}

void newedge(struct graph *g, int s, int d)
{

    struct s_node *q = new(d);
    q->next = g->adj[s].head; // becareful, you had pointer p instead of q here!
    g->adj[s].head = q;

    struct s_node *p = new(s);
    p->next = g->adj[d].head;
    g->adj[d].head = p;

}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int isnum(char c)
{
    return (c >= '0' && c <= '9');
}

void ft_putnbr(int n)
{
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int ft_atoi(char **s)
{
    int nb = 0;
    while (isnum(**s))
    {
        nb = (nb * 10) + (**s - '0');
        (*s)++;
    }
    if (**s)
        (*s)++;
    return nb;
}

int findmaxv(char *s)
{
    int res = 0;

    while (isnum(*s)) // use isnum()
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
        if (!vis[p->value])
        {
            *res = max(*res, cl + 1);
            dfsu(g, p->value, vis, cl + 1, res);
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
        dfsu(g, i, vis, 1, &res); // ??? arguments?
    }
    ft_putnbr(res);
}
/*
void pr(struct graph *g)
{
	struct s_node *p;
	printf("\nAdjacency list\n");
	for (int i = 0; i <= g->maxv; i++)
	{
		p = g->adj[i].head;
		printf("vertex %d:  head", i);
		while (p)
		{
			printf(" -> %d", p->value);
			p = p->next;
		}
		printf("\n");
	}
}
*/
void gd(char *s)
{
    int maxv = findmaxv(s); // s or &s ???

    struct graph *g = newgraph(maxv);

    while (*s)
    {
        int src = ft_atoi(&s);
        int dest = ft_atoi(&s);
        newedge(g, src, dest);

    }
//    pr(g);
    dfs(g, maxv);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        gd(av[1]);
    }
    ft_putchar('\n');
    return 0;
}








