#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Size;
unsigned long long target[1005000];

int lower(const void *p1,const void *p2)
{
	unsigned long long *a=(unsigned long long *)p1;
	unsigned long long *b=(unsigned long long *)p2;
	if(b!=target&&*a<=*(b-1))
	{
		return -1;
	}
	else if((b==target||*a>*(b-1))&&*a>*b)
	{
		return 1;
	}
	else if((b==target||*a>*(b-1))&&*a<=*b)
	{
		return 0;
	}
}

int compare(const void *p1,const void *p2)
{
	unsigned long long *a=(unsigned long long *)p1;
	unsigned long long *b=(unsigned long long *)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void build()
{
	target[Size++]=1;
	unsigned long long pre,now,nownow;
	double test;
	unsigned long long i;
	for(i=2; i<=1000000; ++i)
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
	qsort(target,Size,sizeof(unsigned long long),compare);
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
			unsigned long long *pos=bsearch(&n,target,Size,sizeof(unsigned long long),lower);
			if(pos==NULL)
			{
				pos=target+Size;
			}
			if(n==target[pos-target])
			{
				printf("%llu\n",pos-target+1);
			}
			else
			{
				printf("%llu\n",pos-target);
			}
		}
	}
}
