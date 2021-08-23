#include<stdio.h>

int main()
{
	double sp[7];
	double curT;
	double curF;
	double res;
	scanf("%lf%lf%lf%lf%lf%lf%lf",&sp[0],&sp[1],&sp[2],&sp[3],&sp[4],&sp[5],&sp[6]);
	curT = 1.0;
	curF = 1.0;
	res = 0.0;
	int i = 0;
	while (curT > 1e-10)
	{
		curT = curF * sp[i % 7];
		curF *= (1 - sp[i % 7]);
		res += (1ll * (i + 1)) * curT;
		++i;
	}
	printf("%.8lf", res);
}
