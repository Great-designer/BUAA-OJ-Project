#include<stdio.h>
#include<math.h>

int a[20001];

int main()
{
	int i,j;
	double m;
	while(scanf("%lf",&m)!=EOF)
	{
		i=round(m*100)+10000;
		a[i]++;
	}
	for(i=0; i<=20000; i++)
	{
		if(a[i]>0)
			for(j=1; j<=a[i]; j++)
			{
				printf("%g\n",((double)i-10000)/100);
			}
	}
	return 0;
}