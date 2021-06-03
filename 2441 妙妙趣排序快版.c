#include<stdio.h>

int map[55];
int ori[55];

int n,k,tmp,ans;

struct node
{
	int l,r;
};

struct node node[11];

void dfs(int step)
{
	if(step==1)
	{
		int i;
		for(i=1; i<=n; i++)
		{
			ori[i]=map[i]; /* 其实也可以不储存，因为有回溯，不会打乱 */
		}
	}
	if(step==k+1)
	{
		ans++;
		return;
	}
	int num=k-step+1;
	if(ori[node[num].l]<ori[node[num].r])
	{
		dfs(step+1);
		tmp=ori[node[num].l];
		ori[node[num].l]=ori[node[num].r];
		ori[node[num].r]=tmp;
		dfs(step+1);
		tmp=ori[node[num].l];
		ori[node[num].l]=ori[node[num].r];
		ori[node[num].r]=tmp;
	}
	return;
}

void func1()
{
	int i;
	for(i=1; i<=n-1; i++) /* 从i进行交换 */
	{
		int j;
		for(j=1; j<=n; j++)
		{
			map[j]=j;
		}
		for(j=1; j<=n-i; j++)
		{
			tmp=map[i+j-1];
			map[i+j-1]=map[i+j];
			map[i+j]=tmp;
			dfs(1);
		}
	}
}

void func2()
{
	int i;
	for(i=2; i<=n-1; i++)
	{
		int j;
		for(j=1; j<=n; j++)
		{
			map[j]=j;
		}
		tmp=map[i+1];
		map[i+1]=map[i];
		map[i]=tmp;
		for(j=1; j<=i-1; j++)
		{
			tmp=map[i-j+1];
			map[i-j+1]=map[i-j];
			map[i-j]=tmp;
			dfs(1);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		int j;
		for(j=1; j<=k; j++)
		{
			scanf("%d%d",&node[j].l,&node[j].r);
		}
		func1();
		func2();
		for(j=1; j<=n; j++)
		{
			map[j]=j;
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
