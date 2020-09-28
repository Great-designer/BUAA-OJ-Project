#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

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
			int *pos=lower_bound(num,num+n,search1);
			if (num[pos-num]==search1)
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
