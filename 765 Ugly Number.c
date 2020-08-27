#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

unsigned long long a[100010];
unsigned long long locate[100010];
unsigned long long ans[100010];

int compare(const void*p1,const void*p2)
{
	unsigned long long *s=(unsigned long long*)p1;
	unsigned long long *t=(unsigned long long*)p2;
	return *s>*t?1:-1;
}

int k,n;

int main()
{
	scanf("%d%d",&k,&n);
	int i;
	for(i=1;i<=k;++i)
	{
		scanf("%llu",&a[i]);
		locate[i]=1;
	}
	qsort(a+1,k,sizeof(unsigned long long),compare);
	ans[1]=1;
	for(i=2;i<=n+1;++i)
	{
		ans[i]=ULLONG_MAX;
		int j;
		for(j=1;j<=k;++j)
		{
			while(a[j]*ans[locate[j]]<=ans[i-1])
			{
				locate[j]++;
			}
			if(a[j]*ans[locate[j]]<ans[i])
			{
				ans[i]=a[j]*ans[locate[j]];
			}
		}
	}
	printf("%llu\n",ans[n+1]);
}
