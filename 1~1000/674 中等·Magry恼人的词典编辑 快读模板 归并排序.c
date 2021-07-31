#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct FastIO
{
	char wbuf[30000010];
	char *p_now;
};

int read(struct FastIO *a)
{
	int len = fread(a->wbuf, 1, 30000010, stdin);
	return len;
}

int readInt(struct FastIO *a)
{
	int ret = 0;
	int k = 1;
	while (!isdigit(*(a->p_now)))
	{
		if (*(a->p_now)== '-')
		{
			k = -1;
		}
		++(a->p_now);
	}
	do
	{
		ret = ret * 10 + *(a->p_now)++ - '0';
	}
	while (isdigit(*(a->p_now)));
	return ret * k;
}

char* readline(struct FastIO *a)
{
	while (!isgraph(*(a->p_now)))
	{
		++(a->p_now);
	}
	char* begin = (a->p_now);
	while (isgraph(*(a->p_now)))
	{
		++(a->p_now);
	}
	*(a->p_now)= '\0';
	return begin;
}

char* str[100010];
char* tmp[100010];
long long res;

void merge(int lo, int hi)
{
	if (hi > lo)
	{
		int mi = (hi + lo) >> 1;
		merge(lo, mi);
		merge(mi + 1, hi);
		int bmark = lo;
		int lomark = lo;
		int himark = mi + 1;
		while (lomark <= mi || himark <= hi)
		{
			if ((himark > hi || strcmp(str[lomark], str[himark]) <= 0) && lomark <= mi)
			{
				tmp[bmark++] = str[lomark++];
			}
			else
			{
				tmp[bmark++] = str[himark++];//此时需要统计逆序的问题，子问题合并排序完之后就方便多了
				res += 1ll * mi - 1ll * lomark + 1ll;//表示的是左边的数组有多少个比他大的
			}
		}
		int i;
		for (i = lo; i <= hi; i++)
		{
			str[i] = tmp[i];
		}
	}
	return;
}

struct FastIO in;
int n, t;

int main()
{
	in.p_now=in.wbuf;
	read(&in);
	t =readInt(&in);
	while (t--)
	{
		res = 0;
		n =readInt(&in);
		int i;
		for (i = 0; i < n; ++i)
		{
			str[i] =readline(&in);
		}
		merge(0, n - 1);
		printf("%lld\n", res);
	}
}