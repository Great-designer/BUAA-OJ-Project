#include<stdlib.h>

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Tree
{
	char value;
	struct Tree *lchild,*rchild;
};

bool isTree;

struct Tree *getTree(vector<char> &preorder,vector<char> &inorder,int prebegin,int preend,int inbegin,int inend)
{
	if(prebegin<preend&&inbegin<inend)
	{
		struct Tree *rev=(struct Tree*)malloc(sizeof(struct Tree));
		rev->value=preorder[prebegin];
		rev->lchild=rev->rchild=NULL;
		vector<char>::iterator mid=find(inorder.begin()+inbegin,inorder.begin()+inend,preorder[prebegin]);
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
	else
	{
		return NULL;
	}
}

struct Tree *buildTree(vector<char> &preorder,vector<char> &inorder)
{
	return getTree(preorder,inorder,0,preorder.size(),0,inorder.size());
}

void printBackOrder(struct Tree *t,vector<char> &v)
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

int n,tmp;
struct Tree t,*ans;

vector<char> pre,in;
vector<char> v;
string a,b;

int main()
{
	pre.resize(1100);
	in.resize(1100);
	v.resize(1100);
	while(cin >> a >> b)
	{
		n=a.length();
		pre.clear();
		in.clear();
		v.clear();
		int i;
		for(i=0;i<n;++i)
		{
			pre.push_back(a[i]);
		}
		for(i=0;i<n;++i)
		{
			in.push_back(b[i]);
		}
		isTree=1;
		ans=buildTree(pre,in);
		printBackOrder(ans,v);
		if(ans==NULL||v.size()!=n||!isTree)
		{
			printf("No\n");
		}
		else
		{
			vector<char>::iterator a;
			for(a=v.begin();a!=v.end();a++)
			{
				printf("%c",*a);
			}
			printf("\n");
		}
	}
}
