#include<stdio.h>

int n,m,ngift[25][25],hgift[25],ans,tmpgift[25],vis[25];

void dfs(int step,int total) //step是到了第几个人 total是选择了几个人
{
	if(step==m+1) //递归到了终点也就是最后一个人也结束了
	{
		if(total>ans) ans=total;//大于总数 更新答案并返回
		return;
	}
	int i,flag=0;
	for(i=1; i<=n; i++)
	{
		if(tmpgift[i]+ngift[step][i]>hgift[i]) //已经大于了 没有进行的必要了
		{
			flag=1;
			break;
		}
	}
	if(!flag) //不大于 可以选
	{
		for(i=1; i<=n; i++)
		{
			tmpgift[i]+=ngift[step][i];//将已经消耗的礼物更新
		}
		dfs(step+1,total+1);//到下一个人 并且选择了这个人
		for(i=1; i<=n; i++)
		{
			tmpgift[i]-=ngift[step][i];//递归回来 要减下去表示不选了
		}
	}
	dfs(step+1,total);//递归到下一个人 并且不选这个人
}

int main()
{
	scanf("%d %d",&m,&n);
	int i,j;
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d",&ngift[i][j]);
		}
	}
	for(i=1; i<=n; i++)
	{
		scanf("%d",&hgift[i]);
	}
	dfs(1,0);
	printf("%d",ans);
	return 0;
}