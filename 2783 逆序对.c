#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val,pos;
};

struct node ori[500005];
int n,maxx,ans;

int compare(const void*p1,const void*p2)
{
	struct node *a=(struct node*) p1;
	struct node *b=(struct node*) p2;
	return ((a->val>b->val)?1:-1);
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ori[i].val);
		ori[i].pos=i;
	}
	qsort(ori+1,n,sizeof(struct node),compare);
	for(i=1;i<=n;i++)
	{
		maxx=((maxx>ori[i].pos)?maxx:ori[i].pos);
		ans=((ans>(maxx-ori[i].pos))?ans:(maxx-ori[i].pos));
	} 
	printf("%d\n",ans);
	return 0;
}
