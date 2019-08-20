// height_tree.c
struct s_node
{
	int v;
	struct s_node **n;
}

int h(struct s_node *r)
{
	int h = 0;
	int i = 0;
	int res;
	if (!r)
		return -1;
	else
		while (r->n[i])
		{
			res = 1 + h(r->n[i]);
			h = max(res, h);
			i++;
		}
	return h;
}
///////////////////////////////////
// gold_gain.c
#define M 100

int gold(int g[][], int m, int n)
{
	int t[m][n];
	int c;
	int r;
	int ri, ru, rd;
	int res;

	memset(t, 0, sizeof(t));

	for (c  = n - 1; c >= 0, c--)
	{
		for (r = 0; r < m; r++)
		{
			ri = (c == n - 1) ? 0 : t[r][c + 1];
			ru = (r == 0 || c == n - 1) ? 0 : t[r - 1][c + 1];
			rd = (r = m - 1 || c == n - 1) ? 0 : t[r - 1][c + 1];

			t[r][c] = g[r][c] + max(ri, max(ru, rd));
		}
	}
	res = t[0][0];
	for (r = 1; r < m; r++)
	{
		res = max(res, t[i][0]);
	}
	return res;
}

int main()
{
	int g[M][M] = 
	{
		{1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int m, n;

	m = 4;
	n = 4;
}
////////////////////////////////////
// perimeter.c
void pl(struct n *r)
{
	if (r)
	{
		pl(r->l);
		if (!(r->l) && !(r->r))
			// r->data
		pl(r->ri);
	}
}

void pbl(struct n *r)
{
	if (r)
	{
		if (r->l)
		{
			// r->data
			pbl(r->l);
		}
		else if (r->ri)
		{
			// r->data
			pbl(r->ri);
		}
	}
}

void pb(struct n *r)
{
	if (r)
	{
		// r->d;
		pbl(r->l);
		pl(r->l);
		pl(r->r);
		pbr(r->ri);
	}
}


