#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int Size;
unsigned long long target[1005000];

void build()
{
	target[Size++]=1;
	unsigned long long pre,now,nownow;
	double test;
	unsigned long long i;
	for(i=2;i<=1000000;++i)
	{
		pre=i;
		now=i*i*i;
		target[Size++]=now;
		test=(2*log(i)+log(now))/log(2);
		while(test<60.0)
		{
			nownow=i*i*now-pre;
			pre=now;
			now=nownow;
			if(now<=1000000000000000000LL)
			{
				target[Size++]=now;
			}
			test=(2*log(i)+log(now))/log(2);
		}
	}
	sort(target,target+Size);
}

unsigned long long t,n;

int main()
{
	build();
	while(~scanf("%llu",&t))
	{
		while(t--)
		{
			scanf("%llu",&n);
			unsigned long long* pos=lower_bound(target,target+Size,n);
			if(n==target[pos-target])
			{
				printf("%llu",pos-target+1);
			}
			else
			{
				printf("%llu",pos-target);
			}
			putchar('\n');
		}
	}
}
