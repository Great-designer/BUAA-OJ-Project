#include<stdio.h>
#include<string.h>

int read()
{
    int k=0,f=1;
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
    return k*f;
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

int t;
int n,m;
int op,x,y;
int f[200010],dis[200010];
int ans;

void initFather()
{
	int i;
    for(i=1;i<=n;++i)
	{
		f[i]=i;
		dis[i]=0;
	}
}

int getFather(int x)
{
    if(x==f[x])
	{
		return x;
	}
    getFather(f[x]);
    dis[x]+=dis[f[x]];
    f[x]=f[f[x]];
    return f[x];
}

char check(int x,int y)
{
    int a=getFather(x);
    int b=getFather(y);
    if(a!=b)
	{
		return 0;
	}
    else
	{
		return 1;
	}
}

void merge(int x,int y)
{
    int a=getFather(x);
    int b=getFather(y);
    if(a!=b)
	{
		f[a]=b;
		dis[a]=dis[x]+dis[y]+1;
	}
    else if(ans>dis[x]+dis[y])
	{
		ans=dis[x]+dis[y];
	}
}

int main()
{
    n=read();
    initFather();
    ans=1919810;
    int i;
    for(i=1;i<=n;++i)
	{
        x=i;
		y=read();
        merge(x,y);
    }
    write(ans+1);
}
