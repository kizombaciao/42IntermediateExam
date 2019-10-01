#include <stdlib.h> // del
#include <stdio.h> // del


	struct s_node {
		int				value;
		struct s_node	**nodes;
	};


int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int height_tree(struct s_node *root)
{
    struct s_node *r = root;
    int res = 0;

    if (!r)
        return -1;

    int i;
    i = 0;
    while (r->nodes[i])
    {
        res = max(res, 1 + height_tree(r->nodes[i]));
        i++;
    }
    return (res);
}

struct s_node *new(int v)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->nodes = malloc(1000); // ???
	// need to initialize to NULL ???
	return p;
}

int main()
{
	struct s_node *p;

	p = new(1);
	p->nodes[0] = new(2);
	p->nodes[1] = new(3);
	p->nodes[0]->nodes[0] = new(4);
	p->nodes[1]->nodes[0] = new(5);

	printf("%d\n", height_tree(p));
}
