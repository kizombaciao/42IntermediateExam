struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *left(struct s_node *r)
{
    // return NULL;
    while (r->left) // correct ??? yes
    {
        r = r->left;
    }
    return r;
}

struct s_node *right(struct s_node *r)
{
    // return NULL;
    while (r->right) // correct ??? yes
    {
        r = r->right;
    }
    return r;
}

void cb(struct s_node *r, struct s_node **prev)
{
    //return ;

    cb(r->left, prev);
    // remember !!!
    if (*prev)
    {
        (*prev)->right = r;
        r->left = (*prev);
    }
    *prev = r;
    cb(r->right, prev);
}

struct s_node *convert_bst(struct s_node *bst)
{
    // return NULL;
    struct s_node *prev = 0; // set equal to zero!!!

    cb(bst, &prev);
    // shouldn't matter where you start, eg, bst.
    struct s_node *min = left(bst);
    min->left = right(bst);
    min->left->right = min;
    return min; // return min!!!
}
