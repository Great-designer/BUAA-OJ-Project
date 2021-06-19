#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int elem;//元素
	int index;//原下标
	int in;//目标下标
};//结构体数组，记录数据和下标
struct node mp1[100005],mp2[100005];
int cmp(struct node *a,struct node *b)
{
	return a->elem>b->elem;
}
int cmp2(struct node *a,struct node *b)
{
	return a->elem<b->elem;
}
int cmp3(struct node *a,struct node *b)
{
	return a->index>b->index;
}
int n;
int vis[100005];
int jiaohuan(struct node arr[])//求最少交换次数函数
{
	int sum=0;
	memset(vis,0,sizeof(vis));
	for(int i=0; i<n; i++)
	{

		if(vis[i]==0)
		{
			int l=i;
			int p=i;
			while(1)
			{
				vis[p]=1;
				p=arr[p].in;
				if(p==l) break;
			}
			++sum;
		}
	}
	return n-sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&mp1[i].elem);
			mp1[i].index=i;
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d",&mp2[i].elem);
			mp2[i].index=i;
		}
		qsort(mp1,n,sizeof(struct node),cmp);
		qsort(mp2,n,sizeof(struct node),cmp2);
		for(int i=0; i<n; i++)
		{
			mp1[i].in=mp2[i].index;//确定目标下标
		}
		qsort(mp1,n,sizeof(struct node),cmp3);
		int ans=jiaohuan(mp1);
		long long int _=0;
		qsort(mp1,n,sizeof(struct node),cmp);
		for(int i=0; i<n; i++)
		{
			_=_+(long long)mp1[i].elem*mp2[i].elem;//强制转换
		}
		printf("%lld %d\n",_,ans);
	}
	return 0;
}

