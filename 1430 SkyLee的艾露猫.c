#include<stdio.h>

int cat[50];

int main() 
{
	cat[1]=2;
	cat[2]=2;
	int i;
	for(i=3;i<=50;i++) 
	{
		cat[i]=cat[i-1]+cat[i-2];
		if(i>=13)
		{
			cat[i]=cat[i]-cat[i - 12];
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp>20)
		{
			printf("%d\n",cat[tmp]-cat[tmp-20]);
		}
		else
		{
			printf("%d\n",cat[tmp]);
		}
	}
	return 0;
}

