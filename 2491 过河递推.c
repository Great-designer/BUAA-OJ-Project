#include<stdio.h>

long long a[60]; 
long long b[60]; 

int main() 
{
	a[0]=1;
	a[1]=1;
	a[2]=2;
	b[0]=0;
	b[1]=0;
	b[2]=0;
	int i;
	for(i=3;i<=55;i++)
	{
		a[i]=a[i-1]+a[i-2]+b[i-1]+b[i-2];
		b[i]=a[i-3];
	}
	while(~scanf("%d",&i))
	{
		printf("%lld\n",a[i]+b[i]);
	}
	return 0;
}
