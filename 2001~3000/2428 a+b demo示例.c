#include<stdio.h>

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", a+b);
	}
	return 0;
}