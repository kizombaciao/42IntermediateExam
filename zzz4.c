// longest_sequence.c
void lcu(struct node *r, int len, int exp, int *res)
{
	if (!r)			// check NULL
		return;	
	
	if (r->d == exp) // check expected
		len++;
	else
		len = 1;

	*res = max(*res, len); // find max

	lcu(r->l, len, r->d + 1, res); // traverse
	lcu(r->ri, len, r->d + 1, res); // traverse
}

int lc(struct node *r)
{
	int res;

	if (!r)
		return 0;

	res = 0;
	lc(r, 0, r->d, &res);
	return res;
}

// reverse_tree.c
void m(struct node *n)
{
	struct node *t;

	if (!n)
		return;

	m(n->l);
	m(n->ri);

	t = n->l;
	n->l = n->ri;
	n->ri = t;
}

// can_split.c
int cr(struct node *r, int n, int *res)
{
	if (!r)
		return 0;

	c = 1 + cr(r->l, n, res) + cr(r->ri, n, res);

	if (c == n - c)
		*res = 1;

	return c;
}

int c(struct node *r)
{
	int n;
	int res;

	res = 0;
	n = count(r);
	cr(r, n, &res);
	return res;
}

// gold_gain.c

int g(int **m, int n)
{
	int c, r;
	int ri, ru, rd;

	int t[][] = {0};

	// memset(t, 0, sizeof(t));

	for (c = n - 1; c >= 0; c--)
	{
		for (r = 0; r < n; r++)
		{
			ri = (c == n - 1) ? 0 : t[r][c+1];
			ru = (r == 0 || c == n - 1) ? 0 : t[r-1][c+1];
			rd = (r = n - 1 || col == n - 1) ? 0 : t[r+1][c+1];
			t[r][c] = m[r][c] + max(ri, max(ru, rd));

		}
	}
}

// perimter.c

void pbr(struct node *r)
{
	if (r)
	{
		if (r->ri)
		{
			pbr(r->ri);
			// %d, r->d
		}
		else if (r->l)
		{
			pbr(r->l);
			//%d, r->d
		}
	}
}

void pl(struct node *r)
{
	if (r)
	{
		pl(r->l);
		if (!(r->l) && !(r->ri))
			// %d, r->d
		pl(r->ri);
	}
}

void pbl(struct node *r)
{
	if (r)
	{
		if (r->l)
		{
			// %d, r->d
			pbl(r->l);
		}
		else if (r->ri)
		{
			// %d, r->d
			pbl(r->ri)
		}
	}
}

void pb(struct node *r)
{
	if (r)
	{
		// "%d", r->d
		pbl(r->l);
		pl(r->l)
		pl(r->ri);
		pbr(r>ri)
	}
	
}

// width_tree.c

int h(struct node *r, int *ans)
{
	int l;
	int ri;

	if (!r)
		return 0;
	l = h(r->l, ans);
	ri = h(r->ri, ans);

	*ans = max(ans, 1 + l + ri);
	return (1 + max(l, ri));
}

int d(struct node *r)
{
	int ans = 0;
	int he;

	if (!r)
		return 0;
	he = h(r, &ans);
	return ans;
}

// clone_list.c




int f(struct n *r, struct n *s)
{
	int i = 0;
	while (s)
	{
		if (r == s)
			return i;
		i++;
		s = s->next;
	}
	return -1;
}

struct n *g(int id, struct n *s)
{
	int i = 0;
	while (i < id)
	{
		i++;
		s = s->next;
	}
	return (s);
}

struct n *c(struct n *r)
{
	struct n *h;
	struct n *c1;
	struct n *h1;

	if (!r)
		return NULL;
	h = r;
	c1 = new(h->d);
	h1 = c1;

	r = r->next;
	while (r)
	{
		c1->next = new(r->d);
		c1 = c1->next;
		r = r->next;
	}
	r = h;
	c1 = h1;
	while (r)
	{
		if (r->o)
			c1->o = g(f(r->o, h), h1);
		c1 = c1->next;
		r = r->next;
	}
	return h1;
}

// intersection.c



int gc(struct n *h)
{
	int i = 0;
	struct n *c;

	c = h;
	while (c)
	{
		i++;
		c = c->next;
	}
	return c;
}

int gcn2(int d, struct n *h1, struct n *h2)
{
	int i;
	struct *n c1 = h1;
	struct *n c2 = h2;
	for (i = 0; i < d; i++)
	{
		if (c1 == NULL)
			return -1
		c1 = c1->next;
	}
	while (c1 && c2)
	{
		if (c1 == c2)
			return c1->data;
		c1 = c1->next;
		c2 = c2->next;
	}
	return -1;
}

int gcn(struct n *h1, struct n *h2)
{
	int c1;
	int c2;
	int d;

	if (c1 > c2)
	{
		d = c1 - c2;
		return gcn2(d, h1, h2);
	}
	else
	{
		d = c2 - c1;
		return gcn2(d, h2, h1);
	}
}

// range_comb.c

void p(char *a, int l, int r)
{
	int i;
	if (l == r)
		// a
	else
	{
		for (i = l; i <= r; i++)
		{
			s((a + l), (a + i));
			p(a, l+1, r);
			s((a + l), (a + i));
		}
	}
}

// volume_histogram.c
int fw(int *arr, int n)
{
	int i;
	int l[n];
	int r[n];
	int w = 0;

	l[0] = arr[0];
	for (i = 1; i < n; i++)
	{
		l[i] = max(l[i - 1], arr[i]);
	}
	r[n-1] = arr[n-1];
	for (i = n - 2; i >= 0; i--)
	{
		r[i] = max(r[i + 1], arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		w += min(l[i], r[i]) - arr[i];
	}
	return w;
}











