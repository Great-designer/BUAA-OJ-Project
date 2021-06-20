#include<stdio.h>
#include<limits.h>

int lo=INT_MAX,hi,mi;
int n,m,w;

void write(int x)
{
	if(x>9)
	{
		write(x/10);
	} 
	putchar(x%10+48);
}

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

int a[100010];
int s[100010],f[100010];
char flag;

int binSearch(int lo,int hi)
{
	if(lo>hi)
	{
		return -1;
	} 
	int mi=(lo+hi)>>1;
	s[0]=0;
	int i; 
	for(i=1;i<=n;++i)
	{
		f[i]=mi-a[i];
	}
	int k=0;
	flag=1;
	long long req=0;
	for(i=1;i<=n;++i)
	{
		if(f[i]<=0)
		{
			s[i]=s[i-1];
			continue;
		}
		if(i-w>=0)
		{
			req=s[i-1]-s[i-w];
		}
		else
		{
			req=s[i-1];
		}
		if(f[i]>req)
		{
			k+=f[i]-req;
			s[i]=s[i-1]+f[i]-req;
		}
		else
		{
			s[i]=s[i-1];
		} 
		if(k>m)
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		int subline=binSearch(mi+1,hi);
		if(subline>mi)
		{
			return subline;
		} 
		else
		{
			return mi;
		} 
	}
	else
	{
		return binSearch(lo,mi-1);
	}
}

int main()
{
	n=read();
	m=read();
	w=read();
	int i;
	for(i=1;i<=n;++i)
	{
		a[i]=read();
		lo=lo<a[i]?lo:a[i];
		hi=hi>(a[i]+m)?hi:(a[i]+m);
	}
	write(binSearch(lo,hi));
}

