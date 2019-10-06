
struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *maxbst(struct s_node *r)
{
    if (!r)
        return ;
    while (r->right)
    {
        r = r->right;
    }
    return r;
}

struct s_node *maxbst(struct s_node *r)
{
    if (!r)
        return ;
    while (r->left)
    {
        r = r->left;
    }
    return r;
}

void cb(struct s_node *r, struct s_node **prev)
{
    if (!r)
        return ;

    cb(r->left, prev);
    if (*prev) // ??
    {
        (*prev)->right = r;
        r->left = (*prev);
    }
    *prev = r;
    cb(r->right, prev);
}

// do i need a second function ???
struct s_node *convert_bst(struct s_node *bst)
{
    struct s_node *prev = 0;

    cb(bst, &prev); // how do i know bst will hold the changes from the function ???

    struct s_node *minb = minbst(bst);
    minb->left = maxbst(bst);
    minb->left->right = minb;

    return minb;
}
