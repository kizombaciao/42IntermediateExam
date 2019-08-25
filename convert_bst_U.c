// https://www.youtube.com/watch?v=FsxTX7-yhOw
// This code passed Moulinette on 2019.05.26
#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int           value;
	struct s_node *left;
	struct s_node *right;
};
struct s_node *leftmost(struct s_node *cur)
{
	while (cur->left)
		cur = cur->left;
	return (cur);
}
struct s_node *rightmost(struct s_node *cur)
{
	while (cur->right)
		cur = cur->right;
	return (cur);
}
void	convert_subtree(struct s_node *cur, struct s_node **prev)
{
	if (cur == 0)
		return;

	convert_subtree(cur->left, prev);
	if (*prev)
	{
		(*prev)->right = cur;
		cur->left = *prev;
	}
	*prev = cur;
	convert_subtree(cur->right, prev);
}
struct s_node *convert_bst(struct s_node *bst)
{
	if (bst == 0)
		return (0);

	struct s_node *prev = 0;
	convert_subtree(bst, &prev);

	struct s_node *min = leftmost(bst);
	min->left = rightmost(bst);
	min->left->right = min;
	return (min);
}
/////////////////////////////////////
struct s_node *new(int d)
{
    struct s_node *n =(struct s_node *)malloc(sizeof(struct s_node));
    n->value = d;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// inorder traversal
void p(struct s_node *r)
{
    if(!r)
        return ;
    p(r->left);
    printf("%d\n", r->value);
    p(r->right);
}
int main()
{
    struct s_node *a = new(12);
    a->left = new(6);
    a->left->left = new(3);
    a->left->right = new(9);

    a->right = new(18);
    a->right->right = new(20);
    a->right->left = new(15);
    struct s_node *c = a;
    p(c); // INORDER TRAVERSAL PRINTOUT
    printf("-----------------------------\ncir Doub linklist: \n");
    
    struct s_node *r = convert_bst(a);
    int i = 0;
    while (i++ < 15)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
}

//---------------------------------------------------------
// #include <stdio.h>

// void	print_list(struct s_node *cur)
// {
// 	struct s_node *first = cur;

// 	printf("%d", cur->value);
// 	cur = cur->right;

// 	while (cur != first)
// 	{
// 		printf(" -> %d", cur->value);
// 		cur = cur->right;
// 	}
// 	printf("\n");
// }

// #define NODE(v, r, l) &(struct s_node){v, l, r}
// int	main(void)
// {
// 	struct s_node *root = NODE(10,
// 		NODE(5,
// 			NODE(4,
// 				NODE(2,
// 					NODE(1, 0, 0),
// 					NODE(3, 0, 0)
// 					),
// 				0
// 				),
// 			NODE(7,
// 				NODE(6, 0, 0),
// 				NODE(8, 0, 0)
// 				)
// 			),
// 		NODE(12,
// 			NODE(11, 0, 0),
// 			NODE(15,
// 				0,
// 				NODE(17,
// 					NODE(16, 0, 0),
// 					NODE(20, 0, 0)
// 					)
// 				)
// 			)
// 		);

// 	print_list(convert_bst(root));
// }

// Stanford
// http://cslibrary.stanford.edu/109/TreeListRecursion.html
