#include<stdio.h>

int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	char c=getchar();
	while(c==' '||c=='\n'||c=='\r')
	{
		c=getchar();
	}
	int i;
	for(i=0;i<n;i++)
	{
		if(c=='E')
		{
			a+=100;
			b+=100;
		}
		else if(c=='N')
		{
			if(a<1900)
			{
				a+=71;
			}
			else
			{
				a-=38;
			}
			if(b<1900)
			{
				b+=107;
			}
			else
			{
				b-=74;
			}
		}
		c=getchar();
	}
	if(a>b)
	{
		printf("MaxWin\n");
	}
	else if(a<b)
	{
		printf("KangWin\n");
	}
	else
	{
		printf("WellWell\n");
	}
}