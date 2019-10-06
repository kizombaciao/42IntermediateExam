
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};


int cn(struct s_node *r)
{
    if (!r)
        return 0;

    return (1 + cn(r->left) + cn(r->right));
}

int cs(struct s_node *r, int num, int *res)
{
    if (!r)
        return ;

    int le = cs(r, num, res);
    int ri = cs(r, num, res);
    int cl = 1 + le + ri;

    if (num - cl == cl)
        *res = 1;

    return cl;
}

int	can_split(struct s_node *n)
{
    int res = 0;

    if (!n)
        return 0;

    int num = cn(n);

    int ans = cs(n, num, &res);
}

