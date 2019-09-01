// Passed Moulinette 2019.05.26
#include <stdio.h>

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
	struct s_queue *queue = malloc(sizeof(struct s_queue *));
	queue->first = NULL;
	queue->last = NULL;
	return(queue);
}
void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *cur;

	if (queue == NULL)
		return;
	cur = malloc(sizeof(struct s_node));
	cur->content = content;
	cur->next = NULL;
	if (queue->first == NULL)
		queue->first = cur;
	else
		queue->last->next = cur; // but what if q->last equals NULL ???
	// below line ensures that if only node in list, then last also point to it!
	queue->last = cur;
}
void *dequeue(struct s_queue *queue)
{
	struct s_node *cur;
	void *content;

	if (queue == NULL || queue->first == NULL) // also, check first, if NULL !
		return (NULL);
	cur = queue->first;
	content = cur->content;
	queue->first = cur->next;
	// if both first and last both point to the same node, only one node in list!
	if (cur == queue->last) 
		queue->last = NULL;
	free(cur);
	return (content); // it's a void pointer function!!!
}
void *peek(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}
int isEmpty(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (1);
	return (0);
}
//-----------------------------------------------------
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
//	enqueue(q, c1);

	c2 = dequeue(q);
	printf("aaab  %d\n", *(int *)c2);
	c2 = dequeue(q);
//	printf("aaac  %d\n", *(int *)c2);
	
	printf("aaad  %d\n", isEmpty(q));
}

/*
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
*/
