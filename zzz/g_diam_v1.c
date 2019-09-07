
//#include "queue_g_diam.c"
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
	int u; // smallest vertex
	int v; // largest vertex
	struct s_list *arr;
};

typedef struct s_pair
{
	int nodeidx;
	int maxdist;
} t_pair;
// QUEUE:
/////////////////////////////////////////////
struct s_queue {
        struct s_node *first;
        struct s_node *last;
};   
struct s_node *new(int d)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = d;
	p->next = NULL;
	return p;
}
struct s_queue *init(void)
{
	struct s_queue *q;

	q = (struct s_queue *)malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return q;
}
void enqueue(struct s_queue *queue, int data)
{
	struct s_node *p;
	struct s_queue *q = queue;

	if (!q)
		return ;

	p = new(data);

	// no nodes
	if (q->first == NULL)
	{
		q->first = p;
		q->last = p;
	}
	// 1 node
	else if (q->first == q->last)
	{
		q->last->next = p;
		q->last = p;
	}
	// 2 or more nodes
	else
	{
		q->last->next = p;
		q->last = p;	
	}
}
int dequeue(struct s_queue *queue)
{
	struct s_node *t;
	int d;
	struct s_queue *q = queue;

	if (!q)
		return -1; // return NULL!

	// no nodes
	if (!q->first)
		return -1;

	// if 1 node
	if (q->first == q->last)
	{
		t = q->first;
		d = q->first->data;
		q->first = q->first->next;
		q->last = q->last->next;
	}
	else
	{
		t = q->first;
		d = q->first->data;
		q->first = q->first->next;
	}
	free(t);
	return d;
}
int peek(struct s_queue *queue)
{
	struct s_queue *q = queue;

	if (!q || !q->first)
		return -1;

	return (q->first->data);
}
int isEmpty(struct s_queue *queue)
{
	struct s_queue *q = queue;

	if (!q || !q->first)
		return 1;
	return 0;	
}
////////////////////////////////////////////
void newedge(struct graph *g, int src, int dest)
{
	struct s_node *p;

	p = new(dest);
	p->next = g->arr[src].head; // old head
	g->arr[src].head = p; // new head

	p = new(src);
	p->next = g->arr[dest].head;
	g->arr[dest].head = p;
}
struct graph *newgraph(int u, int v)
{
	int i;
	struct graph *g;

	g = (struct graph *)malloc(sizeof(struct graph));
	g->u = u;
	g->v = v;

	// CANNOT DO (v - u + 1) unless you want to reindex mapping !!!
	g->arr = (struct s_list *)malloc(sizeof(struct s_list) * ((v) + 1));
	for (i = 0; i <= v; ++i) // <<<<<<<<<<<<<<<<< smallest ???
	{
		g->arr[i].head = NULL;
		// why is it . before head instead of -> ???
	}
	return (g);
}

int ft_atoi(char **s)
{
	//int i = 0;
	int nb = 0;

	//printf("222a %s\n", *s);
	while (isnum(**s))
	{
		//printf("222c %c\n", s[i]);
		nb = nb * 10 + (**s - '0');
		(*s)++;
	}
	//printf("222b %s     %d\n", *s, nb);

	// pre-processing for the next string
	if (**s) // **s is equivalent to the char
		(*s)++; // increment the string *s by 1
		// b/c we know each num is always followed by space/hyphen
	return (nb);
}


void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)b;
	while (d < (unsigned char *)b + n)
		*(d++) = (unsigned char)c;
	return (b);
}

t_pair bfs(struct graph *g, int u, int v)
{
	int dist[v + 1];
	struct s_queue *q;
	t_pair p;

	ft_memset(dist, -1, sizeof(dist));
	//printf("333a  %d\n", dis[1]);

	q = init();
	enqueue(q, u);
	dist[u] = 1;

	while (!isEmpty(q))
	{
		int d = dequeue(q);
		//printf("555a %d\n", d);

		for (struct s_node *p = g->arr[d].head; p != NULL; p = p->next)
		{
			
			printf("444a d= %d  p->data= %d\n", d, p->data);
			
			if (dist[p->data] == -1)
			{
				enqueue(q, p->data);
				dist[p->data] = dist[d] + 1;
				printf("888a p->data= %d dist[p->data]= %d // %d %d\n", \
					p->data, dist[p->data], d, dist[d]);	
			}				
			/*if (dist[p->data] < dist[d] + 1)
			{
				dist[p->data] = dist[d] + 1;
			}*/
		}
	}

	p.maxdist = 0;
	for (int i = 0; i <= v; i++) // <<<<< this has to start from smallest!!!
	{
		//printf("777a  %d  %d\n", i, dist[i]);
		if (dist[i] > p.maxdist)
		{
			p.maxdist = dist[i];
			p.nodeidx = i;
		}
	}

	return p;
}

void longest_path_length(struct graph *g, int u, int v)
{
	t_pair p1, p2;

	u = 8; // DELETE!!!

	p1 = bfs(g, u, v); // <<<<<<<<<<<<<<<<<<< HARD WIRED !!!
	printf("\nnodeidx %d  maxdist %d\n\n", p1.nodeidx, p1.maxdist);
	//printf("%d\n", p1.maxdist);

	p2 = bfs(g, p1.nodeidx, v); // <<<<<<< HARDWIRED !!!

	printf("From %d to %d of distance %d by nodes.\n", \
		p1.nodeidx, p2.nodeidx, p2.maxdist); 

}

int find_min_u(char *s)
{
	//int i = 0;
	int res = ft_atoi(&s);
	int tmp;

	while (isnum(*s))
	{
		tmp = ft_atoi(&s);
		res = min(tmp, res);
	}
	return (res);
}

// returns the largest vertex 
int find_max_v(char *s)
{
	//int i = 0;
	int res = 0;
	int tmp;

	while (isnum(*s))
	{
		tmp = ft_atoi(&s);
		res = max(tmp, res);
	}
	return (res);
}

void pr(struct graph *g)
{
	struct s_node *p;

	printf("\nAdjacency list\n");
	for (int i = g->u; i <= g->v; i++)
	{
		p = g->arr[i].head;
		printf("vertex %d:  head", i);
		while (p)
		{
			printf(" -> %d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

// construct adjacent list
// bfs() from start
// bsf() from end
struct graph *g_diam(char *s)
{
	int u = find_min_u(s);
	int v = find_max_v(s);
	struct graph *g = newgraph(u, v); // v or v + 1 ???
	printf("222a %s u = %d  v = %d\n\n", s, u, v);
	while (*s)
	{
		int src = ft_atoi(&s);
		int dest = ft_atoi(&s);
		printf("222b %d %d %d\n", v, src, dest);
		
		newedge(g, src, dest);
	}
	pr(g);

	longest_path_length(g, u, v);
	return NULL;
}

int main(int ac, char **av)
{
	struct graph *g;

	if (ac == 2)
	{
		g = g_diam(av[1]);
	}
	//pr(g);
	return (0);
}