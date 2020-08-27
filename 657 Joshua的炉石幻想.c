#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int x, y, z;
int m, n;

struct Hero
{
	int cost;
	int atk;
};

int cmpCost(const void*p1,const void*p2)
{
	struct Hero*a=(struct Hero*)p1;
	struct Hero*b=(struct Hero*)p2;
	return a->cost>b->cost;
}

int cmpAtk(const void*p1,const void*p2)
{
	struct Hero*a=(struct Hero*)p1;
	struct Hero*b=(struct Hero*)p2;
	return a->atk<b->atk;
}

struct Hero Deck[15];
int minCostAt[15];
int maxAtkAt[15];

int enemyHP[15];
int enemyHPSum;

void handleCostATK()
{
	qsort(Deck + 1,y,sizeof(struct Hero),cmpCost);
	int i; 
	for(i = 1; i <= y; ++i)
	{
		minCostAt[i] = minCostAt[i - 1] + Deck[i].cost;
	}
	qsort(Deck + 1,y,sizeof(struct Hero),cmpAtk);
	for(i = 1; i <= y; ++i)
	{
		maxAtkAt[i] = maxAtkAt[i - 1] + Deck[i].atk;
	}
	qsort(Deck + 1,y,sizeof(struct Hero),cmpCost);
}

int maxDamage;
int dfsSizeofDeck;

char occur[15];
char occur_enemy[15];
struct Hero Arrange[15];
int EnemyOrder[15];
struct Hero simulate_Hero[15];
int simulate_Enemy[15];

char isOK()
{
	int Cost = 0, ATK = 0;
	int i;
	for(i = 1; i <= dfsSizeofDeck; ++i)
	{
		Cost += Arrange[i].cost, ATK += Arrange[i].atk;
	}
	return Cost <= x && ATK > enemyHPSum + maxDamage;
}

int calDamage()
{
	int ret = 0;
	memset(simulate_Hero, 0, sizeof(simulate_Hero));
	memset(simulate_Enemy, 0, sizeof(simulate_Enemy));
	int i;
	for(i = 1; i <= dfsSizeofDeck; ++i)
	{
		simulate_Hero[i] = Arrange[i];
	}
	for(i = 1; i <= z; ++i)
	{
		simulate_Enemy[i] = EnemyOrder[i];
	}
	int heroIndex = 1, enemyIndex = 1;
	while(heroIndex <= dfsSizeofDeck)
	{
		if(enemyIndex <= z)
		{
			if(simulate_Hero[heroIndex].atk < simulate_Enemy[enemyIndex])
			{
				simulate_Enemy[enemyIndex] -= simulate_Hero[heroIndex].atk;
				heroIndex++;
			}
			else
			{
				heroIndex++, enemyIndex++;
			}
		}
		else
		{
			ret += simulate_Hero[heroIndex].atk;
			heroIndex++;
		}
	}
	return ret;
}

void dfs_Enemy(int i)
{
	if(i > z)
	{
		int cur = calDamage();
		if(maxDamage < cur)
		{
			maxDamage = cur;
		}
		return;
	}
	int j;
	for(j = 1; j <= z; ++j)
	{
		if(!occur_enemy[j])
		{
			EnemyOrder[i] = enemyHP[j];
			occur_enemy[j] = 1;
			dfs_Enemy(i + 1);
			occur_enemy[j] = 0;
			EnemyOrder[i] = 0;
		}
	}
}

void dfs_Hero(int i)
{
	if(i > dfsSizeofDeck)
	{
		if(isOK())
		{
			dfs_Enemy(1);
		}
		return;
	}
	int j;
	for(j = 1; j <= y; ++j)
	{
		if (!occur[j])
		{
			Arrange[i] = Deck[j];
			occur[j] = 1;
			dfs_Hero(i + 1);
			occur[j] = 0;
			Arrange[i].atk = 0, Arrange[i].cost = 0;
		}
	}
}

int main()
{
	scanf("%d%d%d", &x, &y, &z);
	int i;
	for(i = 1; i <= y; ++i)
	{
		scanf("%d%d", &Deck[i].atk, &Deck[i].cost);
	}
	for(i = 1; i <= z; ++i)
	{
		scanf("%d", &enemyHP[i]);
		enemyHPSum += enemyHP[i];
	}
	handleCostATK();
	int lim = 7;
	if(lim > x)
	{
		lim = x;
	}
	for(dfsSizeofDeck = z + 1; dfsSizeofDeck <= lim; ++dfsSizeofDeck)
	{
		dfs_Hero(1);
	}
	printf("%d\n", maxDamage);
}
