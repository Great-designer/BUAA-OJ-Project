#include<stdio.h>

int map[55];

int n,k,tmp,ans;

struct node
{
	int l,r;
};

struct node node[11];

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void dfs(int step)
{
	if(step==k+1)//经过了所有筛选器筛选，所以++
	{
		ans++;
		return;
	}
	int num=k-step+1;
	if(map[node[num].l]<map[node[num].r])//可能是经过这个筛选器得到的数列
	{
		dfs(step+1);//判断前一个筛选器
		swap(&map[node[num].l],&map[node[num].r]);//交换后再进行判断
		dfs(step+1);
		swap(&map[node[num].l],&map[node[num].r]);//交换回来防止出错
	}
}

int main()
{
	int cnt;
	scanf("%d",&cnt);
	while(cnt--)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		int j;
		for(j=1; j<=k; j++)
		{
			scanf("%d%d",&node[j].l,&node[j].r);
		}
		int i;
		for(i=1; i<=n-1; i++)//从i进行交换
		{
			for(j=1; j<=n; j++)
			{
				map[j]=j;
			}
			for(j=1; j<=n-i; j++)
			{
				swap(&map[i+j-1],&map[i+j]);
				dfs(1);
			}
		}
		for(i=2; i<=n-1; i++)
		{
			for(j=1; j<=n; j++)
			{
				map[j]=j;
			}
			swap(&map[i+1],&map[i]);
			for(j=1; j<=i-1; j++)
			{
				swap(&map[i-j+1],&map[i-j]);
				dfs(1);
			}
		}
		for(j=1; j<=n; j++)
		{
			map[j]=j;
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
