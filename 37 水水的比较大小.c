#include<stdio.h>
#include<math.h>

int main()
{
    double a,b;
    while(scanf("%lf%lf",&a,&b)==2)
	{
        if(fabs(a-b)<=1e-8)
		{
			printf("nakezhenchun\n");
		}
        else if(a>b)
		{
			printf("woshibukezhanshengde\n");
		}
        else
		{
			printf("wohenbaoqian\n");
		}
    }
}

