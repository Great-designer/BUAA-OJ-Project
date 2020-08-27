#include<stdio.h>

int a[45];

int main()
{
	a[0]=1;
	a[1]=1;
	a[2]=2;
	a[3]=4;
	int i;
	for(i=4;i<=44;i++)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
}
