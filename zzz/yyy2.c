int h(struct s_node *r)
{
    int i = 0;
    int res, res2;
    
    if (!r)
        return -1;
    
    i = 0;
    while (r->nodes[i])
    {
        res = 1 + h(r->nodes[i]);
        res2 = max(res, res2);
        i++;
    }
    return(res2);
}

struct s_node *new(int v)
{
    struct s_node *p;
    
    p = (struct s_node *)malloc(sizeof(struct s_node));
    p->value = v;
    p->nodes = malloc(1000);

}