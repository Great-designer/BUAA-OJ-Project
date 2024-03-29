#include<stdio.h>
#include<string.h>

long long a[530];
char part[530];//p[i]为是否在i后面划分界限
long long n,k;
long long hi,lo,mi;//初始lo是数组最大值 hi是总和
long long ans;

char judge(long long x)
{
	long long flag = 0, cnt = 1;
	for(long long i = 1; i <= n; ++i)
	{
		if(flag+a[i]>x)cnt++,flag=a[i];
		else flag+=a[i];
	}
	return cnt <= k;
}

void print()
{
	//给定了ans和k之后，直接print即可
	//因为要尽可能靠前划分,所以倒着贪心 从后往前划分区间 同时注意划分区间个数
	long long remain = k, flag = 0;
	for(long long i = n; i; --i)
	{
		if(remain>i)part[i]=1,remain--;//如果区间数不够了,必须一个数一个区间
		else if (a[i]+flag>ans)part[i]=1,remain--,flag=a[i];
		else flag+=a[i];
	}
	printf("%lld",a[1]);//这个原封不动
	if(part[1])printf(" \\");
	for(int i = 2; i <= n; ++i)
	{
		printf(" %lld",a[i]);
		if(part[i])printf(" \\");
	}
	putchar('\n');
}

long long t;

int main()
{
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		lo = hi = 0;
		memset(part,0,sizeof(part));
		for(int i = 1; i <= n; ++i)
		{
			scanf("%lld",a+i);
			hi+=a[i];
			if(a[i]>lo)lo=a[i];
		}
		while(hi > lo)
		{
			mi = (hi+lo)>>1;
			if(judge(mi))hi=mi;
			else lo=mi+1;
		}
		ans = lo;//得到答案没问题
		print();
	}
}
