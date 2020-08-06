#include<stdio.h>
#include<stdlib.h>

struct node
{
	int id,x,y;
};

struct node a[1010];

struct Node
{
	int id,num;
};

struct Node b[1010];

int compare(const void*p1,const void*p2)
{
	struct Node *s=(struct Node*)p1;
	struct Node *t=(struct Node*)p2;
	return s->num>t->num;
}

int ans[1010];
int n;
long long sum1,sum2;

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i].y);
		b[i].num=(a[i].x<a[i].y)?a[i].x:a[i].y;
		b[i].id = i;
	}
	qsort(b+1,n,sizeof(struct Node),compare);
	int l=1,r=n;
	for(i=1;i<=n;++i)
	{
		if(b[i].num==a[b[i].id].x)
		{
			ans[l++]=b[i].id;
		}
		else
		{
			ans[r--]=b[i].id;
		}
	}
	for(i=1;i<=n;++i)
	{
		sum1+=a[ans[i]].x;
		sum2=(sum1>sum2)?sum1:sum2;
		sum2+=a[ans[i]].y;
	}
	printf("%lld\n",sum2);
} 
