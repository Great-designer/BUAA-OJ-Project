#include<stdio.h>
#include<stdlib.h>

int n,m;

struct Student
{
	char name[100];
	int num;
	double grade;
	int position;
};

struct Student stu[10010];

int num[10010];

int cmp(const void*p1,const void*p2)
{
	struct Student *a=(struct Student*)p1;
	struct Student *b=(struct Student*)p2;
	if (a->grade==b->grade)
	{
		return (a->num>b->num);
	}
	return (a->grade<b->grade);
}

int cmp2(const void*p1,const void*p2)
{
	struct Student *a=(struct Student*)p1;
	struct Student *b=(struct Student*)p2;
	return a->num>b->num;
}

int compare(const void *p1,const void *p2)
{
	int *a=(int*)p1;
	int *b=(int*)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
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
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%s%d%lf",stu[i].name,&stu[i].num,&stu[i].grade);
		}
		qsort(stu,n,sizeof(struct Student),cmp);
		for(i=0;i<n;i++)
		{
			stu[i].position=i+1;
		}
		qsort(stu,n,sizeof(struct Student),cmp2);
		for(i=0;i<n;i++)
		{
			num[i]=stu[i].num;
		}
		scanf("%d",&m);
		int search1;
		for(i=0;i<m;i++)
		{
			scanf("%d",&search1);
			int *pos=bsearch(&search1,num,n,sizeof(int),compare);
			if(pos!=NULL)
			{
				printf("%s %d %.2lf %d\n",stu[pos-num].name,stu[pos-num].num,stu[pos-num].grade,stu[pos-num].position);
			}
			else
			{
				printf("Only god knows where he is.\n");
			}
		}
	}
}
