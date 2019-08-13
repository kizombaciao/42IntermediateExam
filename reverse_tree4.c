

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	if (!root)
		return ;
	else
	{
		struct s_node *temp;
        
        temp = root->left;
        root->left = root->right; // what if root->right is NULL ???
		root->right = temp;

		if (root->left)
			reverse_tree(root->left);
		if(root->right)
			reverse_tree(root->right);
	}
}

// https://github.com/Manmeet2018/42_Exam-C-Intermediate/blob/master/level2/reverse_tree/reverse_tree.c

