#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,*p,*t,*q;
int i,j;

void sum(struct node *head)
{
    t=head;
    long long summ=0;
    if(t->next->next==NULL||t->next==NULL||t==NULL)
    {
        printf("0\n");
    }
    else
    {
        t=t->next->next;
        summ+=t->data;
        while(t!=NULL)
        {
            if(t->next==NULL||t->next->next==NULL||t->next->next->next==NULL||t->next->next->next->next==NULL||t->next->next->next->next->next==NULL)
            {
                break;
            }
            else
            {
                t=t->next->next->next->next->next;
                summ+=t->data;
            }
        }
    }
    printf("%lld\n",summ);
}

int main()
{    
    int n,a;
    char s[100];
    while(~scanf("%d",&n))
    {
        head=NULL;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            if(strcmp(s,"Add")==0)
            {
                scanf("%d",&a);
                if(head==NULL)
                {
                    p=(struct node *)malloc(sizeof(struct node));
                    head=p;
                    p->data=a;
                    p->next=NULL;
                }
                else
                {
                    t=head;
                    while(t!=NULL)
                    {
                        if(head->data>a)
                        {
                            p=(struct node*)malloc(sizeof(struct node));
                            p->data=a;
                            p->next=head;
                            head=p;
                            break;
                        }
                        else if(t->next==NULL || t->next->data>a)
                        {
	                        p=(struct node*)malloc(sizeof(struct node));
	                        p->data=a;
	                        p->next=t->next;
	                        t->next=p;
	                        break;
                        }
                        t=t->next;
                    }
                }
            }
            else if(strcmp(s,"Del")==0) 
            {
                scanf("%d",&a);
                t=head;
                while(t!=NULL)
                {
                    if(t->next==NULL)
                    {
                        head=NULL;
                    }
                    else if(t->next->data==a)
                    {
                        q=t->next; 
                        t->next=t->next->next;
                        free(q);
                        break;
                    }
                    t=t->next;    
                }
            }
            else if(strcmp(s,"Sum")==0)
            {
                sum(head);
            }
        }
    }
    return 0;
}

