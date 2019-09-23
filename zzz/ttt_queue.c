
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
	return q;
}
 
struct s_node *new(void *c)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
	p->next = NULL;
	return p;
}
void enqueue(struct s_queue *queue, void *content)
{
	if (!queue)
		return;

	struct s_node *p = new(content);

	if (queue->first == NULL)
	{
		q->f = p;
		q->l = p;
	}
	else if (q->f == q->l)
	{
		q->l = p;
		q->f->next = p;
	}
	else
	{
		q->l->next = p;
		q->last = p;
	}
}

void *dequeue(struct s_queue *queue)
{
	if (!q || !q->f)
		return NULL;

	struct s_node *t;

	if (q->f == q->l)
	{
		t = q->f;
		c = q->f->content;		
		q->f = NULL;
		q->l = NULL;
	}
	else
	{
		t = q->f;
		c = q->f->content;		
		q->f = q->first->next;
	}
	free (t);
	return c;
}

void *peek(struct s_queue *queue)
{
	if (!q || !q->f)
		return NULL;

	return (q->f->c);
}

int isEmpty(struct s_queue *queue)
{
	if (!q || !q->f)
		return 1;
	return 0;
}