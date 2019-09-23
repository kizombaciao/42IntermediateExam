
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ABS(V) (((V) < 0) ? -(V) : (V))

int max(int a, int b)
{
    return (a > b ? a : b);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
// USEFUL !!!
int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]);
    return i;
}
// USEFUL !!!
void ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

int ft_strcmp(char *a, char *b)
{
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return (a[i] - b[i]);
}
char *init_str(char *a, char *b)
{
    int len = max(ft_strlen(a), ft_strlen(b)); // why need 1 + ???
	//printf("333a %d\n", len);
    
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    p[len] = '\0';
    return p;
}

void bigfirst(char **s1, char **s2)
{
    char *a = *s1;
    char *b = *s2;

    if (*a == '-')
        a++;
    if (*b == '-')
        b++;
    if ((ft_strlen(a) < ft_strlen(b)) || (ft_strlen(a) == ft_strlen(b) && ft_strcmp(a, b) < 0))
    {
        char *tmp = *s1;
        *s1 = *s2;
        *s2 = tmp;
    }    
}

// note, a is bigger than b
int check_neg(char **a, char **b)
{
    int flag = 0;
    if ((**a == '-' && **b != '-') || (**a != '-' && **b == '-'))
        flag = 1;

    if ((**a == '-' && **b == '-') || (**a == '-' && **b != '-'))
        ft_putchar('-');

    if (**a == '-')
        (*a)++;

    if (**b == '-')
        (*b)++;

    return flag;
}

void add(char *s1, char *s2)
{
    int l1 = ft_strlen(s1) - 1; // why - 1 ? b/c it is used as index.
    int l2 = ft_strlen(s2) - 1;

    char *s3 = init_str(s1, s2); // malloc output.
    int l3 = max(l1, l2);
    //int l3 = ft_strlen(s3) - 1;
    int carry = 0;

//    printf("222a  %s %s %d %d %d\n", s1, s2, l1, l2, l3);

    while (l1 >= 0 || carry)
    {
        carry += s1[l1] - '0';
        if (l2 >= 0)
            carry += s2[l2] - '0';
        s3[l3] = (carry % 10) + '0';
//        printf("222b  %s %s %d %d %d\n", s1, s2, l1, l2, l3);

        carry /= 10;
        l1--;
        l2--;
        l3--;
    }

//    printf("222b  %s %s %s %d %d %d\n", s1, s2, s3, l1, l2, l3);

    ft_putstr(s3); // ???
//    ft_putstr(&s3[l3]); // ???
}

void subtract(char *s1, char *s2)
{
    int l1 = ft_strlen(s1) - 1; // why - 1 ? b/c it is used as index.
    int l2 = ft_strlen(s2) - 1;

    char *s3 = init_str(s1, s2); // malloc output.
    int l3 = max(l1, l2);    
    //int l3 = ft_strlen(s3) - 1;
    int carry = 0;

    while (l1 >= 0)
    {
        carry += s1[l1] - '0';
        if (l2 >= 0)
            carry -= s2[l2] - '0';
        if (carry < 0)
        {
            carry -= 10;
            s3[l3] = (10 - ABS(carry % 10)) + '0';
        }   
        else
            s3[l3] = carry % 10 + '0';
        carry /= 10;
        l1--;
        l2--;
        l3--;        
    }
    ft_putstr(s3);
    //ft_putstr(&s3[l3]);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        bigfirst(&av[1], &av[2]); 
        // note, av[1] is bigger than av[2] now.

        if (check_neg(&av[1], &av[2]) == 1)
            subtract(av[1], av[2]);
        else 
            add(av[1], av[2]);
    }
    ft_putchar('\n');
    return 0;
}
