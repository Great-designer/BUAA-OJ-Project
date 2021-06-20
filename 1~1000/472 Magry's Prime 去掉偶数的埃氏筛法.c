#include<stdio.h>
#include<string.h>
//100w的数据中，偶数可以全部不考虑，如果是2的话，直接输出yes
//于是乎a[i]表示的是2*i+1的数是否是质数
//1不是质数，所以直接赋值false
//3是，那么9，15等一定不是 1 4 7 10等都可以被去掉了，即直接加k都设成false即可
char isPrime[25000010];
int countPrime[25000010];

void initial()
{
	memset(isPrime, 1, sizeof(isPrime));
	int i;
	for (i = 1; i < 25000010; ++i)
	{
		if (isPrime[i])
		{
			int k = (i << 1) + 1;
			int j;
			for (j = i + k; j < 25000010; j += k)
			{
				isPrime[j] = 0;
			}
		}
	}
	countPrime[1] = 2;
	for (i = 2; i < 25000010; ++i)//4和3的质数个数一样，所以直接无脑找n/2-1即可
	{
		countPrime[i] = countPrime[i - 1] + isPrime[i];
	}
}

int main()
{
	initial();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 1)
		{
			printf("0\n");
		}
		else if (n == 2)
		{
			printf("1\n");
		}
		else
		{
			printf("%d\n", countPrime[(n - 1) >> 1]);
		}
	}
}