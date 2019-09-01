// https://github.com/Manmeet2018/42_Exam-C-Intermediate/tree/master/level5/g_diam

/*
1. 1st Solution -> g_diam.c 
-> implementation of Graph by Adjacency Matrix method 
-> Time Complex O(V * V)
2. 2nd Solution -> g_diam.1.c 
-> implementation of Graph by Adjacency list method 
-> optimized solution as Time Complex O(V + E)
3. DFT is used and DFS is used for each node + Backtracking 
4. at each point the max_length_path is consider.
*/

// /********************************** ### Passed Exam Version ### *************************************/
// /****************************************** Method 1st Using Adjacency Matrix ************************************/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define num(x) x >= '0' && x <= '9'
#define for(i, a, b) for(i = (a); i < (b); i++)

static int ref;

int ft_atoi(char **s)
{
    int num = 0;
    while(num(**s))
    {
        num = num * 10 + **s - '0';
        (*s)++;
    }
    if(**s)
        (*s)++;
    return num;
}


void ft_putnbr(int n)
{
    char c;
    
    if(n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}


int find_max(char *s)
{
    int max = 0, num;
    while(*s)
    {
        num = ft_atoi(&s);
        max = num > max ? num : max;
    }
    return max;
}


void longest_path(int max, uint8_t arr[max][max], uint8_t visited[max], int r, int length)
{
    visited[r] = 1;
    int c;
    for(c,0,max)
    {
        if(!visited[c] && arr[r][c]) // if the node is not visited and it is the valid edge in Graph
        {
		ref = (ref < length + 1) ? length + 1 : ref; // Updated ref or the length of valid edge in Graph
		longest_path(max, arr, visited, c, length + 1); // Call fucntion to the all connected node's.
        }
    }
    visited[r] = 0; // Back track the whole problem
}

void solve_matrix(int max, char *s)
{
    int r, c;
    uint8_t arr[max][max];
    uint8_t visited[max];
    for(r,0,max)
        for(c,0,max)
            arr[r][c] = 0;
    for(c,0,max)
        visited[c] = 0;
    while(*s) // Matrix maker
    {
        r = ft_atoi(&s);
        c = ft_atoi(&s);
        arr[r][c] = 1;
        arr[c][r] = 1;
    }
    ref = 2;
    for(r,0,max)
        longest_path(max, arr, visited, r, 1);
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *s = av[1];
        int max = find_max(s);
        solve_matrix(max + 1, s);
        ft_putnbr(ref);
    }
    write(1, "\n", 1);
    return 0;
}

