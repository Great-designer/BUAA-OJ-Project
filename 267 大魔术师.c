#include<stdio.h>
#include<stdlib.h>

int l,r,t,tmpInt;

struct List
{
	int data;
	struct List *next;
};

struct List *addNode(int num,struct List *fNode)
{
	struct List *lNode=fNode;
	while(lNode->next!=fNode)
	{
		lNode=lNode->next;
	}
	struct List *nNode=malloc(sizeof(struct List));
	nNode->data=num;
	nNode->next=fNode;
	lNode->next=nNode;
	fNode->data++;
	return nNode;
}

void deleteNode(int pos,struct List *fNode)
{
	struct List *tNode=fNode;
	int i;
	for(i=1;i<pos;++i)
	{
		tNode=tNode->next;
	}
	tNode->next=tNode->next->next;
	fNode->data--;
}

void printList(struct List *fNode)
{
	struct List *tNode=fNode->next;
	while(tNode!=fNode)
	{
		printf("%d ",tNode->data);
		tNode=tNode->next;
	}
	putchar('\n');
}

int main()
{
	while(~scanf("%d",&t))
	{
		struct List *lists=malloc(sizeof(struct List));
		lists->data=0;
		lists->next=lists;
		int i;
		for(i=0;i<t;++i)
		{
			scanf("%d",&tmpInt);
			addNode(tmpInt,lists);
		}
		scanf("%d%d",&l,&r);
		for(i=0;i<r-l+1;++i)
		{
			deleteNode(l,lists);
		}
		printList(lists);
		free(lists);
	}
	return 0;
}
