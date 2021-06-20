#include<stdio.h>
#include<stdlib.h>

typedef struct _Dish
{
	unsigned long long Index;
	long long Deli;
	unsigned long long Mass;
	unsigned long long Left;
} Dish;

int Compare(const void* a,const void* b)
{
	Dish A= *(Dish*)a;
	Dish B= *(Dish*)b;
	long long AC=A.Deli*(long long)B.Mass;
	long long BC=B.Deli*(long long)A.Mass;
	if(BC-AC==0) //int 和 short的积不会超过long long
	{
		return A.Index-B.Index;
	}
	return BC-AC;

}

Dish Sec[200000]= {};
int main()
{

	unsigned long long Storage=0;
	unsigned long long Delicious=0;
	int DataNum=0;
	scanf("%llu",&Storage);
	scanf("%d",&DataNum);
	for (int i = 0; i < DataNum; i++)
	{
		unsigned long long Index=0;
		long long DishDelicious=0;
		unsigned long long DishLeft=0;
		unsigned long long DishMass=0;
		scanf("%llu %lld %llu %llu",&Index,&DishDelicious,&DishMass,&DishLeft);
		Sec[i].Index=Index;
		Sec[i].Mass=DishMass;
		Sec[i].Deli=DishDelicious;
		Sec[i].Left=DishLeft;
	}

	qsort(Sec,DataNum,sizeof(Dish),Compare);

	for(int i=0; i<DataNum; i++)
	{
		if (Storage>=Sec[i].Mass && Sec[i].Deli>0)
		{

			unsigned long long Need=Storage/Sec[i].Mass;
			if(Need>Sec[i].Left)
			{
				Need=Sec[i].Left;
			}
			Storage-=Need*Sec[i].Mass;
			Delicious+=Need*Sec[i].Deli;
			printf("%llu %llu\n",Sec[i].Index,Need);
		}
	}
	printf("%llu",Delicious);
	return 0;
}