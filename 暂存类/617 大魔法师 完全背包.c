#include<stdio.h>
#include<string.h>

int n, V;
int f[1010];
char input[1010];

void buildDP_FullPack(int cost, int value)
{
	for (int v = cost; v <= V; ++v)
	{
		f[v]=f[v]>(f[v - cost] + value)?f[v]:(f[v - cost] + value);
	}
}

int check(int len)
{
	int ret = 0;
	for (int i = 0; i < len; ++i)
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
			ret++;
	return ret;
}

int main()
{
	while (scanf("%d%d", &n, &V) != EOF)
	{
		memset(f, 0, sizeof(f));
		while (n--)
		{
			scanf("%s", input);
			int len = strlen(input);
			buildDP_FullPack(len, check(len));
		}
		printf("%d\n", f[V]);
	}
}
