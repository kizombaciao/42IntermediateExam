#include <stdio.h> // del
#include <stdlib.h>

struct s_node
{
	void *content;
	struct s_node *next;
};
struct s_queue
{
	struct s_node *first;
	struct s_node *last;
};
struct s_queue *init(void)
{
	struct s_queue *q;
	q = (struct s_queue *)malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}
void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *p;

	if (!queue)
		return;
	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = content;
	p->next = NULL;
	if (queue->first == NULL)
	{
		queue->first = p;
		queue->last = p;
	}
	else
	{
		queue->last->next = p;
		queue->last = p;
	}
	printf("222a %d\n", *(int *)p->content);
}
void *dequeue(struct s_queue *queue)
{
	struct s_node *t;
	void *c;

	if (!queue)
		return NULL;
	if (queue->first == NULL)
		return NULL;

	//c = (void *)malloc(sizeof(void));
	if (queue->first == queue->last)
	{
		t = queue->first;
		c = queue->first->content;
		queue->first = queue->first->next;
		queue->last = queue->last->next;
	}
	else
	{
		t = queue->first;
		c = queue->first->content;
		queue->first = queue->first->next;
	}
	free (t);
	return (c);
}
void *peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return NULL;
	return (queue->first->content);
}
int isEmpty(struct s_queue *queue)
{
	return ((queue && queue->first) ? 0 : 1);
}
/*
int main()
{
	struct s_queue *q;
	int n = 111;
	void *c = &n;
	int n1 = 222; 
	void *c1 = &n1;
	void *c2;

	q = init();
	enqueue(q, c);
	c2 = peek(q);
	printf("%d\n", *(int *)c2);
	//enqueue(q, c1);

	c2 = dequeue(q);
	printf("%d\n", *(int *)c2);
	//c2 = dequeue(q);
	//printf("%d\n", *(int *)c2);
	
	printf("%d\n", isEmpty(q));
}
*/
int main(void)
{
	char a[] = "Apples"; (void)a;
	char b[] = "Banananananas"; (void)b;
	char c[] = "Charlemagne"; (void)c;
	char d[] = "dddddddicks"; (void)d;
	struct s_queue *queue;
	
	queue = init();
	printf("isEmpty A: %d\n", isEmpty(queue));
	enqueue(queue, a);
	printf("isEmpty B: %d\n", isEmpty(queue));
	enqueue(queue, b);
	enqueue(queue, c);
	enqueue(queue, d);
	printf("Peek: %s\n", peek(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Pop: %s\n", dequeue(queue));
	printf("Peek: %s\n", peek(queue));
	printf("isEmpty C: %d\n", isEmpty(queue));
	return (0);
}

