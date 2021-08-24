#include<stdio.h>
#include<ctype.h>

int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

void wr(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9)wr(x / 10);
	putchar(x % 10 + '0');
}

int a[3][3];

char trans(int a)
{
	char ret = 0;
	switch (a)
	{
		case 0:
			ret = 0;
			break;
		case 1:
			ret = 1;
			break;
		case 2:
			ret = 2;
			break;
		case 3:
			ret = 3;
			break;
		default:
			break;
	}
	return ret;
}

char check()
{
	char ret = 0;
	if (a[0][0] && a[0][0] == a[1][1] && a[1][1] == a[2][2])
		ret = trans(a[0][0]);
	else if (a[2][0] && a[2][0] == a[1][1] && a[1][1] == a[0][2])
		ret = trans(a[2][0]);
	else
	{
		for (int i = 0; i < 3 && ret == 0; ++i)
			if (a[i][0] && a[i][0] == a[i][1] && a[i][1] == a[i][2])
				ret = trans(a[i][0]);
		for (int i = 0; i < 3 && ret == 0; ++i)
			if (a[0][i] && a[0][i] == a[1][i] && a[1][i] == a[2][i])
				ret = trans(a[0][i]);
	}
	if (ret != 0) return ret;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (a[i][j] == 0)
				return 0;
	return 3;
}

int f()
{
	int ret = 1;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			ret += (a[i][j] == 0);
	return ret;
}
//记忆化搜索
struct hash
{
	long long status;
	int f;
	int next;
};

int hashcode(long long status)
{
	return status % 23333;
}

struct hash node[65536];
int head[23333], cnt_hash;

int find(long long status)
{
	int code = hashcode(status);
	for (int i = head[code]; i; i = node[i].next)
		if (status == node[i].status)
			return node[i].f;
	return -1;
}

void add(long long status, int f)
{
	int code = hashcode(status);
	node[++cnt_hash].status = status;
	node[cnt_hash].f = f;
	node[cnt_hash].next = head[code];
	head[code] = cnt_hash;
}

long long get_status()
{
	long long ret = 0;
	for (int i = 2; ~i; --i)
		for (int j = 2; ~j; --j)
			ret = (ret << 1) + (ret << 3) + a[i][j];
	return ret;
}
//对抗搜索
int dfs(int p)
{
	long long status = get_status();
	int tmp = find(status);
	if (tmp != -1) return tmp;
	char res = check();
	int ret;
	if (res == 1)
	{
		ret = f();
		add(status, ret);
		return ret;
	}
	else if (res == 2)
	{
		ret = -f();
		add(status, ret);
		return ret;
	}
	else if (res == 3)
	{
		ret = 0;
		add(status, ret);
		return ret;
	}
	else
	{
		//min-max搜索部分
		int minp = 11, maxp = -11;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (a[i][j]) continue;
				a[i][j] = p;//搜索:当前位执子下p
				int nxt = dfs(p == 1 ? 2 : 1);//轮换下棋
				if (p == 1) maxp=maxp>nxt?maxp:nxt;//先手-我方
				else minp=minp<nxt?minp:nxt;//后手-对方
				a[i][j] = 0;//回溯
			}
		}
		if (p == 1) ret = maxp;
		else ret = minp;
		add(status, ret);
		return ret;
	}
}

int t;
int offensive;

int main()
{
	while (!feof(stdin))
	{
		offensive = rd();
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				a[i][j] = rd();
		wr(dfs(offensive)), putchar('\n');
		putchar('\n');
	}
}