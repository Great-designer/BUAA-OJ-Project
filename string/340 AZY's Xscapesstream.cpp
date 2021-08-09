#include<iostream>
#include<sstream>

using namespace std;

string MidOrder,BackOrder;
int Mid[10010],Back[10010];
int lchild[10010],rchild[10010];
int n,ans,Sum;

int buildTree(int l1,int r1,int l2,int r2)
{
	if(l1>r1)
	{
		return 0;
	}
	int root=Back[r2];
	int p=l1;
	while(Mid[p]!=root)
	{
		++p;
	}
	int cnt=p-l1;
	lchild[root]=buildTree(l1,p-1,l2,l2+cnt-1);
	rchild[root]=buildTree(p+1,r1,l2+cnt,r2-1);
	return root;
}

void dfs(int u,int sum)
{
	sum+=u;
	if(!lchild[u]&&!rchild[u])
	{
		if(sum<Sum||(sum==Sum&&u<ans))
		{
			ans=u;
			Sum=sum;
		}
	}
	if(lchild[u])
	{
		dfs(lchild[u],sum);
	}
	if(rchild[u])
	{
		dfs(rchild[u],sum);
	}
}

int main()
{
	while(getline(cin,MidOrder))
	{
		getline(cin,BackOrder);
		int x;
		stringstream s1(MidOrder);
		stringstream s2(BackOrder);
		n=0;
		while(s1 >> x)
		{
			Mid[n++]=x;
		}
		n=0;
		while(s2 >> x)
		{
			Back[n++]=x;
		}
		buildTree(0,n-1,0,n-1);
		Sum=0x3f3f3f3f;
		dfs(Back[n-1],0);
		printf("%d\n",ans);
	}
}
