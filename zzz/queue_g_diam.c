// PASS!!!
//#include "g_diam_v1.c"
#include <stdlib.h>
/*
struct s_node
{
	int data;
	struct s_node *next;
};
*/
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

