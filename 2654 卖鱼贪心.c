#include<stdio.h>
#include<stdlib.h>

struct fish
{
	int t;
	int d;
	double u;
};

struct fish water[100005];

int compare(const void*p1,const void*p2)
{
	return (*(struct fish*)p2).u>(*(struct fish*)p1).u?1:-1;
}

int t[100005],d[100005];
double u[100005];

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&water[i].t,&water[i].d);
		water[i].u=(double)water[i].d/(double)water[i].t;
	}
	qsort(water,n,sizeof(struct fish),compare);
	int ans=0;
	for(i=0;i<n;i++)
	{
		int ti=0;
		for(j=0;j<i;j++)
		{
			ti+=water[j].t;
		}
		ans+=(water[j].d)*ti;
	}
	printf("%d\n",ans);
}
