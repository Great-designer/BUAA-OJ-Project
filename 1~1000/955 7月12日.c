#include<stdio.h>

const int w[7]={1,10,100,1000,10000,100000,1000000};

int getsubnum(int target,int lo,int hi)
{
    return ((target%w[hi])-(lo==1?0:target%w[lo-1]))/w[lo-1];
}

int decbit(int target)
{
	int i;
    for(i=0;i<7;++i)
    {
    	if(target<w[i])
    	{
    		return i;
		}
	}
    return 7;
}

char isEva(int target)
{
    if(target==0)
	{
		return 0;
	}
    int maxbit=decbit(target);
    int i;
    for(i=1;i<=maxbit;++i)
	{
		int j;
        for(j=i;j<=maxbit;++j)
		{
            int flag=getsubnum(target,i,j);
            if((!(flag%7))||(!(flag%12)))
            {
            	return 0;
			}
        }
    }
    return 1;
}

int dp[1000010];

void buildDP()
{
    dp[0]=0;
    int i;
    for(i=1;i<=999999;++i)
    {
    	dp[i]=dp[i-1]+isEva(i);
	}
}

void write(int x)
{
    if(x<0)
	{
		putchar('-');
		x=-x;
	}
    if(x>9)
	{
		write(x/10);
	}
    putchar(x%10+48);
}

long long read()
{
    long long k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        if(c=='-')
		{
			f=-1;
		}
        c=getchar();
    }
    while(c>='0'&&c<='9')
	{
        k=(k<<1)+(k<<3)+c-48;
        c=getchar();
    }
    return f==1?k:-k;
}

long long t,n;

int main()
{
    buildDP();
    t=read();
    while(t--)
	{
        n=read();
        write(dp[n>=1000000?999999:n]);
        putchar('\n');
    }
}
