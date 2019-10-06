//#include <stdio.h> // del

#include <stdlib.h>

struct s_node {
    void *content;
    struct s_node *next;
};

struct s_queue {
    struct s_node *first;
    struct s_node *last;
};

struct s_node *new(void *c)
{
	struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
	p->next = NULL;
	return p;
}

struct s_queue *init(void)
{
	struct s_queue *q = (struct s_queue *)malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return q;
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_queue *q = queue;
	if (!q)
		return ;

	struct s_node *p = new(content);

	// empty
	if (q->first == NULL)
	{
		q->first = p;
		q->last = p;
	}
	// one entry
	else if (q->first == q->last)
	{
		q->first->next = p;
		q->last = p;
	}
	else
	{
		q->last->next = p;
		q->last = p;
	}
}

void *dequeue(struct s_queue *queue)
{
	struct s_queue *q = queue;
	if (!q)
		return NULL;

	// empty
	if (q->first == NULL)
		return NULL;

	struct s_node *p;
	void *c;

	// one entry
	if (q->first == q->last)
	{
		p = q->first;
		c = q->first->content;
		q->first = NULL;
		q->last = NULL;
		free(p);
		return c;
	}
	else
	{
		p = q->first;
		c = q->first->content;
		q->first = q->first->next;
		free(p);
		return c;
	}
}

void *peek(struct s_queue *queue)
{
	struct s_queue *q = queue;
	if (!q)
		return NULL;

	if (q->first == NULL)
		return NULL;

	return q->first->content;
}

int isEmpty(struct s_queue *queue)
{
	struct s_queue *q = queue;
	if (!q)
		return 1;
	if (q->first == NULL)
		return 1;
	return 0;
}

/*
int main()
{
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	void *p1 = &n1;
	void *p2 = &n2;
	void *p3 = &n3;

	struct s_queue *q = init();

	printf("%d\n", isEmpty(q));
	enqueue(q, p1);
	printf("%d\n", isEmpty(q));
	enqueue(q, p2);
	enqueue(q, p3);
	printf("%d\n", *(int *)dequeue(q));
	printf("%d\n", *(int *)peek(q));
	printf("%d\n", *(int *)dequeue(q));
	printf("%d\n", isEmpty(q));
	printf("%d\n", *(int *)peek(q));
	printf("%d\n", *(int *)dequeue(q));
	printf("%d\n", isEmpty(q));
	printf("\n");		
	
	enqueue(q, p1);
	enqueue(q, p2);
	printf("%d\n", *(int *)dequeue(q));
	printf("%d\n", *(int *)peek(q));
	printf("%d\n", *(int *)dequeue(q));
	printf("%d\n", isEmpty(q));
}
*/
