#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct mtree
{
	int data;
	struct mtree *lchild,*rchild;
};

char a[5010];
struct mtree *s[1010];
int top;

void mCreate(struct mtree **t)
{
	top=0;
	(*t)=NULL;
	struct mtree *q,*p;
	char ok=1;
	char ch;
	int l=strlen(a);
	int i; 
	for(i=0;i<l;i++)
	{
		ch=a[i];
		switch(ch)
		{
			case'(':
				s[top]=p;
				top++;
				ok=1;
				break;
			case')':
				q=s[top-1];
				top--;
				break;
			case',':
				ok=0;
				break;
			default:
				p=(struct mtree*)malloc(sizeof(struct mtree));
				p->data=ch-'0';
				if(!(*t))
				{
					(*t)=p;
				}
				else
				{
					q=s[top-1];
					if(ok)
					{
						q->lchild=p;
					}
					else
					{
						q->rchild=p;
					}
				}
		}
	}
}

char flag=0;
int q1[20],level=0;

void find1(struct mtree*t,int cnt,int l)
{
	if(t)
	{
		if(!t->lchild&&!t->rchild)
		{
			cnt+=t->data;
			if(l==cnt)
			{	
				flag=1;
				int i;
				for(i=0;i<level;i++)
				{
					printf("%d ",q1[i]);
				}
				printf("%d\n",t->data);
			}
		}
		if(t->lchild)
		{
			q1[level++]=t->data;
			find1(t->lchild,cnt+t->data,l);
			level--;
		}
		if(t->rchild)
		{
			q1[level++]=t->data;
			find1(t->rchild,cnt+t->data,l);
			level--;
		}
	}
}

int main()
{
	int n,l;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%s",a);
		scanf("%d",&l);
		level=0;
		flag=0;
		printf("Case %d:\n",i);
		if(strlen(a)==1)
		{
			if(a[0]-'0'==l)
			{
				printf("%d\n",l);
			}
			else
			{
				printf("I am so sorry!\n");
			}
		}
		else
		{
			struct mtree *t;
			mCreate(&t);
			find1(t,0,l);
			if(!flag)
			{
				printf("I am so sorry!\n");
			}
		}
	}
}
