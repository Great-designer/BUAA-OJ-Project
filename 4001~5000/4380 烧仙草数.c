#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

int PrimeTab[50000] = {2, 3, 5, 7};
int PrimeIndex = 4;

int GetPrimeTab(int *PrimeTable, int *TabIndex, int Max)
{
	int i = 0;
	int j = 0;
	for (i = 8; i <= Max; i++)

	{

		int IsPrime = 1;
		for (j = 0; PrimeTab[j] * PrimeTab[j] <= i; j++)

		{
			if (i % PrimeTab[j] == 0)

			{
				IsPrime = 0;
				break;
			}
		}
		if (IsPrime)

		{
			PrimeTab[*TabIndex] = i;
			(*TabIndex) += 1;
		}
	}
}

int Check(int *PrimeTable, int TabIndex, int a)
{
	int Sum = 0;
	int b = 0;
	int a1 = a;
	int i = 0;
	while (a1)
	{
		b += a1 % 10;
		a1 /= 10;
	}
	for (i = 0; i < TabIndex; i++)
	{
		if (a % PrimeTable[i] == 0)
		{
			Sum += PrimeTable[i];
			if(Sum>b)
			{
				return 0;
			}
		}
	}
	return Sum == b;
}

int main()
{
	int Input = 0;
	int i = 2;
	GetPrimeTab(PrimeTab, &PrimeIndex, 50000);
	scanf("%d", &Input);
	for (i = 2; i < Input; i++)
	{
		if (Check(PrimeTab, PrimeIndex, i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}