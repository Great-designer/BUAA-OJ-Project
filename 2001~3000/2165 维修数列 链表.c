#include<stdio.h>
#include<stdlib.h>

int read()
{
	int k = 0;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}
void write(int x)
{
	if (x >= 10)write(x / 10);
	putchar(x % 10 + 48);
}

struct node
{
	int number;
	struct node* next;
};

struct node* head, * tail;

void init()
{
	head = (struct node*)malloc(sizeof(struct node));
	head->number = 0;
	head->next = NULL;
	tail = head;
}
void updateTail()
{
	while (tail->next != NULL)tail = tail->next;
}
void addHead(int a)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	head->number++;
	temp->number = a;
	temp->next = head->next;
	head->next = temp;
	updateTail();
}

void addTail(int a)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	head->number++;
	temp->number = a;
	temp->next = NULL;
	tail->next = temp;
	tail = tail->next;
}

void removeTarget(int a)
{
	struct node* temp = head;
	while (temp->next != NULL)
	{
		if (temp->next->number == a)
		{
			struct node* target = temp->next;
			temp->next = temp->next->next;
			head->number--;
			free(target);
			return;
		}
		temp = temp->next;
	}
	putchar('e');
	putchar('r');
	putchar('r');
	putchar('o');
	putchar('r');
	putchar('\n');
}

void removeHead()
{
	if (head->next != NULL)
	{
		write(head->next->number);
		putchar('\n');
		struct node* target = head->next;
		head->next = head->next->next;
		head->number--;
		free(target);
	}
	else
	{
		putchar('e');
		putchar('r');
		putchar('r');
		putchar('o');
		putchar('r');
		putchar('\n');
	}
}

void printSize()
{
	write(head->number);
	putchar('\n');
}

void print()
{
	if (head->next != NULL)
	{
		struct node* temp = head->next;
		while (temp != NULL)
		{
			write(temp->number);
			putchar(' ');
			temp = temp->next;
		}
	}
	else
	{
		putchar('n');
		putchar('u');
		putchar('l');
		putchar('l');
	}
	putchar('\n');
}

int m;
int opA, opB;

void handle()
{
	opA = read();
	if (opA == 1)
	{
		opB = read();
		addTail(opB);
	}
	else if (opA == 2)
	{
		opB = read();
		addHead(opB);
	}
	else if (opA == 3)
	{
		removeHead();
	}
	else if (opA == 4)
	{
		opB = read();
		removeTarget(opB);
	}
	else
	{
		printSize();
	}
}

int main()
{
	init();
	m = read();
	while (m--)
	{
		handle();
	}
	print();
	return 0;
}
