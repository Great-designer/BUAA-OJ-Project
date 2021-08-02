#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ta
{
	char value[105];
	struct ta *next;
};

int index;
char optable, s[105];

struct ta *ahead, *aend, *bhead, *bend;

int readOperation();
void init();
void deleteOne();
void insert();
void move();
void output(struct ta *head, struct ta *end);

int main()
{

	init();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	optable = 'a';
	int i;
	for (i = 0; i < n; i++)
	{
		index = i;
		scanf("%s", s);
		insert();
	}
	optable = 'b';
	for (i = 0; i < m; i++)
	{
		index = i;
		scanf("%s", s);
		insert();
	}
	for (i = 0; i < k; i++)
	{
		int op = readOperation();
		switch (op)
		{
			case 1:
				insert();
				break;
			case 2:
				deleteOne();
				break;
			case 3:
				move();
				break;
			case 0:
				goto out;
		}
	}
out:
	output(ahead, aend);
	printf("\n");
	output(bhead, bend);
}

void output(struct ta *head, struct ta *end)
{
	struct ta *p = head;
	int cnt = 0;
	for (; p != end; p = p->next, cnt++)
	{
		printf("%s\n", p->value);
	}
	if (cnt == 0)
	{
		printf("Empty!\n");
	}
}

void init()
{
	// 初始化链表
	ahead = (struct ta *)malloc(sizeof(struct ta));
	aend = ahead;
	ahead->next = NULL;
	bhead = (struct ta *)malloc(sizeof(struct ta));
	bend = bhead;
	bhead->next = NULL;
}

void deleteOne()
{
	struct ta *head, *last;
	optable == 'a' ? (head = ahead) : (head = bhead);
	if (index == 0)
	{
		optable == 'a' ? (ahead = head->next) : (bhead = head->next);
		free(head);
		return;
	}
	while (index--)
	{
		last = head;
		head = head->next;
	}
	last->next = head->next, free(head);
}

void insert()
{
	struct ta *p = (struct ta *)malloc(sizeof(struct ta)), *head, *last;
	strcpy(p->value, s);
	optable == 'a' ? (head = ahead) : (head = bhead);
	if (index == 0)
	{
		p->next = head;
		optable == 'a' ? (ahead = p) : (bhead = p);
		return;
	}
	while (index--)
	{
		last = head;
		head = head->next;
	}
	last->next = p, p->next = head;
}

void move()
{
	struct ta *head, *last, *end, *p, *otherhead, *otherend;
	optable == 'a' ? (head = ahead, end = aend) : (head = bhead, end = bend);
	optable == 'a' ? (otherhead = bhead, otherend = bend) : (otherhead = ahead, otherend = aend);
	if (index == 0)
	{
		optable == 'a' ? (ahead = aend) : (bhead = bend);
		p = head;
		while (1)
		{
			// 换尾
			if (p->next == end)
			{
				p->next = otherend;
				break;
			}
			p = p->next;
		}
		while (otherhead->next != otherend)
		{
			otherhead = otherhead->next;
		}
		otherhead->next = head;
		return;
	}
	while (index--)
	{
		last = head;
		head = head->next;
	}
	last->next = end;
	p = head;
	while (1)
	{
		// 换尾
		if (p->next == end)
		{
			p->next = otherend;
			break;
		}
		p = p->next;
	}
	if (otherhead == otherend)
	{
		optable == 'a' ? (bhead = head) : (ahead = head);
		return;
	}
	while (otherhead->next != otherend)
	{
		otherhead = otherhead->next;
	}
	otherhead->next = head;
}

int readOperation()
{
	int op;
	if (~scanf("%d %c %d", &op, &optable, &index))
	{
		if (op == 1)
		{
			scanf("%s", s);
		}
		return op;
	}
	else
	{
		return 0;
	}
}

