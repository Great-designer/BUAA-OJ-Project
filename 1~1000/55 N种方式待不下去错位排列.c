#include<stdio.h>

long long a[21];

int main()
{
    int n;
    a[1]=0;
    a[2]=1;
    for(n=3;n<=20;n++)
    {
    	a[n]=(n-1)*(a[n-2]+a[n-1]);
	}
    while(~scanf("%d",&n))
    {
    	printf("%lld\n",a[n]);
	}
}

