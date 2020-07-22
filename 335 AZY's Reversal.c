#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char flag;

struct Tree
{
	char value[300];
	struct Tree *lchild,*rchild;
};

char input[10010];
struct Tree *s[10010];

void createBinTree(struct Tree **t)
{
	struct Tree *p=NULL;
	int i;
	for(i=0;i<10010;++i)
	{
		s[i]=NULL;
	}
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
					strncat(p->value,&input[j++],1);
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
							s[top]->rchild=p;
							break;
						case 2:
							s[top]->lchild=p;
							break;
						default:
							break;
					}
				}
		}
		c=input[++j];
	}
}

void printSheet(struct Tree *t)
{
	printf("%s",t->value);
	if(t->lchild)
	{
		putchar('(');
		printSheet(t->lchild);
		if(t->rchild==NULL)
		{
			putchar(')');
		}
	}
	if(t->rchild)
	{
		if(t->lchild==NULL)
		{
			putchar('(');
		}
		putchar(',');
		printSheet(t->rchild);
		putchar(')');
	}
}

int main()
{
	while(~scanf("%s",input))
	{
		struct Tree* root=NULL;
		createBinTree(&root);
		printSheet(root);
		putchar('\n');
	}
}
