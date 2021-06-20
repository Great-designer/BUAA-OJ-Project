#include<stdio.h>
//为本题量身定做的结构体，用于存储每条人员数据
struct UnivPerson
{
	char name[10];
	char num_char[10];
	int num;
	char sex;
	char job;
	union
	{
		int class0;
		char position[10];
	} category;
};
//适用于结构体排序的cmpfunc函数，学习由结构体指针间接访问元素的运算符->
int cmpfunc (const void * a, const void * b)
{
	struct UnivPerson *p1 = (struct UnivPerson *)a;
	struct UnivPerson *p2 = (struct UnivPerson *)b;
	return (p1->num)-(p2->num);
	//从小到大 小于零不换
}

int main()
{
	struct UnivPerson Person[105];
	int i=0,n;
	char query_job;
	int query_class;
	char query_position[10];
	scanf("%d",&n);
	while(getchar()!='\n');
	for(i=0; i<n; i++)
	{
		scanf("%s %s %c %c",Person[i].name,Person[i].num_char,&Person[i].sex,&Person[i].job);
		//巧用sscanf函数，从字符串中解析输入
		sscanf(Person[i].num_char,"%d",&Person[i].num);
		if(Person[i].job=='S')
		{
			scanf("%d",&Person[i].category.class0);
		}
		else
		{
			scanf("%s",Person[i].category.position);
		}
	}
	while(getchar()!='\n');
	qsort(Person,n,sizeof(Person[0]),cmpfunc);
	scanf("%c",&query_job);
	if(query_job=='S')
	{
		scanf("%d",&query_class);
		for(i=0; i<n; i++)
		{
			if(Person[i].job=='S')
			{
				if(Person[i].category.class0==query_class)
				{
					printf("%-8s %-8s %c %c %d\n",Person[i].name,Person[i].num_char,Person[i].sex,Person[i].job,Person[i].category.class0);
				}
			}
		}
	}
	else
	{
		scanf("%s",query_position);
		for(i=0; i<n; i++)
		{
			if(Person[i].job=='T')
			{
				if(strcmp(Person[i].category.position,query_position)==0)
				{
					printf("%-8s %-8s %c %c %s\n",Person[i].name,Person[i].num_char,Person[i].sex,Person[i].job,Person[i].category.position);
				}
			}
		}
	}

	return 0;
}