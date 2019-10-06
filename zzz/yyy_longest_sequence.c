
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};


void ls(struct s_node *node, int cl, int exp, int *res)
{
    if (!node)
        return ;

    if (exp = node->value)
        cl++;
    else
        cl = 1; // ??
    *res = max(*res, cl); // outside the if condition
    
    ls(node->left, cl, node->value + 1, res);
    ls(node->right, cl, node->value + 1, res);
}

int	longest_sequence(struct s_node *node)
{
    int res = 0;

    if (!node)
        return 0;
    
    ls(node, 0, node->value, &res);
}
