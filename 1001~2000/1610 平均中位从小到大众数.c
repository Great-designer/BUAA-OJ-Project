#include<stdio.h>

int main()
{
	int m=0,b[7]= {0};
	double a[7],s;
	int i;
	for (i=0; i<7; i++)
	{
		scanf("%lf",&a[i]);
	}
	s=(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6])/7;
	int j;
	for(j=0; j<7; j++)
	{
		for(i=0; i<7-j-1; i++)
		{
			if(a[i]>a[i+1])
			{
				int x=a[i+1];
				a[i+1]=a[i];
				a[i]=x;
			}
		}
	}
	for(i-0; i<7; i++)
	{
		for(j=i+1; j<7; j++)
		{
			if(a[j]==a[i])
			{
				b[i]++;
			}
			if(m<=b[i])
			{
				m=b[i];
			}
		}
	}
	printf("%.2lf %.2lf\n",s,a[3]);
	for (i=0; i<7; i++)
	{
		if(b[i]==m)
		{
			printf("%.2lf ",a[i]);
		}
	}
}
