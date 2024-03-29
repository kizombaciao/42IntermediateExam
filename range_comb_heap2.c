#include <stdio.h>
#include <stdlib.h>
int len;

void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void print(const int *v)
{
    int i;
    int size = len;
    if (v != 0) {
    for ( i = 0; i < size; i++) 
        printf("%4d", v[i] );
    printf("\n");
  }
}

void heappermute(int v[], int n) {
    int i;
    if (n == 1) 
        print(v);
    else 
    {
        for (i = 0; i < n; i++) 
        {
            heappermute(v, n - 1);
            if (n % 2 == 1) 
                swap(&v[0], &v[n - 1]);
            else 
                swap(&v[i], &v[n - 1]);
	    }
    }
}
 
int main()
{
   int num[11];
   int  i;
   printf("How many numbers you want to enter: ");
   scanf("%d", &len);
   printf("\nEnter %d numbers: ", len);
   for ( i = 0 ; i < len; i++)
       scanf("%d", &num[i]);
   heappermute(num, len);
   return 0;
}