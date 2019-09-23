
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

struct graph *newgraph(int maxv)
{
	struct graph *g = (struct graph *)malloc(sizeof(struct graph));
	g->maxv = maxv;
	g->adj = (struct s_list *)malloc(sizeof(struct s_list) * (max_v + 1));

	for (int i = 0; i <= maxv; i++)
	{
		g->adj[i].head = NULL;
	}
	return g;
}

void newedge(struct graph *g, int src, int dest)
{
	struct s_node *p = new(dest);
	p->next = g->adj[src].head;
	g->adj[src].head = p;

	struct s_node *p = new(src);
	p->next = g->adj[dest].head;
	g->adj[dest].head = p;
}
//////////////////////////////////////
void ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb/10);
	}
	ft_putchar(nb % 10 + '0');
}

int ft_atoi(char **s)
{
	int nb = 0;

	while (isnum(**s))
	{
		nb = nb * 10 + (**s % 10 - '0');
		(*s)++;
	}
	if (**s)
		(*s)++;

	return nb;
}

int dfs_util(g, v, visited, cl, *res)
{
	visited[v] = 1;

	for (struct s_node *p = g->adj[v].head; p; p = p->next)
	{
		if (!visited[p->data])
		{
			*res = max(*res, cl + 1);
			dfs_util(g, p->data, visited, cl + 1, res);
		}
	}
	visited[v] = 0;
}

void dfs(g, maxv)
{
	int visited[maxv + 1];
	int res = 2;

	for ()
	{

	}
	for ()
	{
		dfs_util(g, i, visited, 1, &res)
	}

}

void g_diam(char *s)
{
	maxv = find_maxv(s);
	struct graph *g = newgraph(maxv);

	while (*s)
	{
		int src = ft_atoi(&s);
		int dest = ft_atoi(&s);
		newedge(g, src, des);
	}
	dfs(g, maxv);
}
//////////////////////////////////////
int find_maxv(char *s)
{
	int res = 0;

	while (isnum(*s))
	{
		int tmp = ft_atoi(&s);
		res = max(tmp, res);
	}
	return res;
}

int dfs_util(g, v, visited, cl, int *res)
{
	visited[v] = 1;

	for (struct s_node *p = g->adj[v].head; p; p = p->next)
	{
		if (!visited[p->data])
		{
			*res = max(*res, cl + 1);
			dfs_util(g, p->data, visited, cl + 1, *res);
		}
	}
	visited[v] = 0;
}

void dfs(struct graph *g, int maxv)
{
	int res = 0;
	int visited[maxv + 1];
	int res = 2;

	for (int i = 0; i <= maxv; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i <= maxv; i++)
	{
		dfs_util(g, i, visited, 1, &res);
	}
	// p res
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

int main(int ac, char **av)
{
	if (ac == 2)
	{
		g_diam(av[1]);
	}
	ft_putchar('\n');
	return 0;
}