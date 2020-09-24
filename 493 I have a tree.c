#include<stdio.h>
#include<string.h>

int n;
long long ans;
long long num[1023][1023];

int main()
{
	while(~scanf("%d",&n))
	{
		memset(num,0,sizeof(num));
		int i;
		for(i=1;i<=n;i++)
		{
			int j;
			for(j=1;j<=i;j++)
			{
				scanf("%lld",&num[i][j]); 
			}
		}
		for(i=2;i<=n;i++)
		{
			int j;
			for(j=1;j<=i;j++)
			{
				num[i][j]+=(num[i-1][j-1]>num[i-1][j]?num[i-1][j-1]:num[i-1][j]);
			}
		}
		ans=-1;
		for(i=1;i<=n;i++)
		{
			ans=(ans>num[n][i]?ans:num[n][i]);
		}
		printf("%d\n",ans);
	}
}


