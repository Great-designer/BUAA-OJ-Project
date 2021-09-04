#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		printf("%.3lf\n",a+b);
	}
}