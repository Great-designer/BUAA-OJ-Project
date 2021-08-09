#include<stdio.h>

void pSwap(int **a,int **b)
{
	int *c;
	c=*a;
	*a=*b;
	*b=c;
	return;
}

int main()
{
	int *a;
	int *b;
	while(scanf("%d%d",&a,&b)==2)
	{
		pSwap(&a,&b);
		printf("%d %d\n",a,b);
	}
	return 0;
}
