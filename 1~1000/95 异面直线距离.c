#include<stdio.h>
#include<math.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		printf("%.5lf\n",x*y*z/sqrt(x*x*y*y+y*y*z*z+x*x*z*z));
	}
	return 0;	
}

