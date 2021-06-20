#include<stdio.h>
#include<stdlib.h>

int FastPower(int base,int exponent,int mod)
{
	int power=1;
	for(;exponent!=0;exponent>>=1)
	{
		if(exponent&1==1)
		{
			power=power*base%mod;
		}
		base=base*base%mod;
	}
	return power;
}

char millerRabbin(int n)
{
	if (n < 3) return n == 2;
	int a = n - 1, b = 0;
	while (a % 2 == 0) a /= 2, ++b;
	int i,j;
	for(i = 1; i <=6; ++i)
	{
		int x = rand() % (n - 2) + 2, v = FastPower(x, a, n);
		if (v == 1 || v == n - 1) continue;
		for (j = 0; j < b; ++j)
		{
			v = (int)v * v % n;
			if (v == n - 1) break;
		}
		if (j >= b) return 0;
	}
	return 1;
}

int main()
{
	int e;
	scanf("%d",&e);
	if(e==4)
	{
		printf("4 = 2 + 2\n");
		return 0;
	}
	int e2=e/2;
	int i;
	for(i=3;i<=e2;i=i+2)
	{
		int temp=e-i;
		if(millerRabbin(i)&&millerRabbin(temp))
		{
			printf("%d = %d + %d\n",e,i,temp);
		}
	}
}