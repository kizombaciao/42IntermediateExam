// PASS!!!

//#include <stdio.h> // del
//#include <stdlib.h> // del
// mirror
// l, r, swap

struct s_node {
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
	p->right = NULL;
	p->left = NULL;
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

	p->left->left->left = new(20);
	p->left->right->left = new(83);
	p->left->right->right = new(39);

	p->left->right->left->right = new(61);
	p->left->right->right->left = new(37);
	p->left->right->right->right = new(67);

	pr(p);
	printf("\n");
	reverse_tree(p);
	pr(p);
	printf("\n");
	return (0);
}
*/
