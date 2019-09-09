
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int tlen(struct s_node *r)
{
	if (!r)
		return 0;

	return (1 + tlen(r->left) + tlen(r->right));
}

// can't remember how to capture c value ???
int cs(struct s_node *r, int n, int *res)
{
	int c;

	if (!r)
		return;

	c = 1 + cs(r->left, n, res) + cs(r->right, n, res);

	if (c = n - c)
		*res = 1;

	return(c);
}

int	can_split(struct s_node *n)
{
	int res = 0;

	if (!n)
		return 0;

	int n = tlen(n);

	cs(n, n, &res);
}

int main()
{


}

// 2 func
// int 4 args
// 