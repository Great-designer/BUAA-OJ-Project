#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long m,n;
int tmp;

long long a(long long m,long long n)
{
	long long ret=m<<(2+n);
	if(ret>=2000ll)
	{
		if(n<=5)
		{
			return 2000;
		}
		else if(n<=7)
		{
			return 3000;
		}
		else if(n<=10)
		{
			return 4000;
		}
		else if(n<=12)
		{
			return 6000;
		}
		else
		{
			return 8000;
		}
	}
	else
	{
		return ret;
	}
}

long long child(long long m,long long n)
{
	long long ret=a(m,n);
	long long ret2=(ret/100)*100;
	if(ret!=ret2)
	{
		return ret2+100;
	}
	else
	{
		return ret;
	}
}

long long parent(long long m,long long n)
{
	long long ret=a(m,n)<<1;
	long long ret2=(ret/100)*100;
	if(ret!=ret2)
	{
		return ret2+100;
	}
	else
	{
		return ret;
	}
}

struct player
{
	int id;
	int score;
	char isWang;
};

int compare(const void*p1,const void*p2)
{
	struct player*o=(struct player*)p1;
	struct player*a=(struct player*)p2;
	if(a->score!=o->score)
	{
		return a->score>o->score;
	}
	else
	{
		return a->id>o->id;
	}
}

struct player origin[10],Tmp[10];
int Wang;

char judge(long long m,long long n)
{
	int i; 
	for(i=1;i<=4;++i)
	{
		Tmp[i]=origin[i];
	}
	long long a=child(m,n);
	long long a2=parent(m,n);
	if (Tmp[Wang].id!=1)
	{
		for(i=1;i<=4;++i)
		{
			if(i==Wang)
			{
				continue;
			}
			if(Tmp[i].id==1)
			{
				Tmp[i].score-=a2;
				Tmp[Wang].score+=a2;
			}
			else
			{
				Tmp[i].score-=a;
				Tmp[Wang].score+=a;
			}
		}
	}
	else
	{
		for(i=1;i<=4;++i)
		{
			if(i==Wang)
			{
				continue;
			}
			Tmp[i].score-=a2;
			Tmp[Wang].score+=a2;
		}
	}
	qsort(Tmp+1,4,sizeof(struct player),compare);
	return !Tmp[4].isWang;
}

int main()
{
	while(~scanf("%d",&tmp))
	{
		memset(origin,0,sizeof(origin));
		origin[1].score=tmp;
		int i;
		for(i=2;i<=4;++i)
		{
			scanf("%d",&origin[i].score);
		}
		origin[1].id=1;
		origin[2].id=4;
		origin[3].id=3;
		origin[4].id=2;
		scanf("%d",&Wang);
		origin[Wang].isWang=1;
		scanf("%lld",&m);
		long long lo=1,hi=30,mi;
		if(m==20)
		{
			lo=2;
		}
		if(m==25)
		{
			lo=3;
		}
		if(!judge(m,hi))
		{
			puts("Impossible");
		}
		else
		{
			while(hi>lo)
			{
				mi=(hi+lo)>>1;
				if(judge(m,mi))
				{
					hi=mi;
				}
				else
				{
					lo=mi+1;
				}
			}
			printf("%lld\n",lo);
		}
	}
}
