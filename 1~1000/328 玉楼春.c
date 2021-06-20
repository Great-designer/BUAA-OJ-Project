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

void createBinTree(struct Tree **t)
{
	struct Tree* p=NULL;
	struct Tree* s[10010];
	int top=-1,k=0,j=0;
	char c;
	(*t)=NULL;
	c=input[j];
	while(c!='\0')
	{
		switch (c)
		{
			case '(':
				s[++top]=p;
				k=1;
				break;
			case ')':
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

int height(struct Tree* t)
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

char JudgeMirror(struct Tree* l,struct Tree* r)
{
	if(l!=NULL&&r!=NULL)
	{
		if(JudgeMirror(l->lchild,r->rchild)&&JudgeMirror(l->rchild,r->lchild))
		{
			if(strcmp(l->value,r->value)==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else if(l==NULL&&r==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char Judge(struct Tree *root)
{
	if(root==NULL)
	{
		return 1;
	}
	else
	{
		return JudgeMirror(root->lchild,root->rchild);
	}
}

int main()
{
	while(~scanf("%s",input))
	{
		struct Tree *root=NULL;
		createBinTree(&root);
		if(height(root)==1)
		{
			puts("YES");
		}
		else
		{
			if(Judge(root))
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
}

