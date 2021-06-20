#include<stdio.h>

int n,k;

int main()
{
    while(~scanf("%d%d",&n,&k))
	{
		if(n%(k+1)==0)
		{
			puts("Yep");
		}
		else
		{
			puts("Nope");
		}
	}
}
