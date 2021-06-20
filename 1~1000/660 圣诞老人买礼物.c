#include<stdio.h> 

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		n=n/5;
		long long m=(n+1+(n*n-(n%2))/4)%1000000007;
		printf("%lld\n",m);
	}
}
