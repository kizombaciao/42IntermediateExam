// count_of_2.c
static void count_number(int n, int *count)
{
	if (n >= 10)
	{
		count_number(n / 10, count);
		count_number(n % 10, count);
	}
	if (n == 2)
	{
		*count += 1;
	}
}

int count_of_2(int n)
{
	int i = 1;
	int count = 0;

	while (++i <= n)
		count_number(i, &count);
	return (count);
}

/////////////////////////////////
// find_pivot.c
int fp(int *arr, int n)
{
	int count = 0;
	int pivot = -1;
	int sum = get_sum(arr, n);

	for (int i = 0; (pivot == -1 && i < n); i++)
	{
		sum -= arr[i];
		pivot = (count == sum) ? i : -1;
		count += arr[i];
	}
	return (pivot);
}

//////////////////////////////////
// is_anagram.c
int is_anagram(char *a, char *b)
{
	int vf[127] = { [0 ... 126] = 0};
	int i = -1;

	while (*a)
	{
		vf[(int)*a]++;
		a++;
	}
	while (*b
	{
		vf[(int)*b]--;
		b++;
	}
	while (++i < 127)
	{
		if (vf[i] != 0)
			return (0);
	}
	return (1);
}

////////////////////////////////////
// print_doublon.c
void print_doublon(int *a, int na, int *b, int nb)
{
	int ia = 0;
	int ib = 0;
	int first = 1;

	while (ia < na && ib < nb)
	{
		if (a[ia] == b[ib])
		{
			if (first)
			{
				printf("%d", a[ia]);
				first = 0;
			}
			else
				printf(" %d", a[ia]);
			ia++;
			ib++;
		}
		else if (a[ia] < b[ib])
			ia++;
		else if (b[ib] < b[ib])
			ib++;
	}
}

////////////////////////////////////
// count_alpha.c
void print_count(char *str)
{
	char c = to_lower(*str);
	int count = 0;

	while (*str)
	{
		if (to_lower(*str) == c)
		{
			*str = ' ';
			count++;
		}
		str++;
	}
	printf("%d%c", count, c);
}

int main()
{
	char *str;
	int first = 1;

	while (*str)
	{
		if (is_alpha(*str))
		{
			if (first == 0)
				printf(", ");
			print_count(str);
			first = 0;
		}
		str++;
	}
}

///////////////////////////////////
// height_tree.c

struct n
{
	int v;
	struct n **nodes;
};

int height_tree(struct n *p)
{
	int height = 0;
	int i = 0;
	int tmp;

	if (!p)
		return -1;
	else
	{
		while (p->nodes[i])
		{
			tmp = 1 + height_tree(p->nodes[i++]);
			height = (tmp > height) ? tmp : height;
		}
	}
	return (height);
}

struct n *new(int v)
{
	struct n *p = (struct n *)malloc(sizeof(struct n));
	p->v = v;
	p->n = malloc(1000);
	return (p);
}

int main()
{
	struct n *p = new(94);
	p->nodes[0] = new(34);
	p->nodes[1] = new(52);
	p->nodes[0]->nodes[0] = new(1);
	p->nodes[0]->nodes[1] = new(99);
	p->nodes[0]->nodes[2] = new(11);

	p->nodes[0]->nodes[1]->nodes[0] = new(13);

	height_tree(p);
}
////////////////////////////////////
// queue.c

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
	struct s_queue *new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return new;
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	if (!queue->first)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
}

void *dequeue(struct s_queue *queue)
{
	void *ele = NULL;
	if (queue->first)
	{
		struct s_node *temp = queue->first;
		ele = queue->first->content;
		queue->last = (queue->first == queue->last) ? NULL : queue->last;
		queue->first = queue->first->next;
		free(temp);
	}
	return ele;
}


void *peek(struct s_queue *queue)
{
	return queue->first ? queue->first->content : NULL;
}

int isEmpty(struct s_queue *queue)
{
	return queue->first ? 0 : 1;
}


int main()
{
	struct s_queue *q = init();

}
//////////////////////////////////////////////////////
// longest_sequence.c

struct node
{
	int data;
	node *l, *r;
}

node *new(int data)
{
	node *p = (struct node *)malloc(sizeof(struct node));
	p->data = data;
	p->l = p->r = NULL;
	return p;
}

void lcu(node *root, int len, int ex, int &res)
{
	if (root == NULL)
		return;
	if (root->data == ex)
		len++;
	else
		len = 1;
	res = max(res, len);
	lcu(root->l, len, root->data + 1, res);
	lcu(root->r, len, root->data + 1, res);
}


int lc(node *root)
{
	if (root == NULL)
		return 0;
	int res = 0;
	lcu(root, 0, root->data, res);
	return res;
}
/////////////////////////////////////////
// ord_alphlong.c

////////////////////////////////////////
// reverse_tree.c

void mirror(struct node *node)
{
	struct node *p;

	if (node == NULL)
		return;
	else
	{
		
		mirror(node->left);
		mirror(node->right);

		p = node->left;
		node->left = node->right;
		node->right = p;
	}
}

//////////////////////////////////////
// str_maxlenoc.c

void p(char *x, char *y, int m, int n)
{
	int lcs[m+1][n+1];
	int len = 0;
	int row, col;
	int i, j;
	char *res;

	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (x[i-1] == y[j-1])
			{
				lcs[i][j] = lcs[i-1][j-1] + 1;
				if (len < lcs[i][j])
				{
					len = lcs[i][j];
					row = i;
					col = j;
				}
			}
			else
				lcs[i][j] = 0;
		}
	}
	if (len == 0)
		return;

	res = (char *)malloc(sizeof(char) * (len + 1));
	while (lcs[row][col] != 0)
	{
		res[--len] = x[row - 1];
		row--;
		col--;
	}
	// print result
}











































