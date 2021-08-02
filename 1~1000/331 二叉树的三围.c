#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Tree
{
	struct Tree *lchild,*rchild;
};

char input[1010];
int cnt[1010];
struct Tree *s[1010];

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

void setDepth(struct Tree* t,int dep)
{
	if (t!=NULL)
	{
		cnt[dep]++;
        if(t->lchild!=NULL)
		{
			setDepth(t->lchild,dep+1);
		}
		if(t->rchild!=NULL)
		{
			setDepth(t->rchild,dep+1);
		}
	}
}

int t;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",input);
		struct Tree *root=NULL,*p=NULL;
		int top=-1,k=0,j=0;
		int i; 
		for(i=0;i<1010;i++)
		{
			s[i]=NULL;
			cnt[i]=0;
		}
		char c=input[j];
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
					p=(struct Tree*)malloc(sizeof(struct Tree));
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
		setDepth(root,1);
		int n=height(root);
		if(n<3)
		{
			puts("Invalid tree!");
		}
		else
		{
			int maxIndex=1;
			int max=cnt[1];
			int i;
			for(i=2;i<=n;++i)
			{
				if(max<cnt[i]||(max==cnt[i]&&i==1&&i!=n))
				{
					max=cnt[i];
					maxIndex=i;
				}
			}
			if(maxIndex==1||maxIndex==n)
			{
				puts("Invalid tree!");
			}
			else
			{
				printf("%d %d %d\n",cnt[maxIndex-1],cnt[maxIndex],cnt[maxIndex+1]);
			}
		}
	}
}

