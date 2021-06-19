#include<stdio.h>

int main()
{
	int a,b,c,d,i,max=1,ans1,ans2;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	ans1=a*d+c*b;
	ans2=b*d;
	for(i=2; i<=ans1&&i<=ans2; i++)
	{
		if(ans1%i==0&&ans2%i==0&&i>max) max=i;
	}
	ans1/=max;
	ans2/=max;
	printf("%d/%d",ans1,ans2);
	return 0;
}