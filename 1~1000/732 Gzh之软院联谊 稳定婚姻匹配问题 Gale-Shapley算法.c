#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char rd_ch()
{
	char c = getchar();
	while (!isalpha(c))
	{
		c = getchar();
	}
	return c;
}

struct queue
{
	int a[1919810];
	int head, tail;
};

void init_q(struct queue *q)
{
	q->head = q->tail = 0;
}

void push(struct queue* q, int val)
{
	q->a[q->tail++] = val;
}

int front(struct queue* q)
{
	return q->a[q->head];
}

void pop(struct queue* q)
{
	q->a[q->head++] = 0;
}

char empty(struct queue* q)
{
	return q->head == q->tail;
}

struct queue single;

int wife[520], husband[520];

void engage(int male, int female)
{
	int m = husband[female];
	if (m)
	{
		wife[m] = 0;
		push(&single, m);
	}
	wife[male] = female;
	husband[female] = male;
}

char male_name[30], female_name[30];
int name_to_male[30], name_to_female[30];

int cmp(const void* p1, const void* p2)
{
	char *a=(char *)p1;
	char *b=(char *)p2;
	if(*a<*b)
	{
		return -1;
	}
	else if(*a>*b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int f_see_m_rank[520][520];
int m_prefer_f[520][520];
int nxt[520];

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		memset(male_name, 0, sizeof(male_name));
		memset(female_name, 0, sizeof(female_name));
		memset(name_to_male, 0, sizeof(name_to_male));
		memset(name_to_male, 0, sizeof(name_to_male));
		init_q(&single);
		int n;
		scanf("%d",&n);
		int i, j;
		for (i = 1; i <= n; ++i)
		{
			male_name[i] = rd_ch();
		}
		qsort(male_name + 1, n, sizeof(male_name[1]), cmp);
		for (i = 1; i <= n; ++i)
		{
			name_to_male[male_name[i] - 'a' + 1] = i;
		}
		for (i = 1; i <= n; ++i)
		{
			female_name[i] = rd_ch();
			name_to_female[female_name[i] - 'A' + 1] = i;
		}
		for (i = 1; i <= n; ++i)
		{
			int u = name_to_male[rd_ch() - 'a' + 1];
			for (j = 1; j <= n; ++j)
			{
				m_prefer_f[u][j] = name_to_female[rd_ch() - 'A' + 1];
			}
			nxt[u] = 1;
			wife[u] = 0;
			push(&single, u);
		}
		for (i = 1; i <= n; ++i)
		{
			int u = name_to_female[rd_ch() - 'A' + 1];
			for (j = 1; j <= n; ++j)
			{
				f_see_m_rank[u][name_to_male[rd_ch() - 'a' + 1]] = j;
			}
			husband[u] = 0;
		}
		while (!empty(&single))
		{
			int male = front(&single);
			pop(&single);
			int female = m_prefer_f[male][nxt[male]++];
			if (!husband[female])
			{
				engage(male, female);
			}
			else if (f_see_m_rank[female][male] < f_see_m_rank[female][husband[female]])
			{
				engage(male, female);
			}
			else
			{
				push(&single, male);
			}
		}
		while (!empty(&single))
		{
			pop(&single);
		}
		for (i = 1; i <= n; ++i)
		{
			printf("%c %c\n",male_name[i],female_name[wife[i]]);
		}
		if (t)
		{
			putchar('\n');
		}
	}
}
