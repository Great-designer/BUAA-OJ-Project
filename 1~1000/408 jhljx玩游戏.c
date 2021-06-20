#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n%4==0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}

