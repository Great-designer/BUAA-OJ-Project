#include<stdio.h>
#include<math.h>

int main()
{
    double x,y,z,a,b,c,max,t;
	int n,i,k,maxi;
    while(scanf("%lf%lf%lf%d",&x,&y,&z,&n)==4)
	{
        max=0;
		maxi=1;
        for(i=0;i<n;i++)
		{
            scanf("%lf%lf%lf",&a,&b,&c);
            t=(a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z);
            if(t>max)
			{
				max=t;
				maxi=i+1;
			}
    	}
    	scanf("%d",&k);
		printf("%d %lf\n",maxi,k*2*sqrt(max));
    }
}

