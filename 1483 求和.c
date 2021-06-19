#include<stdio.h>
#include<math.h>

long long f(int a)
{
	return ((long long)pow(10,a)-1)/9;
}

int main()
{
	long long d,n;
	scanf("%lld%lld",&d,&n);
	int a;
	int i;
	long long sum=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		sum+=(long long)f(a);
	}
	sum*=d;
	printf("%lld\n",sum);
}
