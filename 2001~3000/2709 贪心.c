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
	int n,T;
	scanf("%d%d",&n,&T);
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d%d",&water[i].t,&water[i].d);
		water[i].u=(double)water[i].d/(double)water[i].t;
	}
	qsort(water,n,sizeof(struct fish),compare);
	double ans=0;
	int time=0;
	i=0;
	while((time+water[i].t)<=T&&i<n)
	{
		ans+=water[i].d;
		time+=water[i].t;
		i++;
	}
	if(time<T)
	{
		ans+=(T-time)*water[i].u;
	}
	printf("%.2lf\n",ans);
}
