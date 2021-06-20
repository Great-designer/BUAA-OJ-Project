#include<stdio.h>

int a[750];//3Ϊĩ 
int b[750];//6Ϊĩ 
int c[750];//6Ϊĩ 

void init()
{
	a[1]=1;
	b[1]=0;
	c[1]=0;
	a[2]=1;
	b[2]=1; 
	c[2]=1;
	int i;
	for(i=3;i<=700;i++)
	{
		a[i]=(a[i-1]+b[i-1]+c[i-1])%1000007;
		b[i]=(a[i-2]+b[i-2]+c[i-2])%1000007;
		c[i]=(a[i-2]+b[i-2]+c[i-2])%1000007;
	}
}

int main()
{
	init();
	int n;
	while(~scanf("%d",&n))
	{
		n=n/3;
		int ans=(a[n]+b[n]+c[n])%1000007;
		printf("%d\n",ans);
	}
}
