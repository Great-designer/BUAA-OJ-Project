#include<stdio.h>
#include<math.h>

int main()
{
	long long s;
	int t;
	double m,n,n1;
	double bxm,bxn;
	scanf("%lld%lf%lf%d",&s,&m,&n,&t);
	n1=pow((100+n)/100.0,4);//将季利率转换为年利率
	bxm=s*pow((1+m/100.0),t);
	bxn=s*pow(n1,t);
	if((m/100.0+1>n1-1e-8)&&(m/100.0+1<n1+1e-8))
	{
		printf("%.2f\n%.2f\n",bxm,bxm);
		printf("Whatever\n");
	}
	else if(m/100.0+1>=n1+1e-8)
	{
		printf("%.2f\n%.2f\n",bxm,bxn);
		printf("51Mole!!\n");
	}
	else if(m/100.0+1<=n1-1e-8)
	{
		printf("%.2f\n%.2f\n",bxm,bxn);
		printf("51Seer!!\n");
	}
	return 0;
}