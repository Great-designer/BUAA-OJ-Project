#include<stdio.h>
#include<string.h>

char mat[5005][5005];
int match[5005];//记录男孩i被女孩选择的女孩编号，未被选则0
char vis[5005];//每次记录男孩i是否被占用了

char Hungary(int x,int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		if(mat[x][i]&&!vis[i])//如果有连线且match[i]没有被本次查找遍历过
		{
			vis[i]=1;
			if(!match[i]||Hungary(match[i],n))//如果match[i]没有被占用或者能把占用match[i]的人换一个连线，短路原则如果没有被占用则不会执行后面的部分
			{
				match[i]=x;//这一步的作用是执意要将match[i]匹配给x，尽可能给腾位置出来，因为她可能占了别的女生相匹配的男生
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(mat,0,sizeof(mat));
		memset(match,0,sizeof(match));//match[]数组存放的是已经匹配好的方案，如果是0则未匹配
		int i;
		for(i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			if(x!=0)
			{
				mat[x][i]=1;
			}
		}
		for(i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			if(x!=0)
			{
				mat[i][x]=1;
			}
		}
		int ans=0;
		for(i=1; i<=n; i++) //匈牙利算法主函数
		{
			memset(vis,0,sizeof(vis));//vis每一次都将所有的男生编号都标记为没遍历过，注意区分vis[]和match[]数组功能的区别
			ans+=Hungary(i,n);//如果能直接相连或别人腾出位置总数+1
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
