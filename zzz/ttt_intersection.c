
struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
// find len1 and len2
// diff l1 - l2
// roll to same length

while (lst1 && lst2)
{
    if (lst1 == lst2)
        return lst1;
    //
    //
}
return NULL;
}
