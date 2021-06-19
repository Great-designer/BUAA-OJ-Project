#include<stdio.h>

int n,a[10005],b[10005],t;

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",a+i,b+i);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j]||(a[i]==a[j]&&b[i]>b[j]))
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i],b[i]);
	}
}
