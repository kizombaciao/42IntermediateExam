#include <stdlib.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void cb(struct s_node *r, struct s_node **prev)
{
    if (!r)
        return ;

    cb(r->left, prev);
    if (*prev)
    {
        (*prev)->right = r;
        r->left = (*prev);
    }
    *prev = r;
    cb(r->right, prev);
}

struct s_node *findmin(struct s_node *r)
{
    while (r->left)
    {
        r = r->left;
    }
    return r;
}
struct s_node *findmax(struct s_node *r)
{
    while (r->right)
    {
        r = r->right;
    }
    return r;
}

struct s_node *convert_bst(struct s_node *bst)
{
    if (!bst)
        return NULL;

    struct s_node *prev = 0;

    cb(bst, &prev);

    struct s_node *min = findmin(bst);
    min->left = findmax(bst);
    min->left->right = min;
    return min;
}

int main()
{


}