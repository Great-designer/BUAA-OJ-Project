#include<stdio.h>
#include<string.h>

int sorti[1005];
int s[1005][1005];
int t[1005];

int main()
{
    int n,M,a,b;
    while(~scanf("%d%d",&n,&M))
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t[i]);
		}
		for(i=1;i<=n;i++)
		{
			int j;
			for(j=0;j<t[i];j++)
			{
				scanf("%d",&s[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			sorti[i]=i;
		}
		int m;
        for(m=0;m<M;m++)
		{
			scanf("%d%d",&a,&b);
            int temp=sorti[a];
			sorti[a]=sorti[b];
			sorti[b]=temp;
        }
        for(i=1;i<=n;i++)
		{
			int j;
			for(j=0;j<t[sorti[i]];j++)
			{
				printf("%d ",s[sorti[i]][j]);
			}
			printf("\n");
		}
    }
}

