#include<stdio.h>

int main()
{
	int i,j;
	for (i = 1; i <= 9; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("%d * %d = %d%c", i, j, i * j, " \n"[j == i]);
		}
	}
	return 0;
}
