#include<stdio.h>

long long c[51][51]={0};

int main()
{
    c[1][1]=1;
    int i; 
    for(i=2;i<=50;i++)
	{
		int j;
		for(j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
    int n;
    while(~scanf("%d",&n))
	{
        for(i=0;++i<=n;printf("%d\n",c[i][i]))
		{
			int j;
			for(j=1;j<i;j++)
			{
				printf("%lld ",c[i][j]);
			}
		}
    }
}


