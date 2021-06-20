#include<stdio.h>

int main()
{
	int n;
	long long max=-0x7fffffff,min=0x7fffffff;
	long long end,a;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a);
		if(max<a)max=a;
		if(min>a)min=a;
	}
	end=(max-min)*(max-min);
	printf("%lld",end);
	return 0;
}