#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Tree
{
	char value;
	struct Tree *lchild,*rchild;
};

char input[1010];
int index;
int n;

void createBinTree(struct Tree **t)
{
	++index;
	if(input[index]=='\0')
	{
		return;
	}
	if(input[index]!='#')
	{
		*t=(struct Tree*)malloc(sizeof(struct Tree));
		memset(*t,0,sizeof(struct Tree));
		(*t)->value=input[index];
		createBinTree(&(*t)->lchild);
		createBinTree(&(*t)->rchild);
	}
	else
	{
		*t=NULL;
	}
}

int ans;

void dfs(struct Tree* t,int dis)
{
	if(t->lchild==NULL&&t->rchild==NULL&&ans>dis)
	{
		ans=dis;
		return;
	}
	if(t->lchild)
	{
		dfs(t->lchild,dis+1);
	}
	if(t->rchild)
	{
		dfs(t->rchild,dis+1);
	}
}

struct Tree *root;

int main()
{
	while(~scanf("%s",input+1))
	{
		ans=114514;
		index=0;
		createBinTree(&root);
		if(root==NULL)
		{
			puts("0");
		}
		else
		{
			dfs(root,1);
			printf("%d\n",ans);
		}
	}
}
