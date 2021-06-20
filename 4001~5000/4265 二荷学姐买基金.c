#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	long long a,b,i,ans=0;
	scanf("%lld",&a);
	for(i=2; i<=n; i++)
	{
		scanf("%lld",&b);
		if(b-a>0)
			ans+=(b-a);
		a=b;
	}
	printf("%lld",ans);
	return 0;
}