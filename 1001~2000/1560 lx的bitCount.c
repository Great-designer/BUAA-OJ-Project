#include<stdio.h>

int main()
{
	int x;
	scanf("%d",&x);
	printf("%d\n",__builtin_popcount(x));
}
