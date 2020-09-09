#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include<vector>

using namespace std;

/*****************************************************************
首先思路在于随机化的概率算法
这个想不出来就没辙

如果一个格子没有加入其它糖果
那么加入的糖果编号之和一定是目标糖果编号的倍数
（反之则不一定）

对某个编号的糖果随机某一个比较大的数
那大概率上不会冲突（1+3=2+2这种就不行）

如果对所有糖果序号都进行多次随机，进行上述必要性判断
就可以认为:
在概率上每个存在非接受序号糖果的格子，都存在一组随机数
使得各自的和并非其接受的对应随机数的倍数

也就是说这题完全拼的是概率
大随机数的出错概率很低，多试几次就几乎为0

剩下的二维前缀和就不太多说了就是O(1)查询，子区间求和等要素

[x1,y1][x2,y2]矩形整体加一个数v可以表示为
在某个a数组的[x1,y1][x2+1,y2+1]处加v
然后[x1,y2+1][x2+1][y1]处-v，然后a数组对应前缀和就可求

dp[i][j]=dp[i-1][j]+dp[i][j-1]+a[i][j]
某个格子的[x,y]值则可以由
dp[x][y]+dp[x-1][y-1]-dp[x][y-1]-dp[x-1][y]表示(子矩阵的和值)
*****************************************************************/

long long map[1000010];
vector<long long> counter[1000010],a[1000010];

void write(long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

long long read()
{
	long long k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

long long n,m,t,tmpint;
long long x1,y1,x2,y2,v;

int main()
{
	n = read();
	m = read();
	t = read();
	int i;
	for(i = 0; i <= n + 1; ++i)
	{
		a[i].resize(m + 2);
		counter[i].resize(m + 2);
	}
	srand(time(0));
	for(i = n * m; i > 0; --i)
	{
		map[i] = (rand() * 1ll << 24ll) ^ (rand() << 8ll) ^ (rand() % (1ll << 8));
	}
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 1; j <= m; ++j)
		{
			tmpint = read();
			a[i][j] = map[tmpint];
		}
	}
	while (t--)
	{
		x1 = read();
		y1 = read();
		x2 = read();
		y2 = read();
		v = read();
		++x2;
		++y2;
		long long w = map[v];
		counter[x1][y1] += w;
		counter[x1][y2] -= w;
		counter[x2][y1] -= w;
		counter[x2][y2] += w;
	}
	long long res = 0;
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 1; j <= m; ++j)
		{
			counter[i][j] += counter[i - 1][j] + counter[i][j - 1] - counter[i - 1][j - 1];
			res += (counter[i][j] % a[i][j]) != 0;
		}
	}
	write(res);
}
