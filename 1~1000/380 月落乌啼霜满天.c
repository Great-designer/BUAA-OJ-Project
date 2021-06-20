#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char flag;

struct Tree
{
	char value[110];
	struct Tree *lchild,*rchild;
};

char input[10010];

void createBinTree(struct Tree **t)
{
	struct Tree *p=NULL;
	struct Tree *s[10010];
	int top=-1,k=0,j=0;
	char c;
	(*t)=NULL;
	c=input[j];
	while(c!='\0')
	{
		switch(c)
		{
			case'(':
				s[++top]=p;
				k=1;
				break;
			case')':
				--top;
				break;
			case',':
				k=2;
				break;
			default:
				p=(struct Tree*)malloc(sizeof(struct Tree));
				while(input[j+1]!='('&&input[j+1]!=')'&&input[j+1]!=','&&input[j+1]!='\0')
				{
					strncat(p->value,&input[j],1);
					j++;
				}
				strncat(p->value,&input[j],1);
				p->lchild=p->rchild=NULL;
				if((*t)==NULL)
				{
					(*t)=p;
				}
				else
				{
					switch(k)
					{
						case 1:
							s[top]->lchild=p;
							break;
						case 2:
							s[top]->rchild=p;
							break;
						default:
							break;
					}
				}
		}
		c=input[++j];
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

void isLeaf(struct Tree *t)
{
	if(!t->lchild&&!t->rchild)
	{
		printf("%s ",t->value);
	}
	else
	{
		if(t->lchild)
		{
			isLeaf(t->lchild);
		}
		if(t->rchild)
		{
			isLeaf(t->rchild);
		}
	}
}

void printHTML(struct Tree *t,int dep)
{
	int i;
	for(i=0;i<dep;++i)
	{
		putchar(' ');
	}
	printf("<%s>\n",t->value);
	if(t->lchild)
	{
		printHTML(t->lchild,dep+2);
	}
	if(t->rchild)
	{
		printHTML(t->rchild,dep+2);
	}
	for(i=0;i<dep;++i)
	{
		putchar(' ');
	}
	printf("</%s>\n",t->value);
}

int main()
{
	while(~scanf("%s",input))
	{
		struct Tree* root=NULL;
		createBinTree(&root);
		printf("height=%d\n",height(root));
		isLeaf(root);
		putchar('\n');
		printHTML(root,0);
	}
}
