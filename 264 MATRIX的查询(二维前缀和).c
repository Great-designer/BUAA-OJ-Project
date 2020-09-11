#include<stdio.h>
#include<string.h>

int read()
{
    int k=0;
    char c=getchar();
    while(c<'0'||c>'9')
	{
        c=getchar();
    }
    while(c>='0'&&c<='9')
	{
        k=(k<<1)+(k<<3)+c-48;
        c=getchar();
    }
    return k;
}

void write(int x)
{
    if(x>9)
	{
		write(x/10);
	}
    putchar(x%10+48);
}

int a[510][510];

struct counter
{
    int mark[10];
};

struct counter plus(struct counter a,struct counter o)
{
    struct counter ret;
    memset(ret.mark,0,sizeof(ret.mark));
    int i;
    for(i=0;i<=9;++i)
    {
    	ret.mark[i]=a.mark[i]+o.mark[i];
	}
	return ret;
}

struct counter minus(struct counter a,struct counter o)
{
	struct counter ret;
    memset(ret.mark,0,sizeof(ret.mark));
    int i;
    for(i=0;i<=9;++i)
    {
    	ret.mark[i]=a.mark[i]-o.mark[i];
	}
    return ret;
}

struct counter count(int x)
{
    struct counter ret;
    memset(ret.mark,0,sizeof(ret.mark));
    ret.mark[x]=1;
    return ret;
}

int query(struct counter a)
{
    int ret=0;
    int i;
    for(i=0;i<=9;++i)
    {
    	ret+=(a.mark[i]>0);
	}
	return ret;
}

struct counter sum[510][510];

int m,n,t;
int X1,Y1,X2,Y2;

int main()
{
    while(~scanf("%d%d%d",&m,&n,&t))
	{
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        int i; 
        for(i=1;i<=m;++i)
        {
        	int j;
        	for(j=1;j<=n;++j)
        	{
        		a[i][j]=read();
			} 
		}
        for(i=1;i<=m;++i)
        {
        	int j;
        	for(j=1;j<=n;++j)
        	{
        		struct counter temp1=plus(sum[i-1][j],sum[i][j-1]);
        		struct counter temp2=minus(count(a[i][j]),sum[i-1][j-1]);
        		sum[i][j]=plus(temp1,temp2);
			}
		}
        while(t--)
		{
            X1=read();
			Y1=read();
			X2=read();
			Y2=read();
			struct counter temp1=plus(sum[X2][Y2],sum[X1-1][Y1-1]);
        	struct counter temp2=plus(sum[X1-1][Y2],sum[X2][Y1-1]);
            struct counter ans=minus(temp1,temp2);
            write(query(ans));
			putchar('\n');
        }
    }
}
