struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void ls(r, int cl, int exp, int *res)
{
    if (exp == r->data)
        cl++
    else
    {
        cl = 1; // ??? at 1
    }
    *res = max(*res, cl)

    // remember, branch left and right!
    ls(r->left, cl, r->data + 1, res)
    ls(r->right, cl, r->data + 1, res)
}

int	longest_sequence(struct s_node *node)
{
    int res = 0; // ??? at 0
    int cl = 0; // ?? at 0

    if (!node)
        return 0;

    // does ls need to return int ??? no
    ls(node, cl, node->value, &res);
    return res;
}
