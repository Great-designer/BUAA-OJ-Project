#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double n;
long long cnt1, cnt2;

int main()
{
	srand((unsigned int) NULL);
	scanf("%lf", &n);
	double x, y;
	for(int i = 0; i < 1e8; ++i)
	{
		x = 1e-8 + (double)(n * rand() / RAND_MAX);
		y = (double) rand() / RAND_MAX;
		if(y <= sin(x)/ x)++cnt1;
		++cnt2;
	}
	printf("%.3lf\n",cnt1 * n / cnt2);
}
