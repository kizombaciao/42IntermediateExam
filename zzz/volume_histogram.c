#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return (((a > b) ? a : b));
}

int min(int a, int b)
{
	return (((a > b) ? b : a));
}

int vvv(int *h, int size)
{
	int i = 1;
	int lll[size];
	int rrr[size];
	int res = 0;

	memset(lll, 0, size * sizeof(int));
	memset(rrr, 0, size * sizeof(int));

	lll[0] = h[0];
	while (i < size)
	{
		lll[i] = max(h[i], lll[i - 1]);
		printf("222a %d ", lll[i]);
		i++;
	}
	printf("\n");
	rrr[size - 1] = h[size - 1];
	i = size - 2;
	while (i >= 0)
	{
		rrr[i] = max(h[i], rrr[i + 1]);
		printf("222b %d ", rrr[i]);
		i--;
	}
	printf("\n");
	for (i = 0; i < size; i++)
	{
		res += min(lll[i], rrr[i]) - h[i];
	}

	return res;
}

int main()
{
	int h[] = {1, 0, 2, 0, 2};
	int size = 5;
	int res = 0;

	res = vvv(h, size);
	printf("%d\n", res);

}