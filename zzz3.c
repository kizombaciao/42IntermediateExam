// count_of_2.c
int c(int d)
{
	int ct = 0;

	while (d > 0)
	{
		if (d % 10 == 2)
		{
			ct++;
		}
		d = d / 10;
	}
	return (ct);
}

int count(int n)
{
	int ct = 0;

	for (i = 0; i < n; i++)
	{
		ct += c(i);
	}
	return ct;
}
//////////////////////
// equation.c
void eq()
{
	int a = -1, b = -1, c = -1;

	while (++a < 10)
	{
		while (++b < 0)
		{
			while (++c < 10)
			{
				if (10 * a + b + 10 * c + a == n)
					// print
			}
		}
	}
}
////////////////////////
// find_pivot.c
int sum(int *arr, int n)
{
	int i;
	int s = 0;

	while (i < n)
	{
		s += arr[i];
		i++;
	}
	return s;
}
int fp(int *arr, int n)
{
	int i;
	int t;
	int r = 0;
	int p;

	t = sum(arr, n);
	while (i < n)
	{
		p = t - arr[i];
		if (p == r)
		{
			return (i);
		}
		r = r + arr[i]
		i++;
	}
	return -1;
}
///////////////////////
// is_anagram.c
int a(char *a, char *b)
{
	int i = 0;
	int vf[127] = {0};

	while (a[i])
	{
		vf[(int)a[i]]++;
		i++;
	}
	i = 0
	while (b[i])
	{
		vf[(int)b[i]]--;
		i++;
	}
	i = 0;
	while (i < 127)
	{
		if (vf[i] != 0)
		return 0;
	}
	return 1;
}
////////////////////////
// print_doublon.c
void print_doublon(int *a, int na, int *b, int nb)
{
	int ia = 0;
	int ib = 0;
	int flag = 1;

	while (ia < na && ib < nb)
	{
		if (a[ia] == b[ib])
		{
			if (flag)
			{
				// %d a[ia]
				flag = 0;
			}
			else
			{
				// " %d", a[ia]
			}
			ia++;
			ib++;
		}
		else if (a[ia] > b[ib])
		{
			ib++;
		}
		else if (a[ia] < b[ib])
		{
			ia++;
		}
	}
	// "\n"
}
///////////////////////////////
// count_alpha.c
void p(char *s)
{
	int ct = 0;
	char c;

	c = low(*s);
	while (*s)
	{
		if (low(*s) == c)
		{
			*s = ' ';
			ct++;
		}
		s++;
	}
	// "%d%c", ct, c 
}
void ca(char *s)
{
	int flag = 1;
	while (*s)
	{
		if (is_alpha(*s))
		{
			if (flag == 0)
				// ", "
			p();
			flag = 0;
		}
		s++;
	}
}
////////////////////////////
// height_tree.c
struct s_node
{
	int v;
	struct s_node **nodes;
}

int ht(struct s_node *r)
{
	int h = 0;
	int i = 0;
	int res;

	if (!r)
		return -1;
	
	while (r->nodes[i])
	{
		res = 1 + ht(r->nodes[i]);
		h = max(res, h);
		i++;
	}
	return h;
}
////////////////////////////////
struct s_node
{
	void *content;
	struct s_node *next;
}
struct s_queue
{
	struct s_node *first;
	struct s_node *last;
}

struct s_node *new(void *c)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = NULL;
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

void enqueue(struct s_queue *q, void *c)
{
	struct s_node *tmp;
	tmp = new(c);

	if (q->last == NULL)
	{
		q->first = q->last = temp;
		return;
	}
	q->last->next = tmp;
	q->last = tmp;
}

void *dequeue(struct s_queue *q)
{
	struct s_node *tmp;
	void *p;

	if (q->first == NULL)
		return NULL;
	tmp = p->first;
	p = p->first->content;
	p->first = p->first->next;
	if (q->first == NULL)
		q->last = NULL;
	free(tmp);
	return (p);
}

void *peek(struct s_queue *q)
{
	if (q != NULL && q->first != NULL)
	{
		return q->first->content;
	}
	return NULL;
}
int isEmpty(struct s_queue *q)
{
	if (q == NULL || q->first == NULL)
		return 1;
	return 0;
}
////////////////////////////////////////
// stack.c
struct s_node
{
	void *content;
	struct s_node *next;
};

struct s_stack
{
	struct s_node *top;
};

struct s_node *new(void *content)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = content;
	p->next = NULL;
	return p;
}

struct s_stack *init()
{
	struct s_stack *p;

	p = (struct s_stack *)malloc(sizeof(struct s_stack));
	p->top = NULL;
	return (p);
}

void *pop(struct s_stack *s)
{
	struct s_node *tmp;
	void *p;

	if (!s || !s->top)
		return NULL;

	tmp = s->top;
	p = s->top->content;
	s->top = s->top->next;
	free(tmp);
	return (p);

}

void push(struct s_stack *s, void *content)
{
	struct s_node *p;

	p = new(content);
	p->next = s->top;
	s->top = p;
	return (p);
}

void *peek(struct s_stack *s)
{
	if (!s || !s->top)
		return NULL;
	return (s->top->content);
}

int isEmpty(struct s_stack *s)
{
	if (!s || !s->top)
		return 1;
	return 0;
}

////////////////////////////////
// is_looping.c

struct s_node
{
	int v;
	struct s_node *n;
}

int is_looping(struct s_node *n)
{
	while (n)
	{
		if (n->v == -1)
		{
			return 1;
		}
		n->v = -1;
		n = n->next;
	}
	return 0;
}
/////////////////////////////////

void long2(struct s_node *r, int cur, int exp, int *res)
{
	if (!r)
		return;
	if (r->data == exp)
		cur++;
	else
		cur = 1;
	*res = max(*res, cur);
	long2(r->left, cur, r->data + 1, res);
	long2(r->right, cur, r->data + 1, res);
}

int long(struct s_node *r)
{
	int res;

	if (!r)
		return 0;
	res = 0;
	long2(r, 0, r->data, &res);
	return res;
}
//////////////////////////////////////
// reverse_tree.c

void swap(struct s_node r)
{
	struct s_node *tmp;

	tmp = r->right;
	r->right = r->left;
	r-left = tmp;
}

void mirror(struct s_node *r)
{
	if (!r)
		return;
	mirror(r->left);
	mirror(r->right);
	swap(r);
}






































