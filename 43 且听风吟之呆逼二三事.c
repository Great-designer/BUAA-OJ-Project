#include<stdio.h>

int fib[46];

int main()
{
	fib[0]=1;
	fib[1]=1;
	int i; 
	for(i=2;i<46;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	int n;
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<46;i++)
		{
			if(fib[i]==n)
			{
				break;
			}
		}
		if(i==46)
		{
			printf("Oh,yes!\n");
		}
		else
		{
			printf("Oh,holly shit!\n");
		}
	}
	return 0;
}

