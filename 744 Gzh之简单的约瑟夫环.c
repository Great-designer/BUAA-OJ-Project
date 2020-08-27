#include<stdio.h>

char alive[1010];
int n, k, m;
int realm;
int cur;
int l;

int cir(int n, int m)
{
	int p = 0;
	int i;
	for(i = 2; i <= n; i++)
	{
		p = (p + m) % i;
	}
	return (p + l) % n + 1;
}

int main()
{
	while(~scanf("%d%d%d", &n, &k, &m))
	{
		k--;
		k %= n;
		l = k;
		printf("%d\n",cir(n, m));
	}
}
