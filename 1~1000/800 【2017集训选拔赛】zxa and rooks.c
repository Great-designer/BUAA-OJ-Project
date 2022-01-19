#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100005
struct interval
{
    int xl, xr, yl, yr;
    int x, y;
    int num;
} a[maxn];

int cmp_order(const void *p1, const void *p2)
{
    struct interval *a = (struct interval *)p1, *b = (struct interval *)p2;
    if (a->num < b->num)
        return -1;
    else if (a->num > b->num)
        return 1;
    else
        return 0;
}
//��rΪ�ؼ��ֽ�������
int cmp_x(const void *p1, const void *p2)
{
    struct interval *a = (struct interval *)p1, *b = (struct interval *)p2;
    if (a->xr < b->xr)
        return -1;
    else if (a->xr > b->xr)
        return 1;
    else
        return 0;
}

int cmp_y(const void *p1, const void *p2)
{
    struct interval *a = (struct interval *)p1, *b = (struct interval *)p2;
    if (a->yr < b->yr)
        return -1;
    else if (a->yr > b->yr)
        return 1;
    else
        return 0;
}

char have[maxn];

void solve(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &a[i].xl, &a[i].xr, &a[i].yl, &a[i].yr);
        a[i].num = i; //�ڶ���ʱ��¼��ţ��������֮���Ż���
    }

    memset(have, 0, sizeof(have)); //�������ݣ�ע���ʼ��
    qsort(a + 1, n, sizeof(struct interval), cmp_x);
    for (int i = 1; i <= n; ++i)
    {
        int x = a[i].xl;
        while (have[x] && x <= a[i].xr) //�ҵ���һ��û�б�ѡ���ĵ�
            x++;
        if (x > a[i].xr)
        {
            puts("IMPOSSIBLE");
            return;
        }
        else
        {
            a[i].x = x;
            have[x] = 1;
        }
    }
    memset(have, 0, sizeof(have));
    qsort(a + 1, n, sizeof(struct interval), cmp_y);
    for (int i = 1; i <= n; ++i)
    {
        int y = a[i].yl;
        while (have[y] && y <= a[i].yr)
            y++;
        if (y > a[i].yr)
        {
            puts("IMPOSSIBLE");
            return;
        }
        a[i].y = y;
        have[y] = 1;
    }

    qsort(a + 1, n, sizeof(struct interval), cmp_order); //�Ż���
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", a[i].x, a[i].y);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
        scanf("%d", &n), solve(n);
}