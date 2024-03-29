#include<stdio.h>
#include<string.h>

//最大公约数 用于约分
long long gcd(long long a, long long b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

//分数 p是分子 q是分母
struct decimal
{
	long long p, q;
};

struct decimal sum(struct decimal a, struct decimal b)
{
	struct decimal ret;
	ret.p = a.p * b.q + a.q * b.p;
	ret.q = a.q * b.q;
	long long g = gcd(ret.p, ret.q);
	ret.p /= g;
	ret.q /= g;
	return ret;
}

char up[20], down[20], integer[20];

void print(struct decimal ans)
{
	if(ans.q == 1) printf("%lld\n", ans.p);//整数输出
	else  //带分数输出
	{
		long long Integer = ans.p / ans.q, Up = ans.p % ans.q;
		sprintf(up, "%lld", Up);
		sprintf(down, "%lld", ans.q);
		sprintf(integer, "%lld", Integer);
		int len_int = strlen(integer);
		int len_down = strlen(down);
		int i;
		for(i = 0; i < len_int; i++) putchar(' ');
		puts(up);
		printf("%s", integer);
		for(i = 0; i < len_down; i++) putchar('-');
		putchar('\n');
		for(i = 0; i < len_int; i++) putchar(' ');
		puts(down);
	}
	putchar('\n');
}

int n;
struct decimal a, b;
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		a.p = 0;
		a.q = 1;
		int i;
		for(i = 1; i <= n; ++i)
		{
			b.p = n;
			b.q = i;
			a = sum(a, b);
		}
		print(a);
	}
}