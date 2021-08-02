#include<stdio.h>
#include<math.h>

long long n,maxv,s,t,n,mm;

int main()
{
	scanf("%lld",&maxv);
	mm=(maxv-1)*2;//电梯上下一个周期的时间
	scanf("%lld %lld %lld",&s,&t,&n);
	if(s==t)
	{
		printf("%lld\n",n);//小迷弟那都不用去直接到包房
	}
	else
	{
		long long tmp1,tmp2;
		if(s<t)
		{
			tmp1=s-1;//电梯从1楼向上接到小迷弟
		}
		else
		{
			tmp1=mm+1-s;//电梯从maxv层向下接到小迷弟
		}
		long long tmp3=n/mm*mm+tmp1;//n秒之前电梯跑过n/mm*mm次轮回 又花了tmp1的时间接小迷弟
		if(tmp3<n)
		{
			tmp2=tmp3+mm;//但是仍有可能小于n 如果小于n必须加个周期才能保证在小迷弟出现之后接到小迷弟
		}
		else
		{
			tmp2=tmp3;
		}
		printf("%lld\n",tmp2+llabs(s-t));//再走两者的距离
	}
	return 0;
}