// https://www.sanfoundry.com/cpp-program-find-length-longest-common-substring/

/*
 * C++ Program to Find Length of Longest Common Substring
 */
//#include<iostream>
//#include<cstring>
//using namespace std;
#include <stdio.h> 

// A utility function to find maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Returns length of longest common substring of X[0..m-1] and Y[0..n-1] */
int LCSubStr(char *X, char *Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}
 
int main()
{
    char X[] = "Sanfoundry";
    char Y[] = "foundation";
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of Longest Common Substring is %d", LCSubStr(X, Y, m, n));
    return 0;
}
