#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, m, k;
int last[210], e[1300], pre[1300];
int v[210], pp[210];
int xx, yy;

struct node
{
    int x, y;
};

struct node a[610];

int cmp(const void *p1, const void *p2)
{
    struct node *a = (struct node *) p1;
    struct node *b = (struct node *) p2;
    if (a->x < b->x)
    {
        return 1;
    }
    else if (a->x > b->x)
    {
        return -1;
    }
    else if (a->y < b->y)
    {
        return 1;
    }
    else if (a->y > b->y)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int flag;

void dfs(int x, int y)
{
    v[x] = y;
    pp[x] = 1;
    int i;
    for (i = last[x]; i > 0; i = pre[i])
    {
        if (!pp[e[i]] && e[i] != xx && e[i] != yy)
        {
            dfs(e[i], 3 - y);
        }
        else
        {
            if (v[e[i]] == v[x] && e[i] != xx && e[i] != yy)
            {
                flag = 1;
                break;
            }
        }
    }
}

int main()
{
    memset(e, 0, sizeof(e));
    while (scanf("%d %d %d", &n, &m, &k) == 3)
    {
        memset(last, 0, sizeof(last));
        int i;
        for (i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x > y)
            {
                int temp = x;
                x = y;
                y = temp;
            }
            e[i * 2] = y;
            pre[i * 2] = last[x];
            last[x] = i * 2;
            e[i * 2 - 1] = x;
            pre[i * 2 - 1] = last[y];
            last[y] = i * 2 - 1;
            a[i].x = x, a[i].y = y;
        }
        qsort(a + 1, m, sizeof(struct node), cmp);
        int num = 0;
        if (k == 0)
        {
            if (m != 0)
            {
                num = 1;
            }
            for (i = 2; i <= m; i++)
            {
                if (a[i].x != a[i - 1].x || a[i].y != a[i - 1].y)
                {
                    num++;
                }
            }
            if (num > 1)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
        else if (k == 1)
        {
            int fflag = 0;
            for (i = 0; i < n; i++)
            {
                int j;
                for (j = i + 1; j < n; j++)
                {
                    memset(v, 0, sizeof(v));
                    memset(pp, 0, sizeof(pp));
                    flag = 0;
                    xx = i, yy = j;
                    int l;
                    for (l = 0; l < n; l++)
                    {
                        if (l == i || l == j)
                        {
                            continue;
                        }
                        if (!pp[l])
                        {
                            dfs(l, 1);
                        }
                    }
                    if (!flag)
                    {
                        fflag = 1;
                        break;
                    }
                }
            }
            if (fflag)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}

