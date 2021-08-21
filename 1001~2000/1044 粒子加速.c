#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	double x;
	while (n--)
	{
		scanf("%lf",&x);
		printf("%.2lf\n",asin(x / (1 + x)) * 2.33 +pow((x + 2), 3));
	}
}
