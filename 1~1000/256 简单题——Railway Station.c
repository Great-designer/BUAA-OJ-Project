#include<stdio.h>

int simuStack[110010];
int top;

int n,m;
char flag;
int input;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int j;
		for(j=1;j<=m;++j)
		{
			top=0;
			flag=1;
			int curMax=0;
			int i;
			for(i=1;i<=n;++i)
			{
				scanf("%d",&input);
				if(!flag)
				{
					continue;
				}
				if(input>curMax)
				{
					int k;
					for(k=curMax+1;k<input;++k)
					{
						simuStack[top]=k;
						top++;
					}
					curMax=input;
				}
				else
				{
					if(input==simuStack[top-1])
					{
						top--;
					}
					else
					{
						flag=0;
					}
				}
			}
			if(flag)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		printf("\n");
	}
}
