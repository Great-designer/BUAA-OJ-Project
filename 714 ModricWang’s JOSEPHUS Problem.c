#include<stdio.h>

int n,m;

int cir(int n, int m)
{
	int p = 0;
	int i;
	for(i = 2; i <= n; i++)
	{
		p = (p + m) % i;
	}
	return p + 1;
}

int main()
{
	while(~scanf("%d%d%d", &n, &m))
	{
		printf("%d\n",cir(n, m));
	}
}
