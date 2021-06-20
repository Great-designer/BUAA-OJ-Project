#include<stdio.h>

int m,n,a;

int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		int i;
		for(i=0;i<m;++i)
		{
			printf("%d:",i);
			int j;
			for(j=0;j<m;++j)
			{
				scanf("%d",&a);
				if(a)
				{
					printf("%d ",j);
				}
			}
			putchar('\n');
		}
	}
} 
