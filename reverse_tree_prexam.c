// DID NOT PASS B/C I USED NULL WITHOUT THE BELOW LIBRARIES
// DON'T FORGET THAT TO USE NULL, INCLUDE <string.h> or <stdlib.h> !!!

#include <stdio.h>
#include <stdlib.h>
	struct s_node {
		int				value;
		struct s_node	*right;
		struct s_node	*left;
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

	p = new(1);
	p->left = new(2);
	p->right = new(3);
	p->right->left = new(4);
	pr(p);
	printf("\n");
	reverse_tree(p);
	pr(p);

}
*/