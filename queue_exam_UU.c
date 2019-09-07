// PASS!!!

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
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
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

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *p;
	struct s_queue *q = queue;

	if (!q)
		return ;

	p = new(content);

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

void *dequeue(struct s_queue *queue)
{
	struct s_node *t;
	void *c;
	struct s_queue *q = queue;

	if (!q)
		return NULL; // return NULL!

	// no nodes
	if (!q->first)
		return NULL;

	// if 1 node
	if (q->first == q->last)
	{
		t = q->first;
		c = q->first->content;
		q->first = q->first->next;
		q->last = q->last->next;
	}
	else
	{
		t = q->first;
		c = q->first->content;
		q->first = q->first->next;
	}
	free(t);
	return c;
}

void *peek(struct s_queue *queue)
{
	struct s_queue *q = queue;

	if (!q || !q->first)
		return NULL;

	return (q->first->content);
}

int isEmpty(struct s_queue *queue)
{
	struct s_queue *q = queue;

	if (!q || !q->first)
		return 1;
	return 0;	
}
