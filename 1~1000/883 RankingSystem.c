#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Info
{
	char name[15];
	int score;
};

struct Info ScoreSheet[1010];
char needSort;

int cmp(const void *p1,const void *p2)
{
	struct Info *a=(struct Info *)p1;
	struct Info *b=(struct Info *)p2;
	if (a->score>b->score)
	{
		return -1;
	}
	else if(a->score<b->score)
	{
		return 1;
	}
	else
	{
		return strcmp(a->name, b->name);
	}
}

int size;
char temp[15];
int temp_score;

char locate(char lala[],int lalala)
{
	for (int i = 0; i < size; ++i)
	{
		if (!strcmp(lala, ScoreSheet[i].name))
		{
			ScoreSheet[i].score = lalala;
			return 1;
		}
	}
	return 0;
}

void add(char lala[], int lalala)
{
	strcpy(ScoreSheet[size].name, lala);
	ScoreSheet[size++].score = lalala;
}

int q;
int op;

int main()
{
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%s%d", temp, &temp_score);
			if (!locate(temp, temp_score))
			{
				add(temp, temp_score);
			}
			needSort = 1;
		}
		else
		{
			scanf("%d", &temp_score);
			if(needSort)
			{
				qsort(ScoreSheet,size,sizeof(struct Info),cmp);
			}
			printf("%s %d\n", ScoreSheet[temp_score - 1].name, ScoreSheet[temp_score - 1].score);
			needSort = 0;
		}
	}
}
