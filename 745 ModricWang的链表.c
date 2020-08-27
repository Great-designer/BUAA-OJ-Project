#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int allpos;

struct node* CREAT(int n)
{
	struct node *p,*r,*list=NULL;
	int a = 0;
	int i;
	for(i = 0; i < n; i++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->data = a;
		p->link = NULL;
		if(list == NULL)
		{
			list = p;
		}
		else
		{
			r->link = p;
		}
		r = p;
	}
	return list;
}

int LENGTH(struct node* list)
{
	struct node* p = list;
	int n = 0;
	while(p != NULL)
	{
		n++;
		p = p->link;
	}
	return n;
}

int ISEMPTY(struct node* list)
{
	return list == NULL;
}

int FIND(struct node* list, int a)
{
	struct node* p = list;
	int fpos = 0;
	while(p != NULL && p->data != a)
	{
		p = p->link;
		fpos++;
	}
	return p == NULL ? -1 : fpos;
}

void DELETELIST(struct node* list)
{
	struct node* p = list;
	while(p != NULL)
	{
		list = p->link;
		free(p);
		p = list;
	}
}

struct node* ERASE(struct node* list, int a)
{
	struct node* p = list->link,*q = list;
	if(q->data == a)
	{
		list = list->link;
		free(q);
		return list;
	}
	allpos++;
	int found = 0;
	while(p != NULL)
	{
		if(p->data == a)
		{
			q->link = p->link;
			free(p);
			p = q->link;
			found = 1;
			break;
		}
		else
		{
			q = p;
			p = p->link;
			allpos++;
		}
	}
	if(found == 0)
	allpos = -1;
	return list;
}

void INSERT(struct node* list, int a)
{
	struct node* p = list,*r;
	while(p->link != NULL)
	{
		p = p->link;
	}
	r = (struct node*)malloc(sizeof(struct node));
	r->data = a;
	r->link = NULL;
	p->link = r;
}

int main()
{
	int N;
	scanf("%d", &N);
	struct node* head = NULL;
	while(N--)
	{
		char str[20];
		scanf("%s", str);
		if(strcmp(str, "new") == 0)
		{
			if(head != NULL)
			{
				DELETELIST(head);
				head = NULL;
			}
			printf("A new list is created\n");
		}
		else if(strcmp(str, "erase") == 0)
		{
			int a;
			scanf("%d", &a);
			if(head != NULL)
			{
				head = ERASE(head, a);
				if(allpos >= 0)
				printf("Element %d is erased at %d\n", a, allpos);
				else
				printf("404 Not Found\n");
			}
			else
			printf("404 Not Found\n");
			allpos = 0;
		}
		else if(strcmp(str, "insert") == 0)
		{
			int a;
			scanf("%d", &a);
			if(head == NULL)
			{
				head = CREAT(1);
				head->data = a;
			}
			else
			INSERT(head, a);
			printf("A new element is inserted into the list\n");
		}
		else if(strcmp(str, "find") == 0)
		{
			int a, pos = 0;
			scanf("%d", &a);
			pos = FIND(head, a);
			if(pos != -1)
			printf("Element %d is found at %d\n", a, pos);
			else
			printf("404 Not Found\n");
		}
		else if(strcmp(str, "size") == 0)
		{
			printf("Size : %d\n", LENGTH(head));
		}
		else if(strcmp(str, "delete") == 0)
		{
			if(head)
			DELETELIST(head);
			head = NULL;
			printf("It vanishes\n");
		}
		else if(strcmp(str, "list_empty") == 0)
		{
			if(ISEMPTY(head))
			printf("Empty\n");
			else
			printf("Not Empty\n");
		}
	}
}

