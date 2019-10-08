#include <stdlib.h>

struct s_node {
		void *content;
		struct s_node *next;
};

int llen(struct s_node *p)
{
    int i = 0;

    while (p)
    {
        p = p->next;
        i++;
    }
    return i;
}

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
    int l1 = llen(lst1);
    int l2 = llen(lst2);
    int diff;

    if (l1 > l2)
    {
        diff = l1 - l2;
        for (int i = 0; i < diff; i++)
        {
            lst1 = lst1->next;
        }
    }
    else if (l1 < l2)
    {
        diff = l2 - l1;
        for (int i = 0; i < diff; i++)
        {
            lst2 = lst2->next;
        }
    }
    while (lst1 && lst2)
    {
        if (lst1 == lst2)
            return lst1;
        lst1 = lst1->next;
        lst2 = lst2->next;
    }
    return NULL:
}
