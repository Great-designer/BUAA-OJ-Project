#include<stdio.h>
#include<stdlib.h>

struct pair
{
	int first;
	int second;
};

int compare(const void*p1,const void*p2)
{
	struct pair *a=(struct pair*)p1;
	struct pair *b=(struct pair*)p2;
	if(a->first!=b->first)
	{
		return a->first<b->first?1:-1;
	}
	else
	{
		return a->second>b->second?1:-1;
	}
}

struct pair a[1005];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	qsort(a,n,sizeof(struct pair),compare);
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].first,a[i].second);
	}
}

