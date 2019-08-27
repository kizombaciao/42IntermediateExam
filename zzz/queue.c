#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	void *c;
	struct s_node *next;
};

struct s_queue
{
	struct s_node *f;
	struct s_node *l;
};

struct s_node *new(void *c)
{
	struct s_node *p;
	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->c = c;
	p->next = NULL;
	return p;
}

struct s_queue *init(void);
{
	struct s_q *p;

	p = (struct s_q *)malloc(sizeof(struct s_q));
	p->f = NULL;
	p->l = NULL;
	return p;
}

void enqueue(struct s_queue *q, void *content);
{
	struct s_node *p;

	if (q == NULL)
		return;

	p = new(content);

	if (q->f == NULL)
		q->f = p;
	else 
	{
		queue->l->next = p;
	}
	queue->l = p;
}

void *dequeue(struct s_queue *q);
{
	struct s_node *t;
	void *c;

	if (q == NULL || q->first == NULL)
		return;

	t = q->f;
	c = q->f->content;
	q->f = q->f->next;
	// what if q->f->next == NULL ?
	// what if q->f and q->l point to the same node ?
	// do we need to move last to first ?
	if (q->f == q->l)
		q->l = NULL;
	free (t);
	return (c);
}

void *peek(struct s_queue *q);
{
	if (q == NULL || q->f == NULL)
		return;

	return q->f->content;

}

int isEmpty(struct s_queue *q);
{
	if (q == NULL || q->f == NULL)
		return 1;
	return 0;
}
