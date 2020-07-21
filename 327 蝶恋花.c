#include<stdio.h>
#include<stdlib.h>

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
		(*t)=(struct Tree*)malloc(sizeof(struct Tree));
		(*t)->value=input[index];
		createBinTree(&((*t)->lchild));
		createBinTree(&((*t)->rchild));
	}
	else
	{
		(*t)=NULL;
	}
}

int height(struct Tree *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		int l=height(t->lchild);
		int r=height(t->rchild);
		return (l<r)?r+1:l+1;
	}
}

struct Tree *root;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",input+1);
		index=0;
		createBinTree(&root);
		printf("%d\n",height(root));
	}
}
