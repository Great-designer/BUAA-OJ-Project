#include<stdio.h>

int main()
{
	int n,a;
	while(~scanf("%d",&n))
	{
		a=n%3;
		if(a>0)
		{
			a=1;
		}
		printf("%d\n",n/3+a);
	}
	return 0;
}

