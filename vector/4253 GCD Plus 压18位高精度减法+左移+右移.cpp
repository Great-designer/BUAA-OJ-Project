#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

struct bignum
{
	static const unsigned long long base = 1000000000000000000ull;
	vector<unsigned long long> a;
	inline void in()
	{
		static char s[10001];
		scanf("%s", s);

		for (int n = strlen(s), i = 0;;)
		{
			a.push_back(0);

			if (n - i <= 18)
			{
				for (int j = 0; i + j < n; a.back() = (a.back() << 3) + (a.back() << 1) + (s[j] ^ 48), ++j);

				break;
			}

			i += 18;

			for (int j = 0; j < 18; a.back() = (a.back() << 3) + (a.back() << 1) + (s[n - i + j] ^ 48), ++j);
		}
	}
	inline void out() const
	{
		printf("%llu", a.back());

		if (a.size() >= 2)
			for (int i = a.size() - 2; i >= 0; printf("%018llu", a[i--]));
	}
	inline int cmp(const bignum &b) const
	{
		if (a.size() ^ b.a.size())
			if (a.size() < b.a.size())
				return -1;
			else
				return 1;

		for (int i = a.size() - 1; i >= 0; --i)
			if (a[i] ^ b.a[i])
				if (a[i] < b.a[i])
					return -1;
				else
					return 1;

		return 0;
	}
	//除或乘2
	inline void chu()
	{
		for (int i = a.size() - 1; i >= 0; (a[i] & 1) && (a[i - 1] += base), a[i--] >>= 1);

		for (; !a.back(); a.pop_back());
	}
	inline void cheng()
	{
		for (int i = 0; i < a.size(); a[i++] <<= 1);

		for (int i = 0; i < a.size() - 1; a[i + 1] += a[i] / base, a[i] %= base, ++i);

		if (a.back() >= base)
			a.push_back(a.back() / base), a[a.size() - 2] %= base;
	}
	inline void operator-=(const bignum &b)
	{
		for (int i = 0; i < b.a.size(); ++i)
		{
			a[i] -= b.a[i];

			for (; a[i] >> 63; a[i] += base, --a[i + 1]);
		}

		for (; !a.back(); a.pop_back());
	}
} a, b;

bignum gcd(bignum a, bignum b)
{
	int cnt = 0, tmp = 0;

	while (!(a.a[0] & 1) && !(b.a[0] & 1))
		a.chu(), b.chu(), ++cnt;

	while (1)
	{
		while (!(a.a[0] & 1))
			a.chu();

		while (!(b.a[0] & 1))
			b.chu();

		tmp = a.cmp(b);

		if (!tmp)
			break;

		if (tmp >> 31)
			b -= a;
		else
			a -= b;
	}

	while (cnt--)
		a.cheng();

	return a;
}

int main()
{
	a.in();
	b.in();
	gcd(a, b).out();
}