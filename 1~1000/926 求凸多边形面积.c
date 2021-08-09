#include<stdio.h>
#include<math.h>

struct node
{
	double x;
	double y;
};

struct node List[1010];

//利用解析几何中，叉乘的做法，S = ab向量叉乘ac向量/2
//由于内积的定义，这个结果一定非零
double area(struct node a,struct node b,struct node c)
{
	double abx = b.x - a.x, aby = b.y - a.y;
	double acx = c.x - a.x, acy = c.y - a.y;
	return fabs(abx * acy - acx * aby) * 0.5;
}

int n;

int main()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; ++i)
	{
		scanf("%lf%lf", &List[i].x, &List[i].y);
	}
	double result = 0;
	for (i = 0; i < n - 2; ++i)
	{
		result += area(List[0], List[i + 1], List[i + 2]);
	}
	printf("%.3lf\n", result);
}
