#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head;
int length=0;
int flag=0;

struct node *create()
{
	struct node *p,*q,*head;
	head=(struct node*)malloc(sizeof(struct node));
	p=(struct node*)malloc(sizeof(struct node));
	int x;
	scanf("%d",&x);
	p->data=x;
	head->next=p;
	q=p;
	length++;
	while(~scanf("%d",&x))
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->data=x;
		p->next=NULL;
		q->next=p;
		q=p;
		length++;
	}
	q->next=NULL;
	return head;
}

struct node *reverse(struct node *head,int n)
{
	struct node *p,*q,*r,*s;
	p=head;
	q=p->next;
	r=q->next;
	s=q;
	int counter=1;
	if(n>length)
	{
		return head;
	}
	int cnt=length/n;
	int i;
	for(i=0; i<cnt; i++)
	{
		while(counter<n)
		{
			int x=r->data;
			q->next=r->next;
			free(r);
			r=(struct node*)malloc(sizeof(struct node));
			r->data=x;
			p->next=r;
			r->next=s;
			s=r;
			counter++;
			r=q->next;
		}
		p=q;
		if(q->next == NULL)
		{
			break;
		}
		q=q->next;
		r=q->next;
		s=q;
		counter=1;
	}
	return head;
}

void print(struct node *head)
{
	struct node *p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	int n;
	struct node *head;
	scanf("%d",&n);
	head=create();
	reverse(head,n);
	print(head);
}
