#include<stdio.h>
#include<string.h>

#include<unordered_set>
using namespace std;

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
	while(a < 0) a += p;
	return a % p;
}

const long long inv_K = ApowBmodP(23333, 1000000007 - 2, 1000000007);

unordered_set<long long> password;
long long pass;

long long hash_table[110];

void build_hash_table()
{
	hash_table[0] = 1;
	for(int i = 1; i <= 105; ++i)
		hash_table[i] = (hash_table[i - 1] * 23333) % 1000000007;
}

char s[110];
int len;
long long a[110], pre[110], suf[110];
long long code;

void build()
{
	for(int i = 1; i <= len; ++i) a[i] = (s[i] * hash_table[len - i]) % 1000000007;
	for(int i = 1; i <= len; ++i) pre[i] = (a[i] + pre[i - 1]) % 1000000007;
	for(int i = len; i >= 1; --i) suf[i] = (a[i] + suf[i + 1]) % 1000000007;
	code = pre[len];
}

long long tmp_code;
long long tmp_left, tmp_right, tmp_mid;

char judge()
{
	//case 1 : original code
	tmp_code = AmodP(code, 1000000007);
	if(password.count(tmp_code)) return 1;
	//case 2 : replace 1 char
	for(int i = 1; i <= len; ++i)
	{
		tmp_mid = code - a[i] + 'a' * hash_table[len - i];
		for(int j = 'a'; j <= 'z'; ++j)
		{
			tmp_code = AmodP(tmp_mid, 1000000007);
			if(password.count(tmp_code)) return 1;
			tmp_mid = tmp_mid + hash_table[len - i];
		}
	}
	//case 3 : add 1 char
	for(int i = 0; i <= len; ++i)
	{
		tmp_left = pre[i] * 23333, tmp_right = suf[i + 1];
		tmp_mid = tmp_left + hash_table[len - i] * 'a' + tmp_right;
		for(int j = 'a'; j <= 'z'; ++j)
		{
			tmp_code = AmodP(tmp_mid, 1000000007);
			if(password.count(tmp_code)) return 1;
			tmp_mid = tmp_mid + hash_table[len - i];
		}
	}
	//case 4 : delete 1 char
	for(int i = 1; i <= len; ++i)
	{
		tmp_left = pre[i - 1] * inv_K, tmp_right = suf[i + 1];
		tmp_mid = tmp_left + tmp_right;
		tmp_code = AmodP(tmp_mid, 1000000007);
		if(password.count(tmp_code)) return 1;
	}
	return 0;
}

int n, m;

int main()
{
	build_hash_table();
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d",&m);
		password.clear();
		while(n--)
		{
			scanf("%lld",&pass);
			password.insert(pass);
		}
		while(m--)
		{
			scanf("%s", s + 1);
			len = strlen(s + 1);
			build();
			printf("%s",judge() ? "Dangerous\n" : "Safe\n");
			memset(a, 0, sizeof(a));
			memset(pre, 0, sizeof(pre));
			memset(suf, 0, sizeof(suf));
		}
	}
}
