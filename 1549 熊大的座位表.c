#include<stdio.h>

int a[1005],b[1005]; 

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=n/2;i>=1;i--)
	{
		b[n-n/2-1+i]=2*i;
	}
	for(i=1;i<=n-n/2;i++)
	{
		b[n-n/2-i]=2*i-1;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[b[i]-1]);
	}
}
