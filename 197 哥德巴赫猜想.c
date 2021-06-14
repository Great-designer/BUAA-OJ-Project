#include<stdio.h>
#include<string.h>

char isPrime[500010];

void initial()
{
	memset(isPrime, 1, sizeof(isPrime));
	int i;
	for(i = 1; i < 500010; ++i)
	{
		if (isPrime[i])
		{
			int k = (i << 1) + 1;
			int j;
			for(j = i + k; j < 500010; j += k)
			{
				isPrime[j]=0;
			}
		}
	}
}

int main()
{
	int n;
	initial();
	while (scanf("%d", &n) != EOF)
	{
		int i;
		for(i = 1; i < 500010; ++i)
		{
			if (isPrime[i] && isPrime[(n - (i << 1) - 2) >> 1])
			{
				printf("%d = %d + %d\n", n, (i << 1) + 1, n - (i << 1) - 1);
				break;
			}
		}
	}
}