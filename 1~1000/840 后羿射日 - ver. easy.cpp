#include<stdio.h>
#include<string.h>

char readBuf[30];

struct BigInteger
{
	long long num[5];
	int size;
	BigInteger() :size(0)
	{
		memset(num, 0, sizeof(num));
	}
	BigInteger(const char* Num) :size(0)
	{
		memset(num, 0, sizeof(num));
		int len = strlen(Num);
		size = 0;
		long long wid = 1, cur = 0;
		for (int i = len - 1; i + 1; --i)
		{
			cur += (Num[i] ^ '0') * wid;
			wid = (wid << 1) + (wid << 3);
			if (wid == 100000000)
			{
				wid = 1;
				num[++size] = cur;
				cur = 0;
			}
		}
		if (cur)num[++size] = cur;
	}
	void print()
	{
		printf("%llu", num[size]);
		for (int i = size - 1; i > 0; --i)printf("%08llu", num[i]);
		//0处不放东西,就算答案是0也没问题
		putchar('\n');
	}
	void read()
	{
		scanf("%s", readBuf);
		int len = strlen(readBuf);
		size = 0;
		long long wid = 1, cur = 0;
		for (int i = len - 1; i + 1; --i)
		{
			cur += (readBuf[i] ^ '0') * wid;
			wid = (wid << 1) + (wid << 3);
			if (wid == 100000000)
			{
				wid = 1;
				num[++size] = cur;
				cur = 0;
			}
		}
		if (cur)num[++size] = cur;
	}
	bool operator < (const BigInteger& b) const
	{
		if (size != b.size)return size < b.size;
		for (int i = size; i; --i)
		{
			if (num[i] != b.num[i])return num[i] < b.num[i];
		}
		return false;
	}
	bool operator <= (const BigInteger& b) const
	{
		if (size != b.size)return size < b.size;
		for (int i = size; i; --i)
		{
			if (num[i] != b.num[i])return num[i] < b.num[i];
		}
		return true;
	}
	bool operator > (const BigInteger& b) const
	{
		if (size != b.size)return size > b.size;
		for (int i = size; i; --i)
		{
			if (num[i] != b.num[i])return num[i] > b.num[i];
		}
		return false;
	}
	bool operator >= (const BigInteger& b) const
	{
		if (size != b.size)return size > b.size;
		for (int i = size; i; --i)
		{
			if (num[i] != b.num[i])return num[i] > b.num[i];
		}
		return true;
	}
	bool operator == (const BigInteger& b) const
	{
		return (*this >= b) && (*this <= b);
	}
	bool operator != (const BigInteger& b) const
	{
		return (*this < b) || (*this > b);
	}
	BigInteger operator +(const BigInteger& b) const
	{
		BigInteger c;
		c.size = size;
		if (c.size < b.size)c.size = b.size;
		for (int i = 1; i <= c.size; ++i)
		{
			c.num[i] += num[i] + b.num[i];
			c.num[i + 1] = c.num[i] / 100000000;
			c.num[i] %= 100000000;
		}
		if (c.num[c.size + 1])++c.size;
		return c;
	}
	BigInteger operator -(const BigInteger& b)const
	{
		BigInteger c;
		c = *this;
		for (int i = 1; i <= c.size; ++i)
		{
			c.num[i] -= b.num[i];
			if (c.num[i] < 0)c.num[i + 1] -= 1, c.num[i] += 100000000;
		}
		while (!c.num[c.size] && c.size)--c.size;
		return c;
	}
	BigInteger addOne() const
	{
		BigInteger c = *this;
		c.num[1]++;
		int cur = 1;
		while (c.num[cur] >= 100000000)++c.num[cur + 1], c.num[cur++] -= 100000000;
		if (c.num[c.size + 1])++c.size;
		return c;
	}
	BigInteger minusOne() const
	{
		BigInteger c = *this;
		c.num[1]--;
		int cur = 1;
		while (c.num[cur] < 0)--c.num[cur + 1], c.num[cur++] += 100000000;
		if (!c.num[c.size])--c.size;
		return c;
	}
	BigInteger operator >> (const int& b)const
	{
		BigInteger c;
		c = *this;
		for (int k = 0; k < b; ++k)
		{
			for (int i = c.size; i > 0; --i)
			{
				c.num[i - 1] += (c.num[i] & 1ll) * 100000000;
				c.num[i] >>= 1;
			}
			c.num[0] = 0;
		}
		while (!c.num[c.size] && c.size)--c.size;
		return c;
	}
	BigInteger operator << (const int& b)const
	{
		BigInteger c;
		c = *this;
		for (int k = 0; k < b; ++k)
		{
			for (int i = 1; i <= c.size; ++i) c.num[i] <<= 1;
			for (int i = 1; i <= c.size; ++i)
			{
				if (c.num[i] >= 100000000)
					c.num[i] -= 100000000, c.num[i + 1]++;
			}
			if (c.num[c.size + 1])c.size++;
		}
		return c;
	}
	BigInteger operator * (const BigInteger& b) const
	{
		BigInteger c;
		for (int i = 1; i <= size; ++i)
		{
			for (int j = 1; j <= b.size; ++j)
			{
				c.num[i + j - 1] += (num[i] * b.num[j]);
			}
		}
		c.size = size + b.size + 2;
		for (int i = 1; i <= c.size; ++i)
			c.num[i + 1] += c.num[i] / 100000000, c.num[i] %= 100000000;
		while (!c.num[c.size])--c.size;
		return c;
	}
	BigInteger operator / (BigInteger b) const
	{
		BigInteger e = BigInteger("1"), ret;
		BigInteger a = *this;
		while (a >= b) b = b << 1, e = e << 1;
		while (e.size > 1 || e.num[1])
		{
			if (a >= b)
			{
				a = a - b;
				ret = ret + e;
			}
			b = b >> 1;
			e = e >> 1;
		}
		return ret;
	}
	BigInteger operator % (const BigInteger& b) const
	{
		BigInteger div = *this / b;
		BigInteger c = *this - div * b;
		return c;
	}
	//开根用不上这个
	BigInteger fastpower(int b)
	{
		BigInteger c = BigInteger("1");
		BigInteger d = *this;
		while (b)
		{
			if (b & 1)c = c * d;
			d = d * d;
			b >>= 1;
		}
		return c;
	}
};

BigInteger tmp;
BigInteger sum;
BigInteger b;
BigInteger first, second, third;
int n;
//记住:单纯的二分答案求开根必吃TLE,应对这些问题,中间需要有必要的剪枝

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		sum = first = second = third = BigInteger("0");

		while (n--)
		{
			tmp.read();
			if (tmp > first)
			{
				third = second;
				second = first;
				first = tmp;
			}
			else if (tmp > second)
			{
				third = second;
				second = tmp;
			}
			else if (tmp > third)
				third = tmp;
		}
		sum = first + second + third;
		b.read();
		(sum % b).print();
		puts("");
	}
}
