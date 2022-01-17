#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Area 0 : public
char lex_smallest[11] = "0000000000";
char lex_biggest[11] = "zzzzzzzzzz";
// Area 1 : FastIO
int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + (c ^ 48);
		c = getchar();
	}
	return f > 0 ? k : -k;
}
void wr(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		wr(x / 10);
	putchar(x % 10 + 48);
}

void input_str(char *s)
{
	int i = 0;
	char c = getchar();
	while (isspace(c))
		c = getchar();
	while (!isspace(c))
		s[i++] = c, c = getchar();
	s[i] = '\0';
}
void output_str(char *s)
{
	int len = strlen(s), i = 0;
	while (i < len)
		putchar(s[i++]);
}

// Area 2 : Hashlist
#define mod 294703
const int seed = 761153;
struct hash
{
	char s[12];
	int next;
} list[1010];
int head[mod], cnt;
int hashcode(char *s)
{
	int len = strlen(s);
	long long ret = strlen(s);
	for (int i = 0; i < len; ++i)
		ret = (ret * seed + 1ll * s[i]) % mod;
	return ret;
}
int newnode(char *s)
{
	int code = hashcode(s);
	strcpy(list[++cnt].s, s);
	list[cnt].next = head[code];
	head[code] = cnt;
	return cnt;
}
int _find(char *s)
{
	int code = hashcode(s);
	for (int i = head[code]; i; i = list[i].next)
		if (!strcmp(list[i].s, s))
			return i;
	return 0;
}

// Area 3.1 Answer

char _s[12];
int score;
int res[20], sre[20], res_sz; // print player

// Area 3.2 Splay

int l[1010], r[1010], f[1010];
int a[1010], s[1010];
char *name[1010];
int root;

void update(int x)
{
	s[x] = s[l[x]] + s[r[x]] + 1;
}

void lr(int x)
{
	int y = f[x];
	r[y] = l[x];
	if (l[x])
		f[l[x]] = y;
	f[x] = f[y];
	if (root == y)
		root = x;
	else if (l[f[y]] == y)
		l[f[y]] = x;
	else
		r[f[y]] = x;
	f[y] = x, l[x] = y;
	update(y), update(x);
}

void rr(int x)
{
	int y = f[x];
	l[y] = r[x];
	if (r[x])
		f[r[x]] = y;
	f[x] = f[y];
	if (root == y)
		root = x;
	else if (l[f[y]] == y)
		l[f[y]] = x;
	else
		r[f[y]] = x;
	f[y] = x, r[x] = y;
	update(y), update(x);
}

void rotate(int x)
{
	if (l[f[x]] == x)
		rr(x);
	else
		lr(x);
}

void splay(int x, int target)
{
	while (f[x] != target)
	{
		if (f[f[x]] == target)
			rotate(x);
		else if ((l[f[x]] == x) == (l[f[f[x]]] == f[x]))
			rotate(f[x]), rotate(x);
		else
			rotate(x), rotate(x);
	}
}

void insert(int pos, int val)
{
	int x = root, y = 0;
	char *insert_name = list[pos - 2].s;
	while (x)
	{
		y = x;
		// x = (val <= a[x] ? l[x] : r[x]);//成绩相同, 先来后到
		//成绩相同, 字典序更小更靠前
		x = ((val < a[x] || (val == a[x] && strcmp(insert_name, name[x]) >= 0)) ? l[x] : r[x]);
	}
	if (val < a[y] || (val == a[y] && strcmp(insert_name, name[y]) >= 0))
		l[y] = pos;
	else
		r[y] = pos;
	f[pos] = y, l[pos] = r[pos] = 0;
	a[pos] = val, name[pos] = insert_name, s[pos] = 1;
	splay(pos, 0);
}

void erase(int x)
{
	splay(x, 0);
	if (!r[root])
		f[l[root]] = 0, root = l[root];
	else
	{
		int y = r[x];
		while (l[y])
			y = l[y];
		splay(y, root);
		l[y] = l[root], f[l[root]] = y, f[y] = 0;
		root = r[root];
		update(root);
	}
}

int find(int k)
{
	int x = root;
	while (s[r[x]] + 1 != k)
	{
		if (k < s[r[x]] + 1)
			x = r[x];
		else
			k -= s[r[x]] + 1, x = l[x];
	}
	return x;
}

void access(int x)
{
	if (!x)
		return;
	access(r[x]);
	res[++res_sz] = x;
	sre[res_sz] = a[x];
	access(l[x]);
}

void init()
{
	r[1] = 2, f[2] = 1;
	s[1] = 2, s[2] = 1;
	root = 1;
	name[1] = lex_biggest, name[2] = lex_smallest;
	a[1] = -2147483647, a[2] = 2147483647;
}
// lim : 10 player from rk
void query_with_rank(int rk)
{
	int x = rk + 1, y = rk + 1; // y = min(rk + 10, s[root] - 1);
	x = find(x - 1), y = find(y + 1);
	int tmp = x;
	x = y, y = tmp;
	splay(x, 0);
	splay(y, root);
	res_sz = 0;
	access(l[r[root]]);
	for (int j = 1; j <= res_sz; ++j)
		output_str(list[res[j] - 2].s), putchar(' '), wr(sre[j]), putchar('\n');
}

int n;
int main()
{
	n = rd();
	init(); // Splay init
	while (n--)
	{
		int op = rd();
		if (op == 1)
		{
			input_str(_s), score = rd();
			int cnt = _find(_s) + 2;
			if (cnt <= 2)
				cnt = newnode(_s) + 2, insert(cnt, score);
			else
				erase(cnt), insert(cnt, score);
		}
		else
		{
			int rk = rd();
			query_with_rank(rk);
		}
	}
}