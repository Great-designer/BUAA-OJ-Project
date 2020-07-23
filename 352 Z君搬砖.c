#include<stdio.h>

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
	return k * f;
}

char readOP()
{
	char c=getchar();
	while(c!='M'&&c!='C')
	{
		c=getchar();
	}
	return c=='M';
}

char op;
int x,y;
int m;
int f[3000010],cnt[3000010],size[3000010];

void init()
{
	int i;
	for(i=1;i<3000010;++i)
	{
		f[i]=i;
		cnt[i]=0;
		size[i]=1;
	}
}

int find(int x)
{
	if(x==f[x])
	{
		return x;
	}
	int tmp=f[x];
	f[x]=find(f[x]);
	cnt[x]+=cnt[tmp];
	return f[x];
}

void Union(int x,int y)
{
	f[x]=y;
	cnt[x]+=size[y];
	size[y]+=size[x];
}

int main()
{
	m=read();
	init();
	while(m--)
	{
		if(readOP())
		{
			x=read();
			y=read();
			int px=find(x);
			int py=find(y);
			if(px!=py)
			{
				Union(px,py);
			}
		}
		else
		{
			x=read();
			find(x);
			write(cnt[x]);
			putchar('\n');
		}
	}
}
