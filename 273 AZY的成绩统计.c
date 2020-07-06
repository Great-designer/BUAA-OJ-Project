#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Info
{
	char name[20];
	int studentId;
	int average;
	int gpa;
};

int compare(const void*p1,const void*p2)
{
	struct Info*o=(struct Info*)p1;
	struct Info*a=(struct Info*)p2;
	if(a->average!=o->average)
	{
		return a->average>o->average;
	}
	else
	{
		if(a->gpa!=o->gpa)
		{
			return a->gpa>o->gpa;
		}
		else
		{
			return a->studentId<o->studentId;
		}
	}
}

struct Info info[1010];
int n;

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%s%d%d%d",info[i].name,&info[i].studentId,&info[i].average,&info[i].gpa);
		}
		qsort(info,n,sizeof(struct Info),compare);
		for(i=0;i<n;++i)
		{
			printf("%s %d %d %d\n",info[i].name,info[i].studentId,info[i].average,info[i].gpa);
		}
	}
}
