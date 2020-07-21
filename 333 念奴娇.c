#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Tree
{
	struct Tree *lchild,*rchild;
};

char input[10010];
struct Tree *s[10010];

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

int JudgeMirror(struct Tree *l,struct Tree *r)
{
	if(l!=NULL&&r!=NULL)
	{
		if(JudgeMirror(l->lchild,r->lchild)&&JudgeMirror(l->rchild,r->rchild))
		{
			return 1;
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

int Judge(struct Tree *root)
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
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",input);
		struct Tree* root=NULL;
		struct Tree* p=NULL;
		int top=-1,k=0,j=0;
		int i;
		for(i=0;i<10010;i++)
		{
			s[i]=NULL;
		}
		char c;
		root=NULL;
		c=input[j];
		while(c!='\0')
		{
			switch(c)
			{
				case'(':
					top++;
					s[top]=p;
					k=1;
					break;
				case')':
					top--;
					break;
				case',':
					k=2;
					break;
				default:
					p=(struct Tree*)malloc(sizeof(struct Tree*));
					while(input[j+1]!='('&&input[j+1]!=')'&&input[j+1]!=','&&input[j+1]!='\0')
					{
						j++;
					}
					p->lchild=p->rchild=NULL;
					if(root==NULL)
					{
						root=p;
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
			j++;
			c=input[j];
		}
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
