#include<stdio.h>

#include<iostream>
#include<sstream>

using namespace std;

int n;

struct BST
{
	int value;
	struct BST *lchild,*rchild;
};

void InsertBST(struct BST *&t,int value)
{
	if(t==NULL)
	{
		t=new struct BST;
		t->lchild=t->rchild=NULL;
		t->value=value;
	}
	else
	{
		if(value<t->value)
		{
			InsertBST(t->lchild,value);
		}
		else
		{
			InsertBST(t->rchild,value);
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

struct BST *q[20020];
int front,rear;

void printBFS(struct BST *t)
{
	front=rear=0;
	q[rear]=t;
	rear++;
	while(front!=rear)
	{
		struct BST *x=q[front];
		front++;
		printf("%d ",x->value);
		if(x->lchild)
		{
			q[rear]=x->lchild;
			rear++;
		}
		if(x->rchild)
		{
			q[rear]=x->rchild;
			rear++;
		}
	}
}

string input;

int main()
{
	while(getline(cin,input))
	{
		struct BST *root=NULL;
		stringstream s1(input);
		int n;
		while(s1>>n)
		{
			InsertBST(root,n);
		}
		printPre(root);
		putchar('\n');
		printMi(root);
		putchar('\n');
		printBack(root);
		putchar('\n');
		printBFS(root);
		putchar('\n');
	}
}

