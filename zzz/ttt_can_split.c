
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int cn(struct s_node *r)
{
    int res;

    // return 0;

    int le = cn(r->left);
    int ri = cn(r->right);

    res = 1 + le + ri;
    return res;
}

int cs(struct s_node *r, int n, int *res)
{
    // return 0;
    int le = cs(r->left, res);
    int ri = cs(r->right, res);
    int c = 1 + le + ri;

    if (n - c == c)
    {
        *res = 1; // don't forget the asterisk.
    }    
    return (c);    
}

int	can_split(struct s_node *n)
{
    int res = 0;
    // return 0;
    int num = cn(n);
    int ans = cs(n, num, &res);
    return res;
}


