#include<stdio.h> 

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double x,k;
		scanf("%lf%lf",&x,&k);
		printf("%.3lf\n",k/x);
	}
}
