#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	char data[220];
	struct node* next;
};

struct LinkQueue
{
	struct node* front;
	struct node* rear;
};

void initQueue(struct LinkQueue *q)
{
	(*q).front =(*q).rear=(struct node*)malloc(sizeof(struct node));
	(*q).front->next = NULL;
}

char isEmpty(struct LinkQueue *q)
{
	if((*q).front ==(*q).rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueSize(struct LinkQueue *q)
{
	int counter = 0;
	struct node* p =(*q).front->next;
	while (p != NULL)
	{
		p = p->next;
		counter++;
	}
	return counter;
}

int EnQueue(struct LinkQueue *q,char e[])
{
	struct node* p =(struct node*)malloc(sizeof(struct node));
	strcpy(p->data,e);
	if (isEmpty(&(*q)))
	{
		(*q).front->next = p;
		(*q).rear = p;
		p->next = NULL;
	}
	else
	{
		(*q).rear->next = p;
		(*q).rear = p;
		p->next = NULL;
	}
	return 1;
}

int DeQueue(struct LinkQueue *q)
{
	if (isEmpty(&(*q)))
	return 0;
	else
	{
		struct node* p;
		p =(*q).front->next;
		(*q).front->next = p->next;
		if((*q).rear == p)
		{
			(*q).rear =(*q).front;
		}
		free(p);
	}
	return 1;
}

int getId(struct LinkQueue *q, int m)
{
	int i = 1;
	struct node* p =(*q).front->next;
	while (i < m && p != NULL)
	{
		p = p->next;
		i++;
	}
	printf("%s\n", p->data);
	return 1;
}

void destroyQueue(struct LinkQueue *q)
{
	while((*q).front)
	{
		(*q).rear =(*q).front->next;
		free((*q).front);
		(*q).front =(*q).rear;
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		struct LinkQueue q;
		initQueue(&q);
		char opera[220];
		int i;
		for(i = 0; i < n; i++)
		{
			scanf("%s",opera);
			if(strcmp(opera,"add")==0)
			{
				char str[220];
				scanf("%s",str);
				if (queueSize(&q) >= 25)
				puts("GzhIsSoHandsome");
				else
				{
					EnQueue(&q, str);
				}
			}
			else if(strcmp(opera,"get")==0)
			{
				int m;
				scanf("%d",&m);
				int size1 = queueSize(&q);
				if (m <= 0 || m > size1)
				{
					puts("GzhIsSoHandsome");
				}
				else
				{
					getId(&q, m);
				}
			}
			else if(strcmp(opera,"delete")==0)
			{
				int m;
				scanf("%d",&m);
				if (m<0 || m>queueSize(&q))
				{
					puts("GzhIsSoHandsome");
				}
				else
				{
					int j;
					for(j = 0;j< m;j++)
					{
						DeQueue(&q);
					}
				}
			}
		}
		destroyQueue(&q);
	}
}
