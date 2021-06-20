#include<stdio.h>

int a[25];

int main()
{
	int len; 
	scanf("%d",&len);
	int i;
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
	int n;
	scanf("%d",&n);
	n=n%len;
	for(i=len-n;i<len;i++)
	{
		printf("%d ",a[i]);
	}
	for(i=0;i<len-n;i++)
	{
		printf("%d ",a[i]);
	}
}

