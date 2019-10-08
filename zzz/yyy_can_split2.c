

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

int cs(struct s_node *r, int n, int *res)
{
    if (!r)
        return 0;

    int cl = 1 + cs(r->left, n, res) + cs(r->right, n, res);

    if (cl == n - cl)
        *res = 1;
    
    return cl;
}

int	can_split(struct s_node *n)
{
    int res = 0;

    if (!n)
        return 0;

    int len = tlen(n);

    int ans = cs(n, len, &res);
    return res;
}
