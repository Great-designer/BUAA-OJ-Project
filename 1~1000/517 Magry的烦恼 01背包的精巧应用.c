#include<stdio.h>
#include<string.h>

int f[210];
int V;
int n;
int t[210], w[210];

void buildDP_01Pack(int cost, int value)
{
	for (int v = V; v >= cost; --v)
	{
		f[v]=f[v]>(f[v - cost] + value)?f[v]:(f[v - cost] + value);
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(f, 0, sizeof(f));
		V = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", t + i, w + i), V += t[i];
		for (int i = 1; i <= n; ++i)
			buildDP_01Pack(t[i] + w[i], t[i]);
		printf("%d\n", V - f[V]);
	}
}
