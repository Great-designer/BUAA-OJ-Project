#include<stdio.h>
#include<stdlib.h>

int n;
int pos[10010];

struct student
{
	double height;
	int number;
};

int compare(const void*p1,const void*p2)
{
	struct student *a=(struct student*)p1;
	struct student *b=(struct student*)p2;
	return a->height>b->height;
}


struct student male[10010],female[10010];

int main()
{
	while(~scanf("%d", &n))
	{
		int i;
		for(i = 1; i <= n; ++i)
		{
			scanf("%lf%lf", &female[i].height, &male[i].height);
			female[i].number = i, male[i].number = i;
		}
		qsort(female + 1,n,sizeof(struct student),compare);
		qsort(male + 1,n,sizeof(struct student),compare);
		for(i = 1; i <= n; ++i)
		{
			pos[male[i].number] = i;
		}
		for(i = 1; i <= n; ++i)
		{
			printf("%d ", pos[female[i].number]);
		}
		puts("");
		for(i = 1; i <= n; ++i)
		{
			pos[female[i].number] = i;
		}
		for(i = 1; i <= n; ++i)
		{
			printf("%d ", pos[male[i].number]);
		}
		puts("");
	}
}
