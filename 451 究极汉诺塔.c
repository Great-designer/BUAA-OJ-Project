#include<stdio.h>

int n,top,mid;
long long ans;
int pos[65];
int target[65];

long long hanoi(int step)
{
	return (1LL<<(long long)step)-1;
}

long long move(int stat[],int now,int tgt)
{
	if(now==0)
	{
		return 0;
	}
	else if(stat[now]==tgt)
	{
		return move(stat,now-1,tgt);
	}
	else
	{
		return move(stat,now-1,6-tgt-stat[now])+hanoi(now-1)+1;
	}
}

int main()
{
	while(~scanf("%d",&n)&&n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&pos[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&target[i]);
		}
		top=n;
		while(top>=1&&pos[top]==target[top])
		{
			top--;
		}
		if(top>0)
		{
			mid=6-pos[top]-target[top];
			ans=move(pos,top-1,mid)+move(target,top-1,mid)+1;
		}
		else
		{
			ans=0;
		}
		printf("%lld\n",ans);
	}
}


