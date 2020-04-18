#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	double x,y;
	int cls;
};

struct node a[200005],tmp[200005];

int compare(const void *p1,const void *p2)
{
	struct node *a=(struct node *)p1;
	struct node *b=(struct node *)p2;
	return a->x<b->x;
}

double distance(struct node a,struct node b)
{
	if(a.cls==b.cls)
	{
		return 1e50;
	} 
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double closePair(int left,int right)
{
	if(left>=right)
	{
		return 1e50;
	}
	int mid=(left+right)>>1;
	double cut=a[mid].x;
	double dist=fmin(closePair(left,mid),closePair(mid+1,right));
	int l=left,r=mid+1,cnt=0;
	while(l<=mid&&r<=right)
	{
		if(a[l].y<=a[r].y)
		{
			tmp[cnt++]=a[l++];
		}
		else
		{
			tmp[cnt++]=a[r++];
		}
	}
	while(l<=mid)
	{
		tmp[cnt++]=a[l++];
	}
	while(r<=right)
	{
		tmp[cnt++]=a[r++];
	}
	int i;
	for(i=0;i<cnt;i++)
	{
		a[left+i]=tmp[i];
	}
	cnt=0;
	for(i=left;i<=right;i++)
	{
		if(fabs(a[i].x-cut)<=dist)
		{
			tmp[cnt++]=a[i];
		}
	}
	for(i=0;i<cnt;i++)
	{
		int j;
		for(j=i+1;j<cnt;j++)
		{
			if(tmp[i].y-tmp[j].y>dist)
			{
				break;
			}
			dist=fmin(dist,distance(tmp[i],tmp[j]));
		}
	}
	return dist;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			a[i].cls=0;
		}
		for(i=n;i<2*n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			a[i].cls=1;
		}
		qsort(a,2*n,sizeof(struct node),compare);
		printf("%.3f\n",closePair(0,2*n-1));
	}
}

