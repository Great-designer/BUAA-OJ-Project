#include<stdio.h>

int main()
{
	int n = 0;
	double cur,sum = 0;
	while(~scanf("%lf",&cur))
	{
		sum += cur;
		n += 1;
	}
	printf("%.2f",sum / n);
}