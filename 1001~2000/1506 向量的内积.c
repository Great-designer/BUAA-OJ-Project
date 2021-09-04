#include<stdio.h>

int a[25];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	for(i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		sum+=a[i]*b;
	}
	printf("%d\n",sum);
}