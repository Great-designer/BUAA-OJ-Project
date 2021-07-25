#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Task
{
	int x, y;
};

int compare(const void *p1,const void *p2)
{
	struct Task *a=(struct Task *)p1;
	struct Task *b=(struct Task *)p2;
	if(a->x>b->x)
	{
		return -1;
	}
	else if(a->x<b->x)
	{
		return 1;
	}
	else if(a->y>b->y)
	{
		return -1;
	}
	else if(a->y<b->y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int n, m;
struct Task a[100010], b[100010];
int mark[110];
long long ans;
int cnt;

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(mark, 0, sizeof(mark));
		ans = 0, cnt = 0;
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &b[i].x, &b[i].y);
		}
		qsort(a + 1,n,sizeof(struct Task),compare);
		qsort(b + 1,m,sizeof(struct Task),compare);
		int cur = 1;
		for (i = 1; i <= m; ++i)
		{
			while (cur <= n)
			{
				if (a[cur].x >= b[i].x)mark[a[cur].y]++;
				else break;
				++cur;
			}
			int k;
			for (k = b[i].y; k <= 100; ++k)//贪心:优先找xi yi最小的
			{
				if (mark[k])
				{
					mark[k]--;
					ans += 1000ll * b[i].x + 10ll * b[i].y;
					cnt++;
					break;
				}
			}
		}
		printf("%d %lld\n", cnt, ans);
	}
}
