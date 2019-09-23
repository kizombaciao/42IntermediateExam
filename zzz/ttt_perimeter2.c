void pl()
{
    if (!r)
        return ;
    if (r->l || r->r)
        //p
    if (r->l)
        pl(r->l)
}

void pr()
{
    if (!r)
        return ;
    if (r->r)
        pr(r->r)
    if (r->l || r->r)
        //p
}

void pn()
{
    if (r->l)
        pn(r->l)
    if (r->r)
        pn(r->r)
    if (!r->l && !r->r)
        // p
}

void p(struct s_node *r)
{
    if (!r)
        return ;
    if (r)
        // p
    if (r->l)
        pl(r->l);
        pn(r->l);
    if (r->r)
        pn(r->r);
        pr(r->r);
}