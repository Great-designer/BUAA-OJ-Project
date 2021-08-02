#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int p[1010];
int r[1010];

int bottom_up_ut_rod(int n)
{
	int j;
	for(j=0; j<=n; ++j)
	{
		r[j]=p[j];
	}
	int q;
	for(j=1; j<=n; ++j)
	{
		q=2147483;
		int i;
		for(i=1; i<=j; ++i)
		{
			q=(q<(p[i]+r[j-i])?q:(p[i]+r[j-i]));
		}
		r[j]=q;
	}
	return r[n];
}

int main()
{
	int i;
	int n;
	while(~scanf("%d",&n))
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d",&p[i]);
		}
		bottom_up_ut_rod(n);
		printf("%d\n",r[n]);
	}
}
