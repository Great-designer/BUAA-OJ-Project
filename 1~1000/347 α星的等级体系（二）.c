#include<stdio.h>
#include<stdlib.h>

struct Tree
{
	struct Tree *lchild,*rchild;
};

char input[30010];
struct Tree *s[30010];
struct Tree *q[30010];
int front;
int rear;

char bfs(struct Tree *t)
{
	front=rear=0;
	q[rear]=t;
	rear++;
	struct Tree *s;
	while((s=q[front])!=NULL)
	{
		front++;
		q[rear]=s->lchild;
		rear++;
		q[rear]=s->rchild;
		rear++;
	}
	while(front!=rear)
	{
		s=q[front];
		if(s)
		{
			return 0;
		}
		front++;
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",input);
		struct Tree *root=NULL;
		struct Tree *p=NULL;
		int top=-1,k=0,j=0;
		int i;
		for(i=0;i<30010;i++)
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
		if(bfs(root))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
}
