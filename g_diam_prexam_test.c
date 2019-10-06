#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	int i;
	struct graph *g;

	g = (struct graph *)malloc(sizeof(struct graph));
	g->maxv = maxv;
	g->adj = (struct s_list *)malloc(sizeof(struct s_list) * (maxv + 1));
	for (i = 0; i <= maxv; i++)
	{
		g->adj[i].head = NULL;
	}
	return g;
}

struct s_node *new(int d)
{
	struct s_node *p;
	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = d;
	p->next = NULL;
	return p;
}

void newedge(struct graph *g, int src, int dest)
{
	struct s_node *p = new(dest);
	p->next = g->adj[src].head;
	g->adj[src].head = p;

	p = new(src);
	p->next = g->adj[dest].head;
	g->adj[dest].head = p;
}

////////////////////////////////////////////
int isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
//////////////////////////////////////////////////////////
// REMEMBER THIS !!!
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = (nb % -1000000000) * -1; // 1,000,000,000
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10) // equality!
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0'); // remember + '0'
}

// REMEMBER THIS !!!
int ft_atoi(char **s)
{
	int nb = 0;
	while (isnum(**s))
	{
		nb = nb * 10 + (**s - '0');
		(*s)++;
	}
	// pre-processing for the next string
	if (**s) // **s is equivalent to the char
		(*s)++; // increment the string *s by 1
		// b/c we know each num is always followed by space/hyphen
	return (nb);
}
///////////////////////////////////////////////////////
int find_max_v(char *s) //note, only *s, not **s
{
	int res = 0;

	while (isnum(*s)) // not sure if isnum is necessary here, include *s also???
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
			*res = max(*res, curlen + 1); // note cl + 1
			dfs_util(g, p->data, visited, curlen + 1, res); // note cl + 1
		}
	}
	visited[v] = 0; // how is this backtracking ???
}

void dfs(struct graph *g, int maxv)
{
	int visited[maxv + 1];
	int res = 2; // why 2 ?  b/c min is 2 nodes.

	for (int i = 0; i <= maxv; i++)
		visited[i] = 0;

	for (int i = 0; i <= maxv; i++) // i represent initial conditon
		dfs_util(g, i, visited, 1, &res); // start cl at 1 !!!

	ft_putnbr(res);
}

void g_diam(char *s)
{
	int maxv = find_max_v(s);
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
		g_diam(av[1]);
	ft_putchar('\n');
	return 0;
}

/*
DON'T FORGET ISNUM()!!!

 */




















