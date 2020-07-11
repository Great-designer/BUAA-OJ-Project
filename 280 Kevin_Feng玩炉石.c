#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct card
{
	char name[50];
	int cost;
};

int n,m;
int cardCnt;
char name[4];
int tmpRound,tmpCardCount;

struct card Boss[500][500];
struct card Kevin[500][500];
int topBoss;
int topKevin;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		topBoss=0;
		topKevin=0;
		while(n--)
		{
			scanf("%d",&cardCnt);
			scanf("%s",name);
			int toptop=0;
			if(name[0]=='B')
			{
				while(cardCnt--)
				{
					scanf("%s%d",Boss[topBoss][toptop].name,&Boss[topBoss][toptop].cost);
					toptop++;
				}
				topBoss++;
			}
			else
			{
				while(cardCnt--)
				{
					scanf("%s%d",Kevin[topKevin][toptop].name,&Kevin[topKevin][toptop].cost);
					toptop++;
				}
				topKevin++;
			}
		}
		while(m--)
		{
			scanf("%s%d%d",name,&tmpRound,&tmpCardCount);
			if(name[0]=='B')
			{
				printf("%s %d\n",Boss[tmpRound-1][tmpCardCount-1].name,Boss[tmpRound-1][tmpCardCount-1].cost);
			}
			else
			{
				printf("%s %d\n",Kevin[tmpRound-1][tmpCardCount-1].name,Kevin[tmpRound-1][tmpCardCount-1].cost);
			}
		}
	}
}
