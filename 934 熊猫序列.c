#include<stdio.h>

long long a[120]; 

int main()
{
	a[1]=1;
	a[2]=1;
	a[3]=1;
	a[4]=1;
	a[5]=2;
	int i;
	for(i=6;i<110;i++)
	{
		a[i]=a[i-1]+a[i-4];
		a[i]%=10000007;
	}
	int n;
	scanf("%d",&n);
	printf("%lld",a[n]); 
}
