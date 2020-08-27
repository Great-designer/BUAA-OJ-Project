#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[40],name[80];
int t,n,x;
int MaleRank[40][40];
int FemaleRank[40][40];
int Next[40];
int ans[2][40];

int single[1000010];
int front,rear;

int compare(const void*p1,const void*p2)
{
	char *a=(char*)p1;
	char *b=(char*)p2;
	return (*a)>(*b)?1:-1;
}

void init()
{
	memset(str, 0, sizeof(str));
	memset(name, 0, sizeof(name));
	memset(MaleRank, 0, sizeof(MaleRank));
}

void Paired(int x, int y)
{
	int m = ans[0][y];
	if(m)
	{
		ans[1][m] = 0;
		single[rear]=m;
		rear++;
	}
	ans[1][x] = y, ans[0][y] = x;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int i; 
		for(i = 1; i <= (n << 1); ++i)
		{
			scanf("%s", str);
			name[i] = str[0];
		}
		qsort(name+1,n,sizeof(char),compare);
		for(i = 1; i <= n; ++i)
		{
			scanf("%s", str);
			int j;
			for(j = 2; j < n + 2; ++j)
			{
				FemaleRank[str[0] - 'a' + 1][j - 1] =str[j] - 'A' + 1;
			}
			Next[str[0] - 'a' + 1] = 1, ans[1][str[0] - 'a' + 1] = 0;
			single[rear]=str[0]-'a'+1;
			rear++;
		}
		for(i = 1; i <= n; ++i)
		{
			scanf("%s", str);
			int j;
			for(j = 2; j < n + 2; ++j)
			{
				MaleRank[str[0] - 'A' + 1][str[j] -'a' + 1] = j - 1;
			}
			ans[0][str[0] - 'A' + 1] = 0;
		}
		while(front!=rear)
		{
			int u =single[front];
			front++;
			int v = FemaleRank[u][Next[u]++];
			if (!ans[0][v])Paired(u, v);
			else if (MaleRank[v][u] < MaleRank[v][ans[0][v]])Paired(u, v);
			else
			{
				single[rear]=u;
				rear++;
			}
		}
		for(i = 1; i <= n; ++i)
		{
			printf("%c %c\n", name[i], ans[1][name[i] - 'a' + 1] + 'A' - 1);
		}
		putchar('\n');
	}
}
