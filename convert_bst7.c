// this one didn't make immediate sense either

// http://tech-queries.blogspot.com/2011/08/convert-binary-tree-in-circular-doubly.html

#include <stdio.h>
typedef struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
}       t_node;

void dll(t_node *r, t_node *p, t_node *h)
{
    t_node *right;

    if (!r)
        return;
    
    dll(r->left, p, h);

    // current node's left points to previous node
    r->left = p;
    if (p)
        // previous node's right points to current node
        p->right = r;
    else
        // if previous is NULL, then set head to current node
        h = r;

    // saving right node
    right = r->right;

    // circular
    h->left = r;
    r->right = h;

    p = r;
    dll(right, p, h);        
}

t_node *dll_wrapper(t_node *r)
{
    t_node *p; // previous
    t_node *h;

    p = NULL;
    h = NULL;

    dll(r, p, h)
    return(h);
}