#include<stdio.h>
#include<string.h>
#include<ctype.h>

#include<algorithm>

using namespace std;

struct Scanner
{
	char buf[30000002];
	char *p_now;
};

void read(struct Scanner *a)
{
	fread(a->buf, 1, 30000002, stdin);
}

int nextInt(struct Scanner *a)
{
	int ret = 0;
	while (!isdigit(*(a->p_now)))
	{
		++(a->p_now);
	}
	do
	{
		ret = ret * 10 + *(a->p_now)++ - '0';
	}
	while (isdigit(*(a->p_now)));
	return ret;
}

char *nextLine(struct Scanner *a)
{
	while (!isgraph(*(a->p_now)))
	{
		++(a->p_now);
	}
	char *begin = (a->p_now);
	while (isgraph(*(a->p_now)))
	{
		++(a->p_now);
	}
	*(a->p_now) = '\0';
	return begin;
}

struct Scanner in;
char *str[3000006];

bool cmp(const char *p, const char *q)
{
	return strcmp(p, q) < 0;
}

int main()
{
	in.p_now=in.buf;
	read(&in);
	int T = nextInt(&in);
	int k, n;
	while (T--)
	{
		k = nextInt(&in);
		n = nextInt(&in);
		int i;
		for (i=0; i<n; ++i)
		{
			str[i] = nextLine(&in);
		}
		nth_element(str, str+k-1, str+n, cmp);
		puts(str[k-1]);
	}
	return 0;
}
