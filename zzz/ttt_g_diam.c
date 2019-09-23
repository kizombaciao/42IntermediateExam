


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
	struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = d;
	p->next = NULL;
	return p;
}
struct graph *g(int maxv)
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
	if (!g)
		return ;

	struct s_node *p = new(src);
	p->next = g->adj[dest].head;
	g->adj[dest].head = p;

	struct s_node *p = new(dest);
	p->next = g->adj[src].head;
	g->adj[src].head = p;
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
void ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}
//////////////////////////////////////
int find_maxv(char *s)
{
	int res = 0;
	while (*s)
	{
		int tmp = ft_atoi(&s);
		if (tmp > res)
			res = tmp;
	}
	return res;
}

void dfsu(g, int v, int vis[], int cl, int *res)
{
	if (!g)
		return;

	vis[v] = 1;
	for (struct s_node *p = g->adj[v].head; p; p = p->next)
	{
		if (!v[p->data])
		{
			*res = max(*res, cl + 1);
			dfsu(g, p->data, vi, cl + 1, res);			
		}
	}
	vi[v] = 0;
}

void dfs(struct graph *g, int maxv)
{
	int i;
	int res = 2;
	int vis[maxv + 1];

	for (i = 0; i <= max; i++)
	{
		v[i] = 0;
	}
	for (i = 0; i <= maxv; i++)
		dfsu(g, i, vis, 1, &res);
	ft_putnbr(res);
}

void g_diam(char *s)
{
	int maxv = find_maxv(s);
	struct graph *g = newgraph(maxv);

	while (*s)
	{
		int src = ft_atoi(&s);
		int dest = ft_atoi(&s);
		newedge(g, src, dest);
	}
	dfs(g, maxv);
}
// maxv
// newgraph
// atoi
// newedge
// dfs


int main(int ac, char **av)
{
	g_diam(av[1]);	

}










