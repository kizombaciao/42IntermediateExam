


	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};



void pl(struct s_node *r)
{
    if (!r)
        return;
    if (r->left || r->right)
        //pr
    if (r->left)
        pl(r->left);
}

void pr(struct s_node *r)
{
    if (!r)
        return;

    if (r->right)
        pr(r->right);
    if (r->left || r->right)
        //pr
}


void pn(struct s_node *r)
{
    if (!r)
        return;

    if (r->left)
        pn(r->left);

    if (r->right)
        pn(r->right);

    if (!r->left && !r->right)
        // pr

}


void perimeter(struct s_node *root)
{
    struct s_node *r = root;

    if (!r)
        return;

    // pr

    if (r->left)
    {
        pl(r->left);
        pn(r->left);
    }
    if (r->right)
    {
        pn(r->right);
        pr(r->right);
    }
    // pr
}