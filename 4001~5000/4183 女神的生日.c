#include<stdio.h>
#include<stdlib.h>

struct person
{
	char name[25];
	int year;
	int month;
	int day;
	int number;
};

struct person A[120];

int compare(const void *p1,const void *p2)
{
	struct person *a=(struct person*)p1;
	struct person *b=(struct person*)p2;
	if(a->year>b->year)
	{
		return 1;
	}
	else if(a->year<b->year)
	{
		return -1;
	}
	else if(a->month>b->month)
	{
		return 1;
	}
	else if(a->month<b->month)
	{
		return -1;
	}
	else if(a->day>b->day)
	{
		return 1;
	}
	else if(a->day<b->day)
	{
		return -1;
	}
	else if(a->number<b->number)
	{
		return 1;
	}
	else if(a->number>b->number)
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
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%d",&A[i].name,&A[i].year,&A[i].month,&A[i].day);
		A[i].number=i;
	}
	qsort(A,n,sizeof(struct person),compare);
	for(i=0;i<n;i++)
	{
		printf("%s\n",A[i].name);
	}
}