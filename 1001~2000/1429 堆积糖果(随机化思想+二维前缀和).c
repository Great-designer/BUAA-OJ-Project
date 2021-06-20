#include<stdio.h>
#include<time.h>
#include<stdlib.h>

long long map[1000010];
long long counter[1000010],a[1000010];

void write(long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

long long read()
{
	long long k=0;
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

long long n,m,t,tmpint;
long long x1,y1,x2,y2,v;

int main()
{
	n=read();
	m=read();
	t=read();
	int i;
	srand(time(0));
	for(i=n*m;i>0;--i)
	{
		map[i]=(rand()*1ll<<24ll)^(rand()<<8ll)^(rand()%(1ll<<8));
	}
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=m;++j)
		{
			tmpint=read();
			a[i*m+j]=map[tmpint];
		}
	}
	while(t--)
	{
		x1=read();
		y1=read();
		x2=read();
		y2=read();
		v=read();
		++x2;
		++y2;
		long long w=map[v];
		counter[x1*m+y1]+=w;
		counter[x1*m+y2]-=w;
		counter[x2*m+y1]-=w;
		counter[x2*m+y2]+=w;
	}
	long long res=0;
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=m;++j)
		{
			counter[i*m+j]+=counter[(i-1)*m+j]+counter[i*m+j-1]-counter[(i-1)*m+j-1];
			res+=(counter[i*m+j]%a[i*m+j])!=0;
		}
	}
	write(res);
}
