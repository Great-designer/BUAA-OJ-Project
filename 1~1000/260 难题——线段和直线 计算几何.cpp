#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

double read_double()
{
	double k = 0.0, f = 1.0;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')f=-1.0;
		c = getchar();
	}
	while(isdigit(c))
	{
		k = k * 10.0 + (c - 48);
		c = getchar();
	}
	if(c == '.')
	{
		double fraction = 1;
		c = getchar();
		while(isdigit(c))
		{
			fraction /= 10;
			k += (c - 48) * fraction;
			c = getchar();
		}
	}
	return k * f;
}

int read_int()
{
	int k = 0, f = 1;
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

//题目原型为所有线段都能投影到一条直线，且至少相交于一点
//那么对应的投影区域做一条垂线，垂线必然和所有线段相交
//求解的话，直接枚举所有线段中任意的两个端点的交点情况，只要全部经过就行了
//注意eps提示 考虑重点即可
//复杂度O(n^2)

int sgn(double x)
{
	if(fabs(x)<1e-8)return 0;
	return x > 0 ? 1 : -1;
}

struct Point
{
	double x,y;
	bool operator == (struct Point b)const
	{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (struct Point b)const
	{
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	struct Point operator -(const struct Point &b)const
	{
		struct Point temp;
		temp.x=x-b.x;
		temp.y=y-b.y;
		return temp;
	}
	double operator ^(const struct Point &b)const
	{
		return x*b.y - y*b.x;
	}
	double operator *(const struct Point &b)const
	{
		return x*b.x + y*b.y;
	}
	double dis(struct Point o)
	{
		return sqrt((*this-o)*(*this-o));
	}
} points[110 << 2];

struct Line
{
	struct Point s,e;
	void adjust()
	{
		if (e < s)
		{
			struct Point temp=s;
			s=e;
			e=temp;
		}
	}
	bool operator == (struct Line v)
	{
		return s == v.s || e == v.e;
	}
	bool parallel(struct Line v)
	{
		return sgn((e - s) ^ (v.e - v.s)) == 0;
	}
	int segcrossseg(struct Line v)
	{
		//本题重合视为相交,在这里统一视为非规范相交
		//重合是否算相交视情况而定
		//2:规范 1:非规范 0:不相交
		int d1 = sgn((e - s) ^ (v.s - s));
		int d2 = sgn((e - s) ^ (v.e - s));
		int d3 = sgn((v.e - v.s) ^ (s - v.s));
		int d4 = sgn((v.e - v.s) ^ (e - v.s));
		//位运算技巧:两者异号就是相跨,规范相交
		if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 2;
		bool b1 = (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0);
		bool b2 = (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0);
		bool b3 = (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0);
		bool b4 = (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
		return (int)(b1 || b2 || b3 || b4);
	}
	//线段直线相交 *this是直线 v是线段 返回值同上
	int linecrossseg(struct Line v)
	{
		double d1 = (e-s)^(v.s-s);
		double d2 = (e-s)^(v.e-s);
		double flag = sgn(d1)*sgn(d2);
		return flag<0?2:flag==0?1:0;//非规范相交即两者重合
	}
} segs[110];

int t,n;

bool check(struct Line line)  //端点组成的直线是否和所有的线段相交
{
	if(sgn(line.e.dis(line.s))==0)return 0;//枚举的端点共点
	for(int i = 1; i <= n; ++i)
		if(!line.linecrossseg(segs[i]))return 0;
	return 1;//枚举出来的端点构成的线段与n个给定线段都相交
}

bool flag;
int cnt;

int main()
{
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			cnt = 0;
			flag = 0;
			n = read_int();
			int i;
			for(i = 1; i <= n; ++i)
			{
				segs[i].s.x=read_double();
				segs[i].s.y=read_double();
				segs[i].e.x=read_double();
				segs[i].e.y=read_double();
				points[++cnt]=segs[i].s;
				points[++cnt]=segs[i].e;
			}
			for(i = 1; i <= cnt && !flag; ++i)
			{
				int j;
				for(j = i+1; j <= cnt && !flag; ++j)
				{
					struct Line temp;
					temp.s=points[i];
					temp.e=points[j];
					flag=check(temp);
				}
			}
			puts(flag?"YES":"NO");
		}
	}
}
