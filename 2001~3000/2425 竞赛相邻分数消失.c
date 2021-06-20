#include<stdio.h> 

int x[101000];
int a[101000];
int b[101000];
int c[101000];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int t,tm=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		x[t]++;
		if(tm<t)
		{
			tm=t;
		}
	}
	a[1]=x[1];
	b[1]=0;
	a[2]=2*x[2];
	b[2]=x[1];
	for(i=3;i<=tm;i++)
	{
		b[i]=a[i-1]>b[i-1]?a[i-1]:b[i-1];
		a[i]=i*x[i]+b[i-1];
	}
	int ans=a[tm]>b[tm]?a[tm]:b[tm];
	printf("%d",ans);
}
