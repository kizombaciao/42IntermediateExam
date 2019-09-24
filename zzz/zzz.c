void ls(struct s_node *r, int cl, int exp, int *res)
{
    if (!r)
        return ;

    if (r->value == exp)
        cl++;
    else
    {
        cl = 1;
    }
    *res = max(*res, cl);

    ls(r->left);
    ls(r->right);
}

//reverse_tree
//1 func
//void
// post

char *ls(char *arr)
{
    ml = ft_strlen(arr);
    cl = 2 * moe(arr);

    while (bal(&arr[i], cl) != 0)
    {
        if (cl + i >= ml)
            i = 0
            cl--;
        else
        {
            i++
        }
    }
    return (ft_strndup(&arr[i], cl));
}