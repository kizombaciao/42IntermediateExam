
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int h(struct s_node *r)
{
    if (!r)
        return 0;

    return (1 + h(r->left) + h(r->right)); // remember!
}

int cs(struct s_node *r, int n, int *res)
{
    if (!r)
        return 0;

    int le = cs(r->left, n, res);
    int ri = cs(r->right, n, res);
    int c = 1 + le + ri;
    if (n - c == c)
        *res = 1;
    return (c);
}

int	can_split(struct s_node *n)
{
    int res = 0;
    if (!n)
        return 0;

    int tlen = h(n);
    int ans = cs(n, tlen, &res); // cl = 0 ?
    return res;
}