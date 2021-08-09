#include<stdio.h>
#include<stdlib.h>

void judge(long long a,long long b,long long c)
{
	if(a>0&&b>0&&c>0&&c<a+b&&c>llabs(a-b))
	{
		long long gx3a2=llabs(c*c-b*b);
		unsigned long long right=3*a*a;
		if(gx3a2<right)
		{
			printf("stable\n");
		}
		else if(gx3a2==right)
		{
			printf("almost stable\n");
		}
		else
		{
			printf("no way\n");
		}
	}
	else
	{
		printf("no way\n");
	}
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d:",a);
	judge(a,b,c);
	printf("%d:",b);
	judge(b,c,a);
	printf("%d:",c);
	judge(c,a,b);
}

