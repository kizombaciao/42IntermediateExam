#include <stdio.h>


	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};




void pl(struct s_node *r)
{
    if (!r)
        return ;

    if (r->left || r->right)
        printf(" %d", r->value);

    if (r->left)
        pl(r->left);
}

void pr(struct s_node *r)
{
    if (!r)
        return ;
    if (r->right)
        pl(r->right);
    if (r->left || r->right)
        printf(" %d", r->value);

}

void pn(struct s_node *r)
{
    if (!r)
        return ;
    if (r->left)
        pn(r->left);
    if (r->right)
        pn(r->right);
    if (!r->left && !r->right)
        printf(" %d", r->value);
}


void perimeter(struct s_node *root)
{
    struct s_node *r = root;

    if (!r)
        return ;
    
    printf("%d", root->value);
    if (r->left)
    {
        pl(r->left);
        pn(r->left);
    }
    // no else ??
    if (r->right)
    {
        pn(r->right);
        pr(r->right);
    }
    printf("\n");
}
