#include<stdio.h>

int a[60],b[60];

int main()
{
	int i;
	a[1]=1;
	a[2]=2;
	b[1]=1;
	b[2]=1;
	for(i=3;i<=35;i++)
	{
		b[i]=a[i-1];
		a[i]=a[i-1]+b[i-1];
	}
	int n;
	scanf("%d",&n);
	printf("%d\n",a[n]+b[n]);
}
