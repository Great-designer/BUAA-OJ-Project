#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
const double INF = 1e15;
const double eps = 1e-8;

int n;
double mind;
struct point
{
    double x, y;
    char type;
} points[200005], tmp[200005];
int cmp(const void *p1, const void *p2)
{
    struct point *a = (struct point *)p1, *b = (struct point *)p2;
    if (a->x < b->x)
        return -1;
    else if (a->x == b->x && a->y < b->y)
        return -1;
    else if (a->x == b->x && a->y > b->y)
        return 1;
    else if (a->x > b->x)
        return 1;
    else
        return 0;
}
double get_dist(struct point a, struct point b)
{
    if (a.type == b.type)
        return mind; // optimize when all the points are overlapped
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double dfs(int l, int r)
{
    if (l == r)
        return INF;
    int mid = (l + r) >> 1;
    double mid_x = points[mid].x;
    double ans = fmin(dfs(l, mid), dfs(mid + 1, r));

    int i = l, j = mid + 1, cnt = 0;
    while (i <= mid && j <= r)
        if (points[i].y < points[j].y)
            tmp[cnt++] = points[i++];
        else
            tmp[cnt++] = points[j++];
    while (i <= mid)
        tmp[cnt++] = points[i++];
    while (j <= r)
        tmp[cnt++] = points[j++];
    for (i = l; i <= r; i++)
        points[i] = tmp[i - l];

    cnt = 0;
    for (i = l; i <= r; i++)
        if (points[i].x >= mid_x - ans && points[i].x <= mid_x + ans)
            tmp[cnt++] = points[i];
    for (i = 0; i < cnt; i++)
        for (j = i - 1; ~j && tmp[i].y - tmp[j].y + eps <= ans; j--)
            ans = fmin(ans, get_dist(tmp[i], tmp[j]));
    mind = fmin(mind, ans);
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &points[i].x, &points[i].y);
            points[i].type = 0;
        }
        for (int i = n; i < n << 1; i++)
        {
            scanf("%lf %lf", &points[i].x, &points[i].y);
            points[i].type = 1;
        }
        mind = get_dist(points[0], points[(n << 1) - 1]);
        qsort(points, n << 1, sizeof(points[0]), cmp);
        printf("%.3f\n", dfs(0, (n << 1) - 1));
    }
    return 0;
}
