#include<stdio.h>
#include<string.h>

#include<algorithm>
#include<queue>

using namespace std;

int n;

void write(long long x)
{
	//if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

long long read()
{
	long long k = 0; //f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		//if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;// *f;
}

long long s_sum;
long long ans;

struct hero
{
	long long return_time;
	long long s;
	hero(long long _r = 0, long long _s = 0)
	{
		return_time = _r, s = _s;
	}
	bool operator < (const hero& o) const
	{
		//这题如何设计这里是最核心的问题
		//先拿两个人A和B来看 先走A的话等待B.s*A.return_time 先走B的话等待A.s*B.return_time
		return o.s * return_time < s * o.return_time;
	};
};

hero heros[100010];

priority_queue<hero> q;

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		ans = s_sum = 0;
		while (!q.empty())q.pop();
		for (int i = 0; i < n; ++i)
		{
			heros[i].return_time = read();
			heros[i].s = read();
		}
		sort(heros, heros + n);
		for (int i = 0; i < n; ++i)
		{
			ans += s_sum * heros[i].s;
			s_sum += heros[i].return_time;
		}
		write(ans), putchar('\n');
	}
}
