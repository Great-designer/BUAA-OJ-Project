#include<stdio.h>
#include<math.h>

int n,l,L;

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&L,&l);
		if(3*l*l>=4*L*L)
		{
			puts("1.000000");
			continue;
		}
		double rad,pi=acos(-1),ans=0;
		if(l>L)
		{
			rad=asin(1.*L/l);
		}
		else
		{
			rad=pi/2;
		}
		ans+=pi/2-rad;
		ans+=(-cos(rad)+cos(pi/3))*l/L;
		ans/=(pi/6);
		printf("%.6f\n",ans);
	}
	return 0;
}
