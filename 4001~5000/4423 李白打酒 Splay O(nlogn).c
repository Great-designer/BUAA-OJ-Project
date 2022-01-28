#include<stdio.h>

long long ch[50100][2], val[50100], cnt[50100], par[50100], siz[50100];
long long root, ncnt;

void wr(long long x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		wr(x / 10);
	putchar(x % 10 + 48);
}

long long rd()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

long long chk(long long x)
{
	// 0左 1右
	if (ch[par[x]][0] != x)
		return 1;
	return 0;
}

void pushup(long long x)
{
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x]; //左+右+自己的个数
}

void rotate(long long x)
{
	long long y = par[x], z = par[y], k = chk(x), w = ch[x][k ^ 1];
	ch[y][k] = w;
	par[w] = y;
	ch[z][chk(y)] = x;
	par[x] = z;
	ch[x][k ^ 1] = y;
	par[y] = x;
	pushup(y);
	pushup(x);
}

void splay(long long x, long long goal)
{
	if (goal == -521)
		goal = 0;
	while (par[x] != goal)
	{
		long long y = par[x], z = par[y];
		if (z != goal)
		{
			if (chk(x) == chk(y))
				rotate(y);
			//三点一线 旋转父节点
			else
				rotate(x); //不然旋转自己
		}
		rotate(x);
	}
	if (!goal)
		root = x; // goal是0 x的父节点是0 则根为x
}

void insert(long long x)
{
	long long cur = root, p = 0;
	while (cur && val[cur] != x)
	{
		p = cur;
		cur = ch[cur][x > val[cur]];
	}
	if (cur)
	{
		//说明找到了
		cnt[cur]++;
	}
	else
	{
		cur = ++ncnt;
		//如果存在父亲
		if (p)
			ch[p][x > val[p]] = cur;

		ch[cur][0] = ch[cur][1] = 0;
		val[cur] = x;
		par[cur] = p;
		cnt[cur] = siz[cur] = 1;
	}
	splay(cur, -521);
}

long long kth(long long k)
{
	long long cur = root;
	while (1)
	{
		if (ch[cur][0] && k <= siz[ch[cur][0]])
		{
			cur = ch[cur][0];
		}
		else if (k > siz[ch[cur][0]] + cnt[cur])
		{
			k -= siz[ch[cur][0]] + cnt[cur];
			cur = ch[cur][1];
		}
		else
		{
			return cur;
		}
	}
}

void find(long long x)
{
	//这个有可能找到前驱有可能找到后继
	long long cur = root;
	while (ch[cur][x > val[cur]] && x != val[cur])
	{
		cur = ch[cur][x > val[cur]];
	}
	splay(cur, -521);
}

long long pre(long long x)
{
	find(x);
	if (val[root] < x)
		return root;
	long long cur = ch[root][0];
	while (ch[cur][1])
		cur = ch[cur][1];
	return cur;
}

long long succ(long long x)
{
	find(x);
	if (val[root] > x)
		return root;
	long long cur = ch[root][1];
	while (ch[cur][0])
		cur = ch[cur][0];
	return cur;
}

void Remove(long long x)
{
	long long las = pre(x), nxt = succ(x);
	splay(las, -521);
	splay(nxt, las);
	long long del = ch[nxt][0];
	if (cnt[del] > 1)
	{
		cnt[del]--;
		splay(del, -521);
	}
	else
	{
		ch[nxt][0] = 0;
		cnt[del] = 0;
		siz[del] = 0;
		val[del] = 0;
		ch[del][0] = ch[del][1] = 0;
		par[del] = 0;
	}
}

long long get_rank(long long x)
{
	find(x);
	if (val[root] < x)
		return cnt[root] + siz[ch[root][0]];
	return siz[ch[root][0]];
}

signed main()
{
	long long t, op, num = 3, v;
	v = rd();
	t = rd();
	insert(2020202002002020ll);
	insert(-2020202002002020ll);
	insert(v);
	long long sum = v;
	long long i;
	for (i = 1; i <= t; i++)
	{
		op = rd();
		putchar('D');
		putchar('a');
		putchar('y');
		putchar(' ');
		wr(i);
		putchar(':');
		putchar(' ');
		switch (op)
		{
			case 1:
			{
				if (sum == 0)
				{
					puts("0");
					continue;
				}
				long long tmp = succ(0);
				if (val[tmp] * 2 <= v)
				{
					long long tt = val[tmp];
					Remove(val[tmp]);
					tt *= 2;
					insert(tt);
					sum += tt / 2;
					wr(sum);
				}
				else
				{
					sum -= val[tmp];
					Remove(val[tmp]);
					long long tt = tmp;
					tt = v;
					insert(tt);
					sum += tt;
					wr(sum);
				}
				break;
			}
			case 2:
			{
				if (sum == 0)
				{
					puts("Such beautiful flowers, what a pity!");
					continue;
				}
				long long kt = kth(num - 1);
				long long tt = val[kt];
				Remove(val[kt]);
				tt--;
				insert(tt);
				sum -= 1;
				wr(sum);
				break;
			}
			case 3:
			{
				num++;
				sum += v;
				insert(v);
				wr(sum);
				break;
			}
		}
		putchar(10);
	}
}