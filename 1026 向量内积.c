#include<stdio.h>

int a[20];
int b[20];

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
		scanf("%d",&b[i]);
		sum+=(a[i]*b[i]);
	}
	printf("%d\n",sum);
}

