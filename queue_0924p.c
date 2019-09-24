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

struct s_queue *init(void)
{
	struct s_queue *q = (struct s_queue *)malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

struct s_node *new(void *c)
{
	struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
	p->next = NULL;
	return p;
}

void enqueue(struct s_queue *queue, void *content)
{
	if (!queue)
		return ;

	struct s_node *p = new(content);

	// if empty
	if (queue->first == NULL)
	{
		queue->first = p;
		queue->last = p;
	}
	// if only one
	else if (queue->first == queue->last)
	{
		queue->first->next = p;
		queue->last = p;
	}
	// if two or more
	else
	{
		queue->last->next = p;
		queue->last = p;
	}
}

void *dequeue(struct s_queue *queue)
{
	struct s_node *p;
	void *c;

	if (!queue)
		return NULL;

	// if empty
	if (queue->first == NULL)
		return NULL;

	// if one
	if (queue->first == queue->last)
	{
		p = queue->first;
		c = queue->first->content;
		queue->first = NULL;
		queue->last = NULL;
		free(p);
		return c;
	}
	// if two or more
	p = queue->first;
	c = queue->first->content;
	queue->first = queue->first->next;
	free(p);
	return c;
}

void *peek(struct s_queue *queue)
{
	if (!queue)
		return NULL;
	// empty
	if (queue->first == NULL)
		return NULL;
	
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue)
		return 1;
	if (queue->first == NULL)
		return 1;
	return 0;
}

/*
int main()
{
	int n1 = 1;
	void *p1 = &n1;
	int n2 = 2;
	void *p2 = &n2;
	int n3 = 3;
	void *p3 = &n3;
	int n4 = 4;
	void *p4 = &n4;
	void *t;

	struct s_queue *q = NULL;

	q = init();
	
	// added when empty
	enqueue(q, p1);
	t = peek(q);
	printf("111a  %d\n", *(int *)t);

	// added when 1 
	enqueue(q, p2);
	t = peek(q);
	printf("111a  %d\n", *(int *)t);

	// added when 2 
	enqueue(q, p4);
	t = peek(q);
	printf("111a  %d\n", *(int *)t);

	// removed when 3
	t = dequeue(q);
	printf("111a  %d\n", *(int *)t);

	printf("111a  %d\n", isEmpty(q));

	// added when 2
	enqueue(q, p3);
	t = peek(q);
	printf("111a  %d\n", *(int *)t);

	// removed when 3
	t = dequeue(q);
	printf("111a  %d\n", *(int *)t);

	printf("111a  %d\n", isEmpty(q));

	// removed when 2
	t = dequeue(q);
	printf("111a  %d\n", *(int *)t);

	t = dequeue(q);
	printf("111a  %d\n", *(int *)t);
	
	printf("111a  %d\n", isEmpty(q));
	t = peek(q);
//	printf("111a  %d\n", *(int *)t);
}
*/
