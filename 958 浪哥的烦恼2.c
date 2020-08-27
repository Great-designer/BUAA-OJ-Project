#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void*p1,const void*p2)
{
	return *(long long*)p2>*(long long*)p1?1:-1;
}

void write(int x)
{
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}

long long read()
{
    long long k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9')
	{
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
	{
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}

long long t,n,m;
char f[1000010];
long long d[2010];
long long sum;
int ans;

void buildDP_FullPack(long long cost)
{
	int i;
    for(i = cost; i <= m - sum; i+=2)
    {
    	f[i] = f[i] || f[i - cost];
	}
}

int main()
{
    t = read();
    while(t--)
	{
        ans = 0, sum = 0;
        n = read(), m = read();
        memset(f,0,sizeof(f));
        int i;
        for(i = 1; i < n; ++i)
        {
        	d[i]=read(),sum+=d[i];
		}
        if(sum>m)
		{
			putchar('0'),putchar('\n');
			continue;
		}
        f[0] = 1;
        qsort(d+1,n-1,sizeof(long long),compare);
        for(i = 1; i < n; ++i)
		{
            if(f[d[i]<<1])continue;
            buildDP_FullPack(d[i]<<1);
        }
        for(i=0; i<=m-sum; ++i)
		{
			ans+=f[i];
		}
        write(ans),putchar('\n');
    }
}
