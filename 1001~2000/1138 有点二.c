#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{
		if(b>c)//abc
		{
			printf("%d",b);
		}
		else if(a<c)//cab
		{
			printf("%d",a);
		}
		else//acb
		{
			printf("%d",c);
		}
	}
	else
	{
		if(b<c)//abc
		{
			printf("%d",b);
		}
		else if(a>c)//cab
		{
			printf("%d",a);
		}
		else//acb
		{
			printf("%d",c);
		}
	}
}