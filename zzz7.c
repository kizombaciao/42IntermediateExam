#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
}

struct s_node *concatenate(struct s_node *ll, struct s_node *rl)
{
	struct s_node *llast;
	struct s_node *rlast;

	if (!ll)
		return rl;
	if (!rl)
		return ll;

	llast = ll->left;


}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *left;
	struct s_node *right;

	if (!bst)
		return NULL;




}

void print(struct s_node *h)
{
	struct s_node *p;

	p = h;
	printf("%d ", h->value);
	p = p->right;
	
	while (p != h)
	{
		printf("%d ", h->value);
		p = p->right;
	}
	printf("\n");
}

struct s_node *new(int value) 
{ 
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node)); 
	p->data = data; 
	p->left = p->right = NULL; 
	return (p); 
} 

int main()
{
	struct s_node *r;
	struct s_node *h;

	r = new(10); 
	r->left = new(12); 
	r->right = new(15); 
	r->left->left = new(25); 
	r->left->right = new(30); 
	r->right->left = new(36); 

	h = convert_bst(r);

}