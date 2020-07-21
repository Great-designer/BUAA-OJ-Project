#include<stdio.h>
#include<stdlib.h>

struct node
{    
	char data;    
	struct node *lchild;    
	struct node *rchild;
};

void CreateBTNode(struct node **b,char *str)
{    
	struct node *St[20000],*p;    
	int top=-1,k,j=0;    
	char ch;    
	*b=NULL;    
	ch=str[j];    
	while(ch!='\0')    
	{        
		switch(ch)        
		{            
			case '(': 
			{
				top++; 
				St[top]=p; 
				k=1; 
				break;  
			}          
			case ')': 
			{
				top--; 
				break;
			}            
			case ',': 
			{
				k=2; 
				break;            
			}
			default: 
			{
				p=(struct node *)malloc(sizeof(struct node));                     
				p->data=ch; 
				p->lchild=p->rchild=NULL;                     
				if(*b==NULL)                         
				{
					*b=p;
				}                     
				else                     
				{                         
					switch(k)                         
					{                             
						case 1: 
						{
							St[top]->lchild=p; 
							break;
						}                             
						case 2: 
						{
							St[top]->rchild=p;
							break;
						}                         
					}                     
				}
			}        
		}        
		j++;        
		ch=str[j];    
	}
}

int leaf(struct node *T)
{
	if(T==NULL)
	{
		return 0;
	}
	else if((T->lchild==NULL)&&(T->rchild==NULL))
	{
		return 1;
	}
	else
	{
		return leaf(T->lchild)+leaf(T->rchild);
	}
}

char str[30000];  

int main()
{    
	int t;   
	scanf("%d",&t);
	int i;   
	for(i=0;i<t;i++)   
	{
		scanf("%s",str);          
		struct node *b;           
		CreateBTNode(&b,str);           
		printf("%d\n",leaf(b));
		int j;           
		for(j=0;j<t;j++)           
		{                   
			str[j]=0;           
		}   
	}
}

