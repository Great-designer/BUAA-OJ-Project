#include<stdio.h>
#include<limits.h>

int ans[30];

void init()
{
	ans[0]=1;
	ans[1]=2;
	double sum=1;
	int n;
	for(n=2;n<100000010;n++)
	{
		int temp=(int)sum;
		sum+=1/(double)n;
		if(temp!=(int)sum)
		{
			ans[temp+1]=n;
		}
	}
}

int main()
{
	init();
	int q;
	while(~scanf("%d",&q))
	{
		while(q--)
		{
			int k;
			scanf("%d",&k);
			printf("%lld\n",ans[k]);
		}
	}
}