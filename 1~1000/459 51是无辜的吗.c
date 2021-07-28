#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;
int c;
int la;

struct Stu
{
	int id;
	int vote;
};

int compare(const void *p1,const void *p2)
{
	struct Stu *a=(struct Stu *)p1;
	struct Stu *b=(struct Stu *)p2;
	if(a->vote>b->vote)
	{
		return -1;
	}
	else if(a->vote<b->vote)
	{
		return 1;
	}
	else if(a->id<b->id)
	{
		return -1;
	}
	else if(a->id>b->id)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Stu lalala[110];

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &c);
		memset(lalala, 0, sizeof(lalala));
		for (int i = 1; i <= n; ++i)lalala[i].id = i;
		for (int i = 2; i <= n; ++i)
		{
			scanf("%d", &la);
			if (i == c)lalala[la].vote += 3;
			else lalala[la].vote += 2;
		}
		qsort(lalala + 1,n,sizeof(struct Stu),compare);
		if (lalala[1].id == 1)puts("51 is suspected");
		else puts("51 is innocent");
	}
}
