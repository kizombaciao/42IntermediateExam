// according to colleagues, if there's only one node,
// both first and last need to point to this same node
// below code doesn't abide by that
// so ignore this solution.

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
	struct s_queue	*new;

	new = (struct s_queue*)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new;

	new = (struct s_node*)malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (queue->first == NULL)
		queue->first = new;
	else if (!queue->last) // same as (queue->last == NULL)
	{
		queue->first->next = new; // i don't see why you are doing this ?
		// because if q->last is NULL, that means there is only 1 node in the list!!!
		queue->last = queue->first->next;
	}
	else
	{
		queue->last->next = new;
		queue->last = queue->last->next;
	}
}
/*
according to colleagues, if there is only one node in the list, 
then you want to have both ptrs pointing to the same node.
*/

// what if q->f->next == NULL ?
// what if q->f and q->l point to the same node? only if one node in list.
// do we need to move last to first ?
void *dequeue(struct s_queue *queue)
{
	void *content;
	struct s_node *tmp;

	if (!queue->first)
		return (NULL);
	content = queue->first->content;
	tmp = queue->first;
	queue->first = queue->first->next;
	free(tmp);
	if (queue->first == queue->last)
		queue->last = NULL; // wouldn't this already be NULL ?
		// no, he's setting first to node but last to null!!!
	return (content);
}

// may be also check if queue itself is NULL ?
void *peek(struct s_queue *queue)
{
	return ((queue->first) ? queue->first->content : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return ((queue->first) ? 0 : 1);
}

// TEST THIS CODE TO SEE IF IT WORKS !!!