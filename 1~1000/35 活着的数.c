#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		n+=2;
		while(n%5==0)
		{
			n/=5;
		}
		while(n%3==0)
		{
			n/=3;
		}
		if(n==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}	
	return 0;
}

