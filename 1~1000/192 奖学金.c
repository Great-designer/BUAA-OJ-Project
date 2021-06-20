#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Sheet
{
	int studentId;
	int chi, mat, eng;
	int sum;
};

struct Sheet students[1010];

int compare(const void *p1,const void *p2)
{
	struct Sheet *a=(struct Sheet*)p1;
	struct Sheet *b=(struct Sheet*)p2;
	if(a->sum>b->sum)
	{
		return -1;
	}
	else if(a->sum<b->sum)
	{
		return 1;
	}
	else if(a->chi>b->chi)
	{
		return -1;
	}
	else if(a->chi<b->chi)
	{
		return 1;
	}
	else if(a->studentId>b->studentId)
	{
		return 1;
	}
	else if(a->studentId<b->studentId)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(students, 0, sizeof(students));
		int i;
		for(i = 1; i <= n; ++i)
		{
			students[i].studentId = i;
			scanf("%d%d%d", &students[i].chi, &students[i].mat, &students[i].eng);
			students[i].sum = students[i].chi + students[i].mat + students[i].eng;
		}
		qsort(students + 1,n,sizeof(struct Sheet),compare);
		for(i = 1; i <= 5; ++i)
		{
			printf("%d %d\n", students[i].studentId, students[i].sum);
		}
	}
}