#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct MyStruct
{
	char name[10];
	int a, b, c, sum;
} stu[1000],temp;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d%d%d", stu[i].name, &stu[i].a, &stu[i].b, &stu[i].c );
		stu[i].sum = stu[i].a + stu[i].b + stu[i].c;
	}
	for (int i = 0; i < n+1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(strcmp(stu[i].name,stu[j].name)>0)
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(abs(stu[i].sum-stu[j].sum)<=10&&abs(stu[i].a-stu[j].a)<=5&&abs(stu[i].b-stu[j].b)<=5&&abs(stu[i].c-stu[j].c)<=5)
			{
				printf("%s %s\n", stu[i].name, stu[j].name);
			}
		}
	}
}