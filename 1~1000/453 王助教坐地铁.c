#include<stdio.h>

int main()
{
	int n=1,flag=1;
	int x;
	scanf("%d",&x);
	int l;
	while(~scanf("%d",&l))
	{
		if(x-l<=0)
		{
			flag=0;
			if(x>l-x)
			{
				printf("%d",n+1);
			}
			else
			{
				printf("%d",n);
			}
			break;
		}
		l;
		n++;
		x-=l;
	}
	if(flag)
	{
		printf("%d",n);
	}
}

