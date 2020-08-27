#include<stdio.h>
#include<string.h>

struct pp
{
	double first;
	double second;
};

int n, m, k;
double up, tp;
int x[1010];
double origin[1010];
double ans;

inline void init()
{
	memset(origin, 0, sizeof(origin));
	ans = 1145141919810.0;
}

inline double sigleorigin(int i)
{

	int pack = x[i] / k;
	int single = x[i] % k;
	return (pack * tp + single * up)<((pack + 1) * tp)?(pack * tp + single * up):((pack + 1) * tp);
}

inline struct pp coudan1(int j)
{
	int sum = x[0] + x[j];
	int pack = sum / k;
	int single = sum % k;
	if (pack == 0)
	{
		struct pp tt;
		tt.first=x[0] * up;
		tt.second=x[j] * up;
		return tt;
	}
	double cost_wang = (1.0 - (x[j] * 1.0 / ((double)pack * k * 1.0))) * pack * tp + single * up;
	double cost_j = (x[j] * 1.0 / ((double)pack * k * 1.0)) * pack * tp;
	struct pp tt;
	tt.first=cost_wang;
	tt.second=cost_j;
	return tt;
}

inline struct pp coudan2(int j)
{
	int sum = x[0] + x[j];
	int pack = sum / k;
	int single = sum % k;
	if (single > 0)pack++;
	if (pack == 0)
	{
		struct pp tt;
		tt.first=x[0] * up;
		tt.second=x[j] * up;
		return tt;
	}
	double cost_wang = (1.0 - (x[j] * 1.0 / ((double)pack * k * 1.0))) * pack * tp;
	double cost_j = (x[j] * 1.0 / ((double)pack * k * 1.0)) * pack * tp;
	struct pp tt;
	tt.first=cost_wang;
	tt.second=cost_j;
	return tt;
}

inline void calorigin()
{
	int i;
	for(i = 0; i <= n; ++i)
	{
		origin[i] = sigleorigin(i);
	}
	ans = origin[0];
}

int main()
{
	while(~scanf("%d", &n))
	{
		scanf("%d%d", &m, &k);
		scanf("%lf%lf", &up, &tp);
		int i;
		for(i = 1; i <= n; ++i)
		{
			scanf("%d", x + i);
		}
		if (up * k <= tp)
		{
			printf("%.2f\n", up * m);
			continue;
		}
		x[0] = m;
		calorigin();
		for(i = 1; i <= n; ++i)
		{
			struct pp tmp1 = coudan1(i);
			if (tmp1.second <= origin[i])
				ans =ans<tmp1.first?ans:tmp1.first;
			struct pp tmp2 = coudan2(i);
			if (tmp2.second <= origin[i])
				ans =ans<tmp2.first?ans:tmp2.first;
		}
		printf("%.2f\n", ans);
	}
}
