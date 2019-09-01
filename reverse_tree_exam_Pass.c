//#include <stdio.h> // del
//#include <stdlib.h> // del

struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node *t;

	if (!root)
		return;

	reverse_tree(root->left);
	reverse_tree(root->right);

	t = root->left;
	root->left = root->right;
	root->right = t;
}
/*
struct s_node *new(int v)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->left = NULL;
	p->right = NULL;
	return (p);
}

void pr(struct s_node *r)
{
	if (!r)
		return;
	pr(r->left);
	printf("%d ", r->value);
	pr(r->right);
}

int main()
{
	struct s_node *p;

	p = new(94);
	p->left = new(34);
	p->right = new(52);
	p->left->left = new(1);
	p->left->right = new(99);

	pr(p);
	printf("\n");
	reverse_tree(p);
	pr(p);
}
*/
