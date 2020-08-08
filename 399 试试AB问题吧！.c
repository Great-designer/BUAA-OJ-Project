#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		if(b==0)
		{
			printf("Error!\n");
		}
		else
		{
			printf("%.2lf\n",a/b);
		}
	}
}

