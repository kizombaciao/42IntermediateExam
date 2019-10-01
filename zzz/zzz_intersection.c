#include <stdio.h>

	struct s_node {
		void *content;
		struct s_node *next;
	};

int tlen(struct s_node *r)
{
    int i = 0;
    while (r)
    {
        i++;
        r = r->next;
    }
    return i;
}

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
    int diff;
    int len1 = tlen(lst1);
    int len2 = tlen(lst2);


    if (len1 > len2)
    {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++)
        {
            lst1 = lst1->next;
        }
    }
    else
    {
        diff = len2 - len1;
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
    return NULL;
}
