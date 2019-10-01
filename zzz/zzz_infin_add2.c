
void big(char **s1, char **s2)
{
    char *a = *s1;
    char *b = *s2;

    if (*a == '-')
        a++;
    if (*b == '-')
        b++;

    if (strlen(a) < strlen(b))
    {
        //swap
    }
    if (strlen(a) == strlen(b) && ft_strcmp(a, b) < 0)
    {
        //swap
    }
}

int check(char **a, char **b)
{
    int flag = 0;
    //if (**a == '-' && **b !- '-') || 
    flag = 1;

    // if both neg or first neg and second pos
    //putchar -

    if (**a == '-')
        (*a)++;

    if (**b == '-')
        (*b)++;
    return flag;
}

void add(char *s1, char *s2)
{
    


}


int main(int ac, char **av)
{
    if (ac == 3)
    {
        big(&av[1], &av[2]);
        if (check(&av[1], &av[2]) == 1)
            subtract(av[1], av[2]);
        else
            add(av[1], av[2]);
    }

}