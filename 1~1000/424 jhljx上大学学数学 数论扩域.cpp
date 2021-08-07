#include<stdio.h>

int add(int a, int b)
{
	return a + b >= 100000 ? a + b - 100000 : a + b;
}

int sub(int a, int b)
{
	return a < b ? a - b + 100000 : a - b;
}

int mul(int a, int b)
{
	return (1ll * a * b) % 100000;
}

struct complex
{
	int a, b;
	complex(int _a = 0, int _b = 0) : a(_a), b(_b) {}
	complex operator+(const complex &o) const
	{
		return complex(add(a, o.a), add(b, o.b));
	}
	complex operator-(const complex &o) const
	{
		return complex(sub(a, o.a), sub(b, o.b));
	}
	complex operator-(const int &o) const
	{
		return complex(sub(a, o), b);
	}
	complex operator*(const complex &o) const
	{
		return complex(add(mul(a, o.a), mul(mul(5, b), o.b)), add(mul(a, o.b), mul(o.a, b)));
	}
	complex operator*(const int &o) const
	{
		return complex(mul(a, o), mul(b, o));
	}
	complex operator^(long long o) const
	{
		complex ret = complex(1, 0), tmp = complex(add(0, a), add(0, b));
		while (o)
		{
			if (o & 1)
				ret = ret * tmp;
			tmp = tmp * tmp;
			o >>= 1;
		}
		return ret;
	}
};

long long T;
long long m, n;
int x;

int main()
{
	while(scanf("%lld", &n) != EOF)
	{
		complex ans = complex(3, 1) ^ n;
		printf("%05lld\n", ((ans.a << 1) - 1) % 100000);
	}
}