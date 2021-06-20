#include<stdio.h>
#include<math.h>

int x,y,a,b;

int main(void)
{
	scanf("%d%d%d%d",&x,&y,&a,&b);
	double ans=x+a-sqrt(0.5)*a;
	printf("%.5f\n",ans);
	return 0;
}