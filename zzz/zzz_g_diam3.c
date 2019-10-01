
void ft_putnbr(int n)
{
    if (n >= 10)
    {
        ft_putnbr(n / 10);
    }
    ft_putchar((n % 10) + '0');
}

int ft_atoi(char **s)
{
    int nb = 0;
    while (isnum(**s))
    {
        nb = nb * 10 + (**s - '0');
        (*s)++;
    }
    if (**s)
        (*s)++;
    return nb;
}

int findmaxv(char *s)
{
    int res = 0;

    while (*s)
    {
        int tmp = ft_atoi(&s);
        res = max(tmp, res);
    }
    return res;
}

void dfsu(struct graph *g, int v, int vis[], int cl, int *res)
{
    vis[v] = 1;

    for (struct s_node *p = g->adj[v].head; p; p = p->next)
    {
        if (!vis[p->data])
        {
            *res = max(*res, cl + 1);
            dfsu(g, p->data, vis, cl + 1, res); // note!
        }
    }

    vis[v] = 0;
}

void dfs(struct graph *g, int maxv)
{
    int vis[maxv + 1];
    int res = 2;

    for (int i = 0; i <= maxv; i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i <= maxv; i++)
    {
        dfsu(g, i, vis, 1, &res); // note !
    }

}

void gd(char *s)
{
    int maxv = findmaxv(s);
    struct graph *g = newgraph(maxv);
    while (*s)
    {
        int src = ft_atoi(&s);
        int dest = ft_atoi(&s);
        newedge(g, src, dest);
    }
    dfs(g, maxv);
}