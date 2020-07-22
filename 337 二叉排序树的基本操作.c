#include<stdio.h>
#include<stdlib.h> 

int n;
int input;

struct BST
{
	int value;
	struct BST *lchild,*rchild;
};

void InsertBST(struct BST **t,int value)
{
	if(*t==NULL)
	{
		*t=(struct BST*)malloc(sizeof(struct BST*));
		(*t)->lchild=(*t)->rchild=NULL;
		(*t)->value=value;
	}
	else
	{
		if(value<(*t)->value)
		{
			InsertBST(&((*t)->lchild),value);
		} 
		else
		{
			InsertBST(&((*t)->rchild),value);
		} 
	}
}

void printPre(struct BST *t)
{
	if(t)
	{
		printf("%d ",t->value);
		printPre(t->lchild);
		printPre(t->rchild);
	}
}

void printMi(struct BST *t)
{
	if(t)
	{
		printMi(t->lchild);
		printf("%d ",t->value);
		printMi(t->rchild);
	}
}

void printBack(struct BST *t)
{
	if(t)
	{
		printBack(t->lchild);
		printBack(t->rchild);
		printf("%d ",t->value);
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		struct BST *root=NULL;
		while(n--)
		{
			scanf("%d",&input);
			InsertBST(&root,input);
		}
		printPre(root);
		putchar('\n');
		printMi(root);
		putchar('\n');
		printBack(root);
		putchar('\n');
	}
}
