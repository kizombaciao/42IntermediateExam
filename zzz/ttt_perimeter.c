#include <stdio.h>

struct s_node
{
    int v;
    struct s_node *l;
    struct s_node *r;
};

// 3, 3, 3, 4

// !r, or p, l
void pl(struct s_node *r)
{
    if (!r)
        return;
    if (r->l || r->r)
        printf(" %d", r->v);   
    if (r->l)
        pl(r->l);
}

// !r, r, or p
void pr(struct s_node *r)
{
    if (!r)
        return;
    if (r->r)
        pr(r->r);
    if (r->l || r->r)
        printf(" %d", r->v);   
}

// l, r, !&& p
void pn(struct s_node *r)
{
    if (r->l)
        pn(r->l);
    if (r->r)
        pn(r->r);
    if (!r->l && !r->r)
        printf(" %d", r->v);   
}

// !r, r p, l ln, r nr 
void p(struct s_node *r)
{
    if (!r)
        return ;
    if (r)
        printf("%d", r->v);   
    if (r->l)
    {
        pl(r->l);
        pn(r->l);
    }
    if (r->r)
    {
        pn(r->r);
        pr(r->r);
    }
}   
/////////////////////////////////////////////////////