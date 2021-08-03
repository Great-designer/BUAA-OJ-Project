#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define PI acos(-1.0)

struct Point
{
	double x,y;
};

struct Point Minus(struct Point a,struct Point o)
{
	struct Point ans;
	ans.x=a.x-o.x;
	ans.y=a.y-o.y;
	return ans;
}

double dis(struct Point a,struct Point o)
{
	return hypot(a.x-o.x,a.y-o.y);
}

double Cross(struct Point a,struct Point o)
{
	return a.x*o.y-a.y*o.x;
}

struct Point points[100010], stack[100010];

int cnt;
double ans;

int cmp(const void *p1,const void *p2)
{
	struct Point *a=(struct Point *)p1;
	struct Point *b=(struct Point *)p2;
	double flag = Cross(Minus(*a,points[1]),Minus(*b,points[1]));
	if(flag > 0.0)
	{
		return -1;
	}
	else if (flag == 0.0 && dis(*a,points[1]) < dis(*b,points[1]))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int n, r;

int main()
{
	while(scanf("%d%d",&n, &r)!=EOF)
	{
		memset(points, 0, sizeof(points));
		memset(stack, 0, sizeof(stack));
		cnt = 1;
		ans = 0.0;
		int i;
		for(i = 1; i <= n; ++i)
		{
			scanf("%lf%lf",&points[i].x,&points[i].y);
			if(i != 1)
			{
				if(points[i].y < points[1].y)
				{
					struct Point temp=points[i];
					points[i]=points[1];
					points[1]=temp;
				}
				else if (points[i].y == points[1].y && points[i].x < points[1].x)
				{
					struct Point temp=points[i];
					points[i]=points[1];
					points[1]=temp;
				}
			}
		}
		qsort(points + 2,n-1,sizeof(struct Point), cmp);
		stack[1] = points[1];
		//右转叉乘是小于0的
		for(i = 2; i <= n; ++i)
		{
			while(cnt > 1 && Cross(Minus(stack[cnt],stack[cnt - 1]),Minus(points[i],stack[cnt])) <= 0.0)
			{
				cnt--;
			}
			stack[++cnt] = points[i];
		}
		stack[cnt+1]=points[1];//最后绕一圈回来
		for(i = 1; i <= cnt; ++i)
		{
			ans +=dis(stack[i],stack[i+1]);
		}
		ans += 4.0 * acos(0.0) * (double)r;
		printf("%lld\n",(long long)(ans+0.5));
	}
}

