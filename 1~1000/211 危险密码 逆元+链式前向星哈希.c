#include<stdio.h>
#include<string.h>

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

long long AmulBmodP(long long a, long long b, long long p)
{
	long long ret = 0;
	while (b)
	{
		if (b & 1)ret = (ret + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	return ret % p;
}

long long ApowBmodP(long long a, long long b, long long p)
{
	long long ret = 1;
	while (b)
	{
		if (b & 1)ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ret % p;
}

long long AmodP(long long a, long long p)
{
	while (a < 0) a += p;
	return a % p;
}

struct hashnode
{
	long long val;
	int next;
};

int hashcode(long long status)
{
	return status % 23333ll;
}

struct hashnode node[100010];
int head[23333ll], cnt;

int find(long long status)
{
	int code = hashcode(status);
	for (int i = head[code]; i; i = node[i].next)
		if (status == node[i].val)
			return i;
	return 0;
}

void add(long long status)
{
	if (!find(status))
	{
		int code = hashcode(status);
		node[++cnt].val = status;
		node[cnt].next = head[code];
		head[code] = cnt;
	}
}

long long pass;
long long hash_table[110];

void build_hash_table()
{
	hash_table[0] = 1;
	for (int i = 1; i <= 105; ++i)
		hash_table[i] = (hash_table[i - 1] * 23333ll) % 1000000007ll;
}

char s[110];
int len;
long long a[110], pre[110], suf[110];
long long code;

void build()
{
	for (int i = 1; i <= len; ++i) a[i] = (s[i] * hash_table[len - i]) % 1000000007ll;
	for (int i = 1; i <= len; ++i) pre[i] = (a[i] + pre[i - 1]) % 1000000007ll;
	for (int i = len; i >= 1; --i) suf[i] = (a[i] + suf[i + 1]) % 1000000007ll;
	code = pre[len];
}

long long tmp_code;
long long tmp_left, tmp_right, tmp_mid;

char judge()
{
	tmp_code = AmodP(code, 1000000007ll);//case 1 : original code
	if (find(tmp_code)) return 1;
	for (int i = 1; i <= len; ++i)//case 2 : replace 1 char
	{
		tmp_mid = code - a[i] + 'a' * hash_table[len - i];
		for (int j = 'a'; j <= 'z'; ++j)
		{
			tmp_code = AmodP(tmp_mid, 1000000007ll);
			if (find(tmp_code)) return 1;
			tmp_mid = tmp_mid + hash_table[len - i];
		}
	}
	for (int i = 0; i <= len; ++i)//case 3 : add 1 char
	{
		tmp_left = pre[i] * 23333ll, tmp_right = suf[i + 1];
		tmp_mid = tmp_left + hash_table[len - i] * 'a' + tmp_right;
		for (int j = 'a'; j <= 'z'; ++j)
		{
			tmp_code = AmodP(tmp_mid, 1000000007ll);
			if (find(tmp_code)) return 1;
			tmp_mid = tmp_mid + hash_table[len - i];
		}
	}
	for (int i = 1; i <= len; ++i)//case 4 : delete 1 char
	{
		tmp_left = pre[i - 1] * 203960058ll, tmp_right = suf[i + 1];
		tmp_mid = tmp_left + tmp_right;
		tmp_code = AmodP(tmp_mid, 1000000007ll);
		if (find(tmp_code)) return 1;
	}
	return 0;
}

int n, m;

void print(const char* a)
{
	for (int i = 0; i < strlen(a); ++i) putchar(a[i]);
}

int main()
{
	build_hash_table();
	while (scanf("%d", &n) != EOF)
	{
		m = rd();
		memset(head, 0, sizeof(head)), cnt = 0;
		while (n--) pass = rd(), add(pass);
		while (m--)
		{
			scanf("%s", s + 1);
			len = strlen(s + 1);
			build();
			print(judge() ? "Dangerous\n" : "Safe\n");
			memset(a, 0, sizeof(a));
			memset(pre, 0, sizeof(pre));
			memset(suf, 0, sizeof(suf));
		}
	}
}
