#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==i)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	printf("\n");
	return 0;
}