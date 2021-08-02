#include<stdio.h>

struct list
{
	char name[101];
	int age;
	char dst[101];
	int rush;
};

struct list rush_list[51];

int main()
{
	char lj[5];
	int n;
	scanf("%d", &n);
	gets(lj);
	int i;
	for (i = 0; i < n; ++i)
	{
		gets(rush_list[i].name);
		scanf("%d", &rush_list[i].age);
		gets(lj);
		gets(rush_list[i].dst);
		scanf("%d", &rush_list[i].rush);
		gets(lj);
		if (i != n - 1)
		{
			gets(lj);
		}
	}
	for (i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < n - i - 1; j++)
		{
			if (rush_list[j].rush < rush_list[j + 1].rush)
			{
				struct list temp;
				temp = rush_list[j];
				rush_list[j] = rush_list[j + 1];
				rush_list[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; ++i)
	{
		printf("%s\n", rush_list[i].name);
		printf("%d\n", rush_list[i].age);
		printf("%s\n", rush_list[i].dst);
		printf("%d\n", rush_list[i].rush);
		if (i != n - 1)
		{
			printf("\n");
		}
	}
}