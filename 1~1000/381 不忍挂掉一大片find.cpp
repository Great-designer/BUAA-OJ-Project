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

bool isTree;

struct Tree *getTree(vector<int> &preorder,vector<int> &inorder,int prebegin,int preend,int inbegin,int inend)
{
	if(prebegin<preend&&inbegin<inend)
	{
		struct Tree *rev=(struct Tree*)malloc(sizeof(struct Tree));
		rev->value=preorder[prebegin];
		rev->lchild=rev->rchild=NULL;
		vector<int>::iterator mid=find(inorder.begin()+inbegin,inorder.begin()+inend,preorder[prebegin]);
		if(mid==inorder.end())
		{
			isTree=false;
			return NULL;
		}
		int offset=mid-(inorder.begin()+inbegin);
		rev->lchild=getTree(preorder,inorder,prebegin+1,prebegin+1+offset,inbegin,inbegin+offset);
		rev->rchild=getTree(preorder,inorder,prebegin+1+offset,preend,inbegin+offset+1,inend);
		return rev;
	}
	else
	{
		return NULL;
	}
}

struct Tree *buildTree(vector<int> &preorder,vector<int> &inorder)
{
	return getTree(preorder,inorder,0,preorder.size(),0,inorder.size());
}

void printBackOrder(struct Tree *t,vector<int> &v)
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

struct Tree *q[10010];
int front,rear;

void printBFS(struct Tree *t,vector<int> &v)
{
	front=rear=0;
	q[rear]=t;
	rear++;
	while(front!=rear)
	{
		struct Tree *t1=q[front];
		front++;
		v.push_back(t1->value);
		if(t1->lchild)
		{
			q[rear]=t1->lchild;
			rear++;
		}
		if(t1->rchild)
		{
			q[rear]=t1->rchild;
			rear++;
		}
	}
}

struct Tree t,*ans;
vector<int> pre,in;
vector<int> v,v2;
int n,tmp;

int main()
{
	pre.resize(1100);
	in.resize(1100);
	v.resize(1100);
	v2.resize(1100);
	while(~scanf("%d",&n))
	{
		pre.clear();
		in.clear();
		v.clear();
		v2.clear();
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
		isTree=true;
		ans=buildTree(pre,in);
		printBackOrder(ans,v);
		if(ans==NULL||v.size()!=n||!isTree)
		{
			puts("No");
		}
		else
		{
			vector<int>::iterator a;
			for(a=v.begin();a!=v.end();a++)
			{
				printf("%d ",*a);
			}
			putchar('\n');
			printBFS(ans,v2);
			for(a=v2.begin();a!=v2.end();a++)
			{
				printf("%d ",*a);
			}
			putchar('\n');
		}
	}
}
