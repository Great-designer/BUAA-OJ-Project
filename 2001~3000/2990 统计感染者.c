#include<stdio.h>

int main()
{
	int n, a, b;
	n = 1;
	while(n--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", (a+b));
	}
	return 0;
}