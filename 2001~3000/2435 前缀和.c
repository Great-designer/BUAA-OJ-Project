#include<stdio.h>

int sum[1000009];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a;
	int i; 
	sum[0]=0;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
	} 
	int max=-2147483647;
	for(i=0;i+k<=n;++i)
	{
		if(sum[i+k]-sum[i]>max)
		{
			max=sum[i+k]-sum[i];
		}
	}
	printf("%d\n",max);
}
