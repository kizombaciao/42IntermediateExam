#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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

struct s_node *new(int v)
{
    struct s_node *r = (struct s_node *)malloc(sizeof(struct s_node));
    r->value = v;
    r->next = NULL;
    return r;
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
	g->adj[src].head = q;;
}

////////////////////////////////////////////
int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int isnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb >=0)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
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
	int res = ft_atoi(&s);
	while (*s)
	{
		res = max(res, ft_atoi(&s));
		s++;
	}
	return res;
}

// cl ???
void dfsu(struct graph *g, int i, int vis[], int cl, int *res)
{
	vis[i] = 1;

	for (struct s_node *p = g->adj[i].head; p; p = p->next)
	{
		if (!vis[p->value])
		{
			*res = max(*res, cl);
			dfsu(g, p->value, vis, cl + 1, res);
		}
	}
	vis[i] = 0;
}

void dfs(struct graph *g, int maxv)
{
	int res = 2;
	int vis[maxv + 1];

	for (int i = 0; i <= maxv; i++)
	{
		vis[i] = 0;
	}
	for (int i = 0; i <= maxv; i++)
	{
		dfsu(g, i, vis, 0, &res);
	}
	ft_putnbr(res);
}


void g_diam(char *s)
{
	int maxv;

	maxv = findmaxv(s);
	struct graph *g = newgraph(maxv);

	while (*s)
	{
		int src = ft_atoi(&s);
		int dest = ft_atoi(&s);
		newedge(g, src, dest);
		s++;
	}
	dfs(g, maxv);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		g_diam(av[1]);
	}
	write(1, "\n", 1);
}
