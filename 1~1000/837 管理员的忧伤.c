#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n<1000||(n>1799&&n<3000)||n>3999)
		{
			printf("who?\n");
		}
		else if(n>2999&&n<4000)
		{
			printf("bacon\n");
		}
		else if(n>999&&n<1700)
		{
			printf("bacon\n");
		}
		else if(n>1699&&n<1800)
		{
			printf("freshman\n");
		}
	}
}

