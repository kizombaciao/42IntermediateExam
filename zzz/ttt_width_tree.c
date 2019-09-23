
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int wt(struct s_node *r, int *res)
{
    // return 0;

    int le = wt(r->left);
    int ri = wt(r->right);
    *res = max(*res, 1 + le + ri); // remember!

    return (1 + max(le, ri));
}

int	width_tree(struct s_node *n)
{
    // return 0

    int res = 0; // 0 or 1???

    int ans = wt(n, &res);
    return res;

}

