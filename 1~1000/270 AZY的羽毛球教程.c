#include<stdio.h>
#include<string.h>

struct Queue
{
	int head;
	int tail;
	int data[1100];
	int length;
	int cnt;
};

void InitQueue(struct Queue *q,int n)
{
	q->head=0;
	q->tail=0;
	q->cnt=0;
	q->length=n;
}

void PopFront(struct Queue *q,int *z)
{
	*z=q->data[q->head];
	q->head=(q->head+1)%q->length;
	q->cnt--;
}

void PushBack(struct Queue *q,int m)
{
	q->data[q->tail]=m;
	q->tail=(q->tail+1)%q->length;
	q->cnt++;
}

int main()
{
	int n,m,k;
	char a[10];
	while(~scanf("%d%d",&n,&m))
	{
		struct Queue q;
		InitQueue(&q,n);
		while(m--)
		{
			scanf("%s",a);
			if(a[0]=='P')
			{
				int t;
				scanf("%d",&k);
				if(q.cnt!=n)
				{
					PushBack(&q,k);
					printf("JUSTME\n");
				}
				else
				{
					PopFront(&q,&t);
					PushBack(&q,k);
					printf("OOPS\n");
				}
			}
			else if(a[0]=='R')
			{
				int x;
				if(q.cnt!=0)
				{
					PopFront(&q,&x);
					printf("%d\n",x);
				}
				else
				{
					printf("NONE\n");
				}
			}
			else
			{
				scanf("%d",&k);
				int y,z;
				char judge;
				judge=0;
				y=q.cnt;
				while(y--)
				{
					PopFront(&q,&z);
					if(z==k)
					{
						judge=1;
						break;
					}
					else
					{
						PushBack(&q,z);
					}
				}
				if(judge==1)
				{
					printf("GOTIT\n");
				}
				else
				{
					printf("WHERE\n");
				}
			}
		}
	}
	return 0;
}
