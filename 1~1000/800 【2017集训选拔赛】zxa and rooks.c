#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct interval
{
	int xl, xr, yl, yr;
	int x, y;
	int num;
} a[100005];

int cmp_order(const void *p1, const void *p2)
{
	struct interval *a = (struct interval *)p1, *b = (struct interval *)p2;
	if (a->num < b->num)
		return -1;
	else if (a->num > b->num)
		return 1;
	else
		return 0;
}
//以r为关键字进行排序
int cmp_x(const void *p1, const void *p2)
{
	struct interval *a = (struct interval *)p1, *b = (struct interval *)p2;
	if (a->xr < b->xr)
		return -1;
	else if (a->xr > b->xr)
		return 1;
	else
		return 0;
}

int cmp_y(const void *p1, const void *p2)
{
	struct interval *a = (struct interval *)p1, *b = (struct interval *)p2;
	if (a->yr < b->yr)
		return -1;
	else if (a->yr > b->yr)
		return 1;
	else
		return 0;
}

char have[100005];

void solve(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d%d", &a[i].xl, &a[i].xr, &a[i].yl, &a[i].yr);
		a[i].num = i; //在读入时记录标号，方便打乱之后排回来
	}

	memset(have, 0, sizeof(have)); //多组数据，注意初始化
	qsort(a + 1, n, sizeof(struct interval), cmp_x);
	for (int i = 1; i <= n; ++i)
	{
		int x = a[i].xl;
		while (have[x] && x <= a[i].xr) //找到第一个没有被选过的点
			x++;
		if (x > a[i].xr)
		{
			puts("IMPOSSIBLE");
			return;
		}
		else
		{
			a[i].x = x;
			have[x] = 1;
		}
	}
	memset(have, 0, sizeof(have));
	qsort(a + 1, n, sizeof(struct interval), cmp_y);
	for (int i = 1; i <= n; ++i)
	{
		int y = a[i].yl;
		while (have[y] && y <= a[i].yr)
			y++;
		if (y > a[i].yr)
		{
			puts("IMPOSSIBLE");
			return;
		}
		a[i].y = y;
		have[y] = 1;
	}

	qsort(a + 1, n, sizeof(struct interval), cmp_order); //排回来
	for (int i = 1; i <= n; ++i)
		printf("%d %d\n", a[i].x, a[i].y);
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
		scanf("%d", &n), solve(n);
}