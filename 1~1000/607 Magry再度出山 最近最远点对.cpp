#include<stdio.h>
#include<math.h>
#include<string.h>

#include<algorithm>
#include<iostream>

using namespace std;

struct Point
{
	long long x,y;
	Point(long long xx = 0, long long yy = 0)
	{
		x = xx, y = yy;
	}
	Point operator - (const Point& o) const
	{
		return Point(x - o.x, y - o.y);
	}
	long long operator ^(const Point& o) const
	{
		return x * o.y - y * o.x;
	}
	long long dis2(Point o)
	{
		return (x-o.x)*(x-o.x)+(y-o.y)*(y-o.y);
	}
	double dis(Point o)
	{
		return hypot(x - o.x, y - o.y);
	}
} p[200010], s[200010];
int tmp[200010];
long long read()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
int n,cnt;
bool cmp(Point a, Point b)
{
	long long flag = (a - p[1]) ^ (b - p[1]);
	if(flag > 0)return true;
	else if (flag == 0 && a.dis(p[1]) < b.dis(p[1])) return true;
	else return false;

}
void init()
{
	cnt = 0;
	memset(p, 0, sizeof(p));
	memset(s, 0, sizeof(s));
	memset(tmp,0,sizeof(tmp));
	for(int i = 1; i <= n; ++i)
		p[i].x = read(), p[i].y = read();
}
void get_convex()
{
	for(int i = 1; i <= n; ++i)
	{
		if(i!=1&&(p[i].y<p[1].y||(p[i].y==p[1].y&&p[i].x<p[1].x)))
			p[i].x ^= p[1].x, p[1].x ^= p[i].x, p[i].x ^= p[1].x,p[i].y ^= p[1].y, p[1].y ^= p[i].y, p[i].y ^= p[1].y;
	}
	sort(p+2,p+n+1,cmp);
	s[++cnt] = p[1], s[++cnt] = p[2];
	for(int i = 3; i <= n; ++i)
	{
		while(cnt>1&&(Point(s[cnt]-s[cnt-1])^Point(p[i]-s[cnt])) <= 0)
			cnt--;
		s[++cnt]=p[i];
	}
	s[0]=s[cnt];//为了后面的循环，所以把尾部加到前面
}
long long get_convex_diameter()
{
	if(n==1)return 0ll;
	if(cnt==2)return s[0].dis2(s[1]);
	int j = 2;
	long long ret = 0;
	//此处采用三角形面积的叉乘公式进行对比
	for(int i = 0; i < cnt; ++i)
	{
		while(((s[i+1]-s[i])^(s[j]-s[i]))<((s[i+1]-s[i])^(s[j+1]-s[i])))
			j=(j+1)%cnt;
		long long tmp = s[i].dis2(s[j]);
		if(tmp>ret)ret=tmp;
		tmp = s[i+1].dis2(s[j]);
		if(tmp>ret)ret=tmp;
	}
	return ret;
}
bool cmp2(Point a, Point b)
{
	if(a.x == b.x)return a.y < b.y;
	else return a.x < b.x;
}
bool cmpIndex(int a, int b)
{
	return p[a].y < p[b].y;
}
long long merge(int lo, int hi)
{
	long long dis = 1145141919810114514LL;
	if(lo==hi)return dis;
	if(lo+1==hi)return p[lo].dis2(p[hi]);
	int mi = (lo+hi)>>1;
	long long dis1 = merge(lo,mi);
	long long dis2 = merge(mi+1,hi);
	if(dis1<dis)dis=dis1;
	if(dis2<dis)dis=dis2;
	int ccnt = 0;
	for(int i = lo; i <= hi; ++i)
	{
		long long Abs = p[i].x-p[mi].x;
		if(Abs<0)Abs=-Abs;
		if(Abs<=dis) tmp[ccnt++]=i;
	}
	sort(tmp,tmp+ccnt,cmpIndex);
	for(int i = 0; i < ccnt; ++i)
	{
		for(int j = i+1; j < ccnt && p[tmp[j]].y-p[tmp[i]].y < dis; ++j)
		{
			long long dis3 = p[tmp[i]].dis2(p[tmp[j]]);
			if(dis > dis3)dis = dis3;
		}
	}
	return dis;
}
long long get_nearset()
{
	sort(p+1,p+n+1,cmp2);
	return merge(1,n);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		init();
		printf("%lld ",get_nearset());
		get_convex();
		printf("%lld\n",get_convex_diameter());
	}
}
