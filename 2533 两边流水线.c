#include<stdio.h>

int p1[600],p2[600];
int t1[600],t2[600];
int min1[600],min2[600];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p1[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p2[i]);
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d",&t1[i]);
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%d",&t2[i]);
		}
		min1[0]=0;
		min2[0]=0;
		for(i=1;i<=n;i++)
		{
			min1[i]=(min1[i-1]<(min2[i-1]+t2[i-1])?min1[i-1]:(min2[i-1]+t2[i-1]))+p1[i];
			min2[i]=(min2[i-1]<(min1[i-1]+t1[i-1])?min2[i-1]:(min1[i-1]+t1[i-1]))+p2[i];
		}
		int ans=(min1[n]<min2[n]?min1[n]:min2[n]);
		printf("%d\n",ans);
	}
}
