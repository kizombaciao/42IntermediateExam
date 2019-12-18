/*
alkozma:fiestaparrot: 5:08 PM
I wanted to post this somewhere and I feel like here's a good place. I wrote a little example of how to store a doubly linked circular list using only 1 pointer in each node for prev and next. XOR Linked Lists exists, but I couldn't find anyone talking about how to do a circular one so here c: (EDIT: I also formatted this for submission for a Geeksforgeeks data structures article so ignore the strings referencing that
 */

#include <stdlib.h> // for malloc
#include <stdio.h>  // for printf
#include <stdint.h> // for uintptr_t
 
typedef struct  s_list  t_list;
 
struct s_list
{
    char        *data;  // Contains a string.
    struct s_list   *npx;   // npx = previous XOR next
};
 
t_list  *create_elem(char *data, t_list *npx)
{
    t_list  *ret;
 
    ret = malloc(sizeof(*ret));
    ret->data = data;
    ret->npx = npx;
    return (ret);
}
 
t_list  *xor(t_list *a, t_list *b)
{
    return (t_list*)((uintptr_t)a ^ (uintptr_t)b);
}
 
void    insert(t_list **h, t_list **t, char *data)
{
    t_list  *last = *t;
    t_list  *first = *h;
    t_list  *new, npx;
 
    if (!last && !first)  // No nodes, populate first node
    {
        new = create_elem(data, NULL);  // self XOR self == NULL
        *h = ((*t = new));
    }
    else if (last == first)  // Only one node, set tail properly
        *t = create_elem(data, NULL);   // self XOR self == NULL
    else  // Multiple nodes, do a real add
    {
        // Create an element with npx = first XOR last
        // (it will be inserted at the end of the list)
 
        new = create_elem(data, xor(first, last));
 
        // If head or tail's npx == 0, we know its a list of size 2,
        // so each prev and next pointer is the same.
        // So, if it is a list with size 2
        //  last->npx = new XOR first
        //  first->npx = new XOR last
        // else
        //  last->npx = new XOR (last->npx XOR first)
        //  first->npx = new XOR (first->npx XOR last)
     
        last->npx = xor(new, ((!last->npx || !first->npx) ?
                first : xor(last->npx, first)));
        first->npx = xor(new, ((!last->npx || !first->npx) ?
                last : xor(first->npx, last)));
 
        // Set the new pointers for passed addresses.
        *h = first;
        *t = new;
    }
}
 
int traverse(t_list *h, t_list *t)
{
    t_list  *cur = h;
    t_list  *last = t;
    t_list  *tmp;
 
    while (cur)
    {
        printf("[%s]\n", cur->data);
        tmp = xor(cur->npx, last);
        last = cur;
        cur = tmp;
        if (cur == h)
            return (1);
    }
    return (1);
}
 
int main(void)
{
    char    s1[] = "Testing!";
    char    s2[] = "My!";
    char    s3[] = "Function!";
    char    s4[] = "For!";
    char    s5[] = "GeeksforGeeks!";
 
    // We need to keep track of head and tail pointers for
    // everything to work nicely.
 
    // Traversal will always require access to
    // two consecutive pointers.
 
    t_list  *head;
    t_list  *tail;
 
    head = NULL;
    tail = NULL;
    insert(&head, &tail, s1);
    insert(&head, &tail, s2);
    insert(&head, &tail, s3);
    insert(&head, &tail, s4);
    insert(&head, &tail, s5);
    traverse(head, tail);
}

