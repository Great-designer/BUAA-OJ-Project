#include<stdio.h>

int n;

struct node
{
	int x,y;
	int father;
};

struct node info[110];

int getFather(int x)
{
	return info[x].father==x?x:(info[x].father=getFather(info[x].father));
}

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&info[i].x,&info[i].y);
			info[i].father=i;
		}
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				if(i==j)
				{
					continue;
				}
				if(info[i].x==info[j].x||info[i].y==info[j].y)
				{
					int a=getFather(i);
					int b=getFather(j);
					if(a!=b)
					{
						info[a].father=b;
					}
				}
			}
		}
		int ans=0;
		for(i=1;i<=n;++i)
		{
			if(info[i].father==i)
			{
				++ans;
			}
		}
		printf("%d\n",ans-1);
	}
}
