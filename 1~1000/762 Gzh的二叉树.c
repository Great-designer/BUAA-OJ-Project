#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char list[2048];
int n;

struct tree
{
	char data[2048];
	struct tree *lch,*rch;
};

void createtree(struct tree **b,char list[])
{
	struct tree *sta[1000],*p=NULL;
	int top=-1,k=0,j;
	char ch;
	*b=NULL;
	for(j=0; list[j]!='\0'; j++)
	{
		ch=list[j];
		switch(ch)
		{
			case '(':
				top++;
				sta[top]=p;
				k=1;
				break;
			case ',':
				k=2;
				break;
			case ')':
				top--;
				break;
			default:
				p=(struct tree*)malloc(sizeof(struct tree));
				memset(p,0,sizeof(struct tree));
				while(list[j+1]!='('&&list[j+1]!=','&&list[j+1]!=')'&&list[j+1]!='\0')
				{
					strncat(p->data,&list[j],1);
					j++;
				}
				strncat(p->data,&list[j],1);
				p->lch=NULL;
				p->rch=NULL;
				if(*b==NULL)
				{
					*b=p;
				}
				else
				{
					if(k==1)
					{
						sta[top]->lch=p;
					}
					else
					{
						sta[top]->rch=p;
					}
				}
				break;
		}
	}
}

char judge(struct tree *lch,struct tree *rch)
{
	if(lch!=NULL&&rch!=NULL)
	{
		if(strcmp(lch->data,rch->data)!=0)
		{
			return 0;
		}
		if(judge(lch->lch,rch->rch)&&judge(lch->rch,rch->lch))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(lch==NULL&&rch==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char duizhe(struct tree **head)
{
	if(*head==NULL)
	{
		return 1;
	}
	char re=judge((*head)->lch,(*head)->rch);
	return re;
}

char judge2(struct tree *lch,struct tree *rch)
{
	if(lch!=NULL&&rch!=NULL)
	{
		if(judge2(lch->lch,rch->lch)&&judge2(lch->rch,rch->rch))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(lch==NULL&&rch==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char pingyi(struct tree **head)
{
	if(*head==NULL)
	{
		return 1;
	}
	return judge2((*head)->lch,(*head)->rch);
}

void destroy(struct tree **head)
{
	if(*head==NULL)
	{
		return;
	}
	else
	{
		destroy(&((*head)->lch));
		destroy(&((*head)->rch));
		free(*head);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		struct tree *head;
		scanf("%s",list);
		char flag1=0;
		char flag2=0;
		createtree(&head,list);
		if(duizhe(&head))
		{
			flag1=1;
		}
		if(pingyi(&head))
		{
			flag2=1;
		}
		if(flag1==1&&flag2==1)
		{
			printf("GzhIsSoSoHandsome\n");
		}
		else if(flag1 == 1)
		{
			printf("GzhIsHandsome\n");
		}
		else if(flag2 == 1)
		{
			printf("GzhIsSoHandsome\n");
		}
		else
		{
			printf("GzhIsSoSoSoHandsome\n");
		}
		destroy(&head);
	}
	return 0;
}
