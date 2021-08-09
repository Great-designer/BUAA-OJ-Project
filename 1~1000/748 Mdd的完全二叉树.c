#include<stdio.h>

struct Tree
{
	int value;
	int lchild,rchild;
};

struct Tree tree[100010];

int Size;

int s[100010];
int top;

void inorderiteration()
{
	top=0;
	int cur=1;
	while(cur||top!=0)
	{
		if(cur)
		{
			s[top]=cur;
			top++;
			cur=tree[cur].lchild;
		}
		else
		{
			cur=s[top-1];
			printf("%d ",tree[cur].value);
			top--;
			cur=tree[cur].rchild;
		}
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		tree[++Size].value=n;
		tree[Size].lchild=tree[Size].rchild=0;
    }
	int i;
	for(i=1;i<=Size;++i)
	{
		if((i<<1)<=Size)
		{
			tree[i].lchild=i<<1;
		}
		if(((i<<1)+1)<=Size)
		{
			tree[i].rchild=(i<<1)+1;
		}
	}
	inorderiteration();
}

