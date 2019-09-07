// https://math.stackexchange.com/questions/1225842/longest-path-in-undirected-unweighted-graph

#include <stdio.h>
#include <stdlib.h>

#define isnum(x) x>= '0' && x <= '9'
#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b

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
	int min_v; // smallest vertex
	int max_v; // largest vertex
	struct s_list *adj;
};

////////////////////////////////////////////
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
	struct s_node *p;

	p = new(dest);
	p->next = g->adj[src].head; // old head
	g->adj[src].head = p; // new head

	p = new(src);
	p->next = g->adj[dest].head;
	g->adj[dest].head = p;
}
struct graph *newgraph(int min_v, int max_v)
{
	int i;
	struct graph *g;

	g = (struct graph *)malloc(sizeof(struct graph));
	g->min_v = min_v;
	g->max_v = max_v;

	// CANNOT DO (v - u + 1) unless you want to reindex mapping !!!
	g->adj = (struct s_list *)malloc(sizeof(struct s_list) * ((max_v) + 1));
	for (i = 0; i <= max_v; ++i) // <<<<<<<<<<<<<<<<< smallest ???
	{
		g->adj[i].head = NULL;
		// why is it . before head instead of -> ???
	}
	return (g);
}
////////////////////////////////////////////
void pr(struct graph *g)
{
	struct s_node *p;
	printf("\nAdjacency list\n");
	for (int i = g->min_v; i <= g->max_v; i++)
	{
		p = g->adj[i].head;
		printf("vertex %d:  head", i);
		while (p)
		{
			printf(" -> %d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

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

int find_min_v(char *s)
{
	int res = ft_atoi(&s);
	//int tmp;
	while (isnum(*s))
	{
		int tmp = ft_atoi(&s);
		res = min(tmp, res);
	}
	return (res);
}

// returns the largest vertex 
int find_max_v(char *s)
{
	int res = 0;
	//int tmp;
	while (isnum(*s))
	{
		int tmp = ft_atoi(&s);
		res = max(tmp, res);
	}
	return (res);
}

void dfs_util(struct graph *g, int v, int visited[])
{
    visited[v] = 1;

    printf("222a  %d\n", v);
    
    for (struct s_node *p = g->adj[v].head; p; p = p->next)
    {
        if (!visited[p->data])
            dfs_util(g, p->data, visited);
    }
}

void dfs(struct graph *g, int min_v, int max_v)
{
    int visited[max_v];

    for (int i = 0; i <= max_v; i++) // can also use b_zero() or memset
        visited[i] = 0;

    // start travesal at min_v ??????????
    dfs_util(g, min_v, visited);
}
struct graph *g_diam(char *s)
{
	int min_v = find_min_v(s);
	int max_v = find_max_v(s);
	struct graph *g = newgraph(min_v, max_v); // careful with v
	printf("222a %s u = %d  v = %d\n\n", s, min_v, max_v);
	while (*s)
	{
		int src = ft_atoi(&s);
		int dest = ft_atoi(&s);
		printf("222b %d %d %d\n", max_v, src, dest);
		newedge(g, src, dest);
	}
	pr(g);

    dfs(g, min_v, max_v);
	return NULL;
}

int main(int ac, char **av)
{
	struct graph *g;

	if (ac == 2)
		g = g_diam(av[1]);
	return (0);
}
