#include<stdio.h>
#include<string.h>

struct BigInteger
{
	long long num[250];
	int size;
};

struct BigInteger Minus(struct BigInteger a,struct BigInteger b)
{
	struct BigInteger c=a;
	int i;
	for(i = 1; i <= c.size; ++i)
	{
		c.num[i] -= b.num[i];
		if (c.num[i] < 0)
		{
			c.num[i + 1] -= 1;
			c.num[i] += 100000000;
		}
	}
	while (!c.num[c.size] && c.size)
	{
		--c.size;
	}
	return c;
}

struct BigInteger right_one(struct BigInteger a)
{
	struct BigInteger c=a;
	int i;
	for (i = c.size; i > 0; --i)
	{
		c.num[i - 1] += (c.num[i] & 1ll) * 100000000;
		c.num[i] >>= 1;
	}
	c.num[0] = 0;
	while (!c.num[c.size] && c.size)
	{
		--c.size;
	}
	return c;
}

struct BigInteger left(struct BigInteger a,int b)
{
	struct BigInteger c=a;
	int k;
	for(k = 0; k < b; ++k)
	{
		int i;
		for(i = 1; i <= c.size; ++i)
		{
			c.num[i] <<= 1;
		}
		for(i = 1; i <= c.size; ++i)
		{
			if (c.num[i] >= 100000000)
			{
				c.num[i] -= 100000000;
				c.num[i + 1]++;
			}
		}
		if (c.num[c.size + 1])
		{
			c.size++;
		}
	}
	return c;
}

char Bigger(struct BigInteger a,struct BigInteger b)
{
	if(a.size != b.size)
	{
		return a.size > b.size;
	}
	int i;
	for(i =a.size; i; --i)
	{
		if (a.num[i] != b.num[i])
		{
			return a.num[i] > b.num[i];
		}
	}
	return 0;
}

struct BigInteger gcd(struct BigInteger a, struct BigInteger b)
{
	int r = 0;
	while (!(a.num[1] & 1 || b.num[1] & 1))
	{
		a=right_one(a);
		b=right_one(b);
		++r;
	}
	while (1)
	{
		while (!(a.num[1] & 1))
		{
			a=right_one(a);
		}
		while (!(b.num[1] & 1))
		{
			b=right_one(b);
		}
		if (Bigger(a,b))
		{
			a=Minus(a,b);
		}
		else
		{
			b=Minus(b,a);
		}
		if(a.size==0)
		{
			return left(b,r);
		}
		if(b.size==0)
		{
			return left(a,r);
		}
	}
}

char readBuf[1010];

void read(struct BigInteger *a)
{
	scanf("%s",readBuf);
	int len = strlen(readBuf);
	a->size = 0;
	long long wid = 1, cur = 0;
	int i;
	for(i = len - 1; i + 1; --i)
	{
		cur += (readBuf[i] ^ '0') * wid;
		wid = (wid << 1) + (wid << 3);
		if (wid == 100000000)
		{
			wid = 1;
			a->num[++a->size] = cur;
			cur = 0;
		}
	}
	if (cur)
	{
		a->num[++a->size] = cur;
	}
}

void print(struct BigInteger a)
{
	printf("%llu",a.num[a.size]);
	int i;
	for(i =a.size - 1; i > 0; --i)//0处不放东西,就算答案是0也没问题
	{
		printf("%08llu",a.num[i]);
	}
	putchar('\n');
}

struct BigInteger a,b;

int main()
{
	read(&a);
	read(&b);
	print(gcd(a,b));
}