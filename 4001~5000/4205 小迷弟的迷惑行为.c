#include<stdio.h>
#include<math.h>

int main()
{
	double x,y;
	scanf("%lf%lf",&x,&y);
	long long ans=(long long)(log(y)/log(x)+1e-8);//eps设为1e-8可以更小但不能过小
	printf("%lld\n",ans);
}