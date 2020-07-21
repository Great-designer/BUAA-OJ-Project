#include<stdio.h>
#include<stdlib.h>

#include<algorithm>
#include<vector>

using namespace std;

struct Tree
{
	int value;
	struct Tree *lchild,*rchild;
};

char isTree;

struct Tree* getTree(vector<int> &preorder,vector<int> &inorder,int prebegin,int preend,int inbegin,int inend)
{
	if(prebegin<preend&&inbegin<inend)
	{
		struct Tree* rev=(struct Tree*)malloc(sizeof(struct Tree));
		rev->value=preorder[prebegin];
		rev->lchild=rev->rchild=NULL;
		vector<int>::iterator mid=find(inorder.begin()+inbegin,inorder.begin()+inend,preorder[prebegin]);
		if(mid==inorder.end())
		{
			isTree=0;
			return NULL;
		}
		int offset=mid-(inorder.begin()+inbegin);
		rev->lchild=getTree(preorder,inorder,prebegin+1,prebegin+1+offset,inbegin,inbegin+offset);
		rev->rchild=getTree(preorder,inorder,prebegin+1+offset,preend,inbegin+offset+1,inend);
		return rev;
	}
	else return NULL;
}

void printBackOrder(struct Tree* t,vector<int> &v)
{
	if(t->value<=0)
	{
		return;
	}
	if(t->lchild)
	{
		printBackOrder(t->lchild,v);
	}
	if(t->rchild)
	{
		printBackOrder(t->rchild,v);
	}
	v.push_back(t->value);
}

struct Tree t,*ans;

vector<int> pre,in;
vector<int> v;

int n,tmp;

int main()
{
	pre.resize(1100);
	in.resize(1100);
	v.resize(1100);
	while(~scanf("%d",&n))
	{
		pre.clear();
		in.clear();
		v.clear();
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&tmp);
			pre.push_back(tmp);
		}
		for(i=1;i<=n;++i)
		{
			scanf("%d",&tmp);
			in.push_back(tmp);
		}
		isTree=1;
		ans=getTree(pre,in,0,pre.size(),0,in.size());
		printBackOrder(ans,v);
		if(ans==NULL||v.size()!=n||!isTree)
		{
			printf("No\n");
		}
		else
		{
			vector<int>::iterator a;
			for(a=v.begin();a!=v.end();a++)
			{
				printf("%d ",*a);
			}
			printf("\n");
		}
	}
}
