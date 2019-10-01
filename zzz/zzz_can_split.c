
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int nn(struct s_node *r)
{
    if (!r)
        return 0;

    return (1 + nn(r->left) + nn(r->right));
}

int cs(struct s_node *r, int n, int *res)
{
    if (!r)
        return ;

    int le = cs(r->left, n, res);
    int ri = cs(r->right, n, res);
    int c = 1 + le + ri;

    if (n - c == c)
        *res = 1;    

    return (c);
}

int	can_split(struct s_node *n)
{
    if (!n)
        return;

    n = nn(n);

    int res = 0;
    int ans = cs(n, n, &res);

}
