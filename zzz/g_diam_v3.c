

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

struct s_node *new(int d)
{
	struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = d;
	p->next = NULL;
	return p;
}

void newedge(struct graph *g, int src, int dest)
{
	struct s_node *p = new(dest);
	p->next = g->adj[src].head;
	g->adj[src].head = p;

	struct s_node *q = new(src);
	q->next = g->adj[dest].head;
	g->adj[dest].head = q;
}
//////////////////////////////////////

void ft_putnbr(int n)
{
	if ()
	{
		//putchar
		//putchar
		// n = n % 10 * -1;
		//n *= -1;
	}
	if (n < 0)
	{
		//putchar -
		nb *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
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
}

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

void dfs_util(struct graph *g, int v, int visited[], int curlen, int *res)
{
	visited[v] = 1;
	for (struct s_node *p = g->adj[v].head; p; p = p->next)
	{
		if (!visited[p->data])
		{
			*res = max(*res, curlen + 1);
			dfs_util(g, p->data, visited, curlen + 1, res);
		}
	}
	visited[v] = 0;
}

void dfs(struct graph *g, int maxv)
{
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
	ft_putnbr(res);
}

void g_diam()
{
	int maxv = find_maxv(s);

	while (*s)
	{
		int src = ft_atoi(&s);
		int des = ft_atoi(&s);
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
}










