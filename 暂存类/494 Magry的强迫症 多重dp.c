#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int a[510];
int MaxInRange[510][510], MinInRange[510][510];
char p[510][510];
int dp[510][510], f[510], nxt[510], first[510];

void write(int x)
{
	if(x < 0)
	{
		putchar('-');
		x=-x;
	}
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

struct node
{
	int id,x;
};

int compare(const void *p1,const void *p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	if(a->x>b->x)
	{
		return 1;
	}
	else if(a->x<b->x)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int findDP(int x, int y)
{
	if(dp[x][y] < 114514)return dp[x][y];
	if(x == y)
	{
		dp[x][y] = 0;
		return 0;
	}
	int num;
	struct node t[510];
	for(int i = x; i <= y; ++i)
		t[i-x+1].x=a[i],t[i-x+1].id = i;
	qsort(t+1,y-x+1,sizeof(struct node),compare);
	for(int i = x; i < y; ++i)
	{
		int mm=(MinInRange[x][i]>MinInRange[i+1][y]?MinInRange[x][i]:MinInRange[i+1][y]);
		num = 0;
		for(int j = 1; j <= y-x+1; ++j)
		{
			if(t[j].x == mm)break;
			if(t[j].x<mm)++num;
		}
		num = y-x+1-num;
		dp[x][y]=dp[x][y]<(findDP(x, i)+findDP(i+1, y)+num)?dp[x][y]:(findDP(x, i)+findDP(i+1, y)+num);
	}
	return dp[x][y];
}

int main()
{
	while(~scanf("%d",&n))
	{
		memset(first, 0, sizeof(first));
		memset(p, 0, sizeof(p));
		for(int i = 1; i <= n; ++i)
		{
			a[i] = read();
			nxt[i] = first[a[i]];
			first[a[i]] = i;//构建链表
		}
		memset(MinInRange, 0x3f, sizeof(MinInRange));
		for(int i = 1; i <= n; ++i)
			MaxInRange[i][i] = MinInRange[i][i] = a[i], p[i][i] = 1;
		//区间dp模板
		for(int i = n; i >= 1; --i)
		{
			for(int j = i + 1; j <= n; ++j)
			{
				MaxInRange[i][j]=MaxInRange[i][j-1]>a[j]?MaxInRange[i][j-1]:a[j];
				MinInRange[i][j]=MinInRange[i][j-1]<a[j]?MinInRange[i][j-1]:a[j];
				if(p[i][j-1]&&nxt[j]<i)p[i][j] = 1;
			}
		}
		memset(dp,0x3f,sizeof(dp));
		memset(f, 0x3f, sizeof(f));
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(MaxInRange[i][j] == j - i + 1 && p[i][j])
					findDP(i,j);
			}
		}
		f[0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < i; ++j)
				if(MaxInRange[j+1][i]==i-j&&p[j+1][i])
					f[i]=f[i]<(f[j]+dp[j+1][i])?f[i]:(f[j]+dp[j+1][i]);
		if(f[n]>114514)
			puts("There is no way to meet Magry's requirements.");
		else
			write(f[n]),putchar('\n');
	}
}
