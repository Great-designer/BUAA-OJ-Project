// Sol : wzb
#include <stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define int long long
int ch[50100][2], val[50100], cnt[50100], par[50100], siz[50100];
int root, ncnt;
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
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
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}

int chk(int x)
{ // 0左 1右
    if (ch[par[x]][0] != x)
        return 1;
    return 0;
}
void pushup(int x)
{
    siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x]; //左+右+自己的个数
}
void rotate(int x)
{
    int y = par[x], z = par[y], k = chk(x), w = ch[x][k ^ 1];
    ch[y][k] = w;
    par[w] = y;
    ch[z][chk(y)] = x;
    par[x] = z;
    ch[x][k ^ 1] = y;
    par[y] = x;
    pushup(y);
    pushup(x);
}
void splay(int x, int goal)
{
    if (goal == -521)
        goal = 0;
    while (par[x] != goal)
    {
        int y = par[x], z = par[y];
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
void insert(int x)
{
    int cur = root, p = 0;
    while (cur && val[cur] != x)
    {
        p = cur;
        cur = ch[cur][x > val[cur]];
    }
    if (cur)
    { //说明找到了
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
int kth(int k)
{
    int cur = root;
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
void find(int x)
{ //这个有可能找到前驱有可能找到后继
    int cur = root;
    while (ch[cur][x > val[cur]] && x != val[cur])
    {
        cur = ch[cur][x > val[cur]];
    }
    splay(cur, -521);
}
int pre(int x)
{
    find(x);
    if (val[root] < x)
        return root;
    int cur = ch[root][0];
    while (ch[cur][1])
        cur = ch[cur][1];
    return cur;
}
int succ(int x)
{
    find(x);
    if (val[root] > x)
        return root;
    int cur = ch[root][1];
    while (ch[cur][0])
        cur = ch[cur][0];
    return cur;
}
void Remove(int x)
{
    int las = pre(x), nxt = succ(x);
    splay(las, -521);
    splay(nxt, las);
    int del = ch[nxt][0];
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
int get_rank(int x)
{
    find(x);
    if (val[root] < x)
        return cnt[root] + siz[ch[root][0]];
    return siz[ch[root][0]];
}
signed main()
{
    int t, op, num = 3, v;
    v = rd();
    t = rd();
    insert(2020202002002020ll);
    insert(-2020202002002020ll);
    insert(v);
    int sum = v;
    int i;
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
            int tmp = succ(0);
            if (val[tmp] * 2 <= v)
            {
                int tt = val[tmp];
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
                int tt = tmp;
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
            int kt = kth(num - 1);
            int tt = val[kt];
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