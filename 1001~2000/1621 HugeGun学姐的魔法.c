#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		if (a==0&&b==0)
		{
			printf("0.0000000 0.0000000\n");
		}
		else if(a==0)
		{
			if (b>0)
			{
				printf("%.7lf 1.5707963 \n",b);
			}
			else
			{
				printf("%.7lf 4.7123890 \n",-b);
			}
		}
		else if(b==0)
		{
			if (a>0)
			{
				printf("%.7lf 0.0000000 \n",a);
			}
			else
			{
				printf("%.7lf 3.1415927 \n",-a);
			}
		}
		else
		{
			double r,s;
			r=sqrt(a*a+b*b);
			s=asin(b/r);
			if (a<0)
			{
				s=-s+3.1415926535897932;
			}
			else if (a>0&&b<0)
			{
				s=s+6.2831853071795864;
			}
			printf("%.7lf %.7lf \n",r,s);
		}
	}
 } 
