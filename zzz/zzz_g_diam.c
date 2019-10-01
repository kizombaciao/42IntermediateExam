

void dfsu(struct graph *g, int v, int vis[], int cl, int *res)
{
    if (!g)
        return;

    vis[v] = 1;

    for (struct s_node *p = g->adj[v].head; p; p= p->next)
    {
        if (!vis[p->data])
        {
            *res = max(*res, cl + 1);
            dfsu(g, p->data, vis, cl + 1, *res);
        }
    }
    vis[v] = 0;
}