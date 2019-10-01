
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int wt(struct s_node *r, int *res)
{
    if (!r)
        return 0;

    int le = wt(r->left, res);
    int ri = wt(r->right, res);

    int cl = 1 + le + ri;
    *res = max(*res, cl);

    return (1 + max(le, ri));
}

int	width_tree(struct s_node *n)
{
    if (!n)
        return 0;

    int res = 0;

    int ans = wt(n, &res);

    return res;
}
