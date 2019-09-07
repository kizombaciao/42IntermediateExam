// https://github.com/Manmeet2018/42_Exam-C-Intermediate/blob/master/level5/g_diam/g_diam1.c

#include <stdio.h>
#include <stdlib.h>

#define isnum(x) x>= '0' && x <= '9'

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
	int v; // vertice
	struct s_list *arr;
};
int ft_atoi(char **s)
{
	int i = 0;
	int nb = 0;

	//printf("222a %s\n", *s);
	while (isnum(**s))
	{
		//printf("222c %c\n", s[i]);
		nb = nb * 10 + (**s - '0');
		(*s)++;
	}
	//printf("222b %s     %d\n", *s, nb);
	if (**s) // **s is equivalent to the char
		(*s)++; // increment the string *s by 1
		// b/c we know each num is always followed by space or hyphen
	return (nb);
}
int max(int a, int b)
{
	return ((a > b ? a : b));
}
int find_v(char *s)
{
	int i = 0;
	int res = 0;
	int tmp;

	while (isnum(*s))
	{
		tmp = ft_atoi(&s);
		res = max(tmp, res);
	}
	return (res);
}
struct s_node *newnode(int dest)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = dest;
	p->next = NULL;
	return (p);
}
// QUEUE:
void newedge(struct graph *g, int src, int dest)
{
	struct s_node *p;

	p = newnode(dest);
	p->next = g->arr[src].head; // old head
	g->arr[src].head = p; // new head

	p = newnode(src);
	p->next = g->arr[dest].head;
	g->arr[dest].head = p; // syntax g->arr[dest]->head ???
}
struct graph *newgraph(int v)
{
	int i;
	struct graph *g;

	g = (struct graph *)malloc(sizeof(struct graph));
	g->v = v;

	g->arr = (struct s_list *)malloc(sizeof(struct s_list) * v);
	for (i = 0; i < v; ++i)
	{
		g->arr[i].head = NULL;
		// why is it . before head instead of -> ???
	}
	return (g);
}

void solve(struct graph *g, int v, int visited[], int i, int len, int *long_len)
{
	visited[i] = 1;
	struct s_node *t;

	t = g->arr[i].head;
	while (t)
	{
		if (!visited[t->data])
		{
			*long_len = max(*long_len, len + 1);
			solve(g, v, visited, t->data, len + 1, long_len);
		}
		t = t->next;
	}
	visited[i] = 0; // backtrack ???
}

struct graph *g_diam(char *s)
{
	int i;
	int v;
	int src, dest;
	struct graph *g;
	int *visited;
	int long_len; // ???

	v = find_v(s);
	g = newgraph(v + 1); // v or v + 1 ???

	while (*s)
	{
		src = ft_atoi(&s);
		dest = ft_atoi(&s);
		printf("%d %d %d\n", v, src, dest);
		newedge(g, src, dest);
	}

	visited = (int *)malloc(sizeof(int) * (v + 1));
	for (i = 0; i <= v; i++)
	{
		visited[i] = 0; // might use memset or b_zero!!!
	}

	long_len = 2; // ???
	for (i = 0; i <= v; i++)
	{
		solve(g, v + 1, visited, i, 1, &long_len);
	}
	return (g);
}

///////////////////////////////////////////////
void pr(struct graph *g)
{
	int v;
	struct s_node *p;

	for (v = 0; v < g->v; v++)
	{
		p = g->arr[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (p)
		{
			printf("-> %d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

int main(int ac, char **av)
{
	struct graph *g;

	if (ac == 2)
	{
		g = g_diam(av[1]);
	}
	pr(g);
	return (0);
}


/*
int isnum(char c)
{
	return (c >= '0' && c <= '9');
}
*/