#include<stdio.h>

#include<queue>

using namespace std;

deque<int> dmin;
deque<int> dmax;

int a[100010];
int top;

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
	return k*f;
}

int n,k;

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int i;
		for(i=1;i<=n;++i)
		{
			a[i]=read();
		}
		while(!dmin.empty())
		{
			dmin.pop_back();
		}
		for(i=1;i<=k;++i)
		{
			if(dmin.empty())
			{
				dmin.push_back(i);
			}
			else
			{
				while(!dmin.empty()&&a[dmin.back()]>a[i])
				{
					dmin.pop_back();
				}
				dmin.push_back(i);
			}
		}
		write(a[dmin.front()]);
		putchar(' ');
		for(i=k+1;i<=n;++i)
		{
			while(!dmin.empty()&&dmin.front()<=i-k)
			{
				dmin.pop_front();
			}
			if(dmin.empty())
			{
				dmin.push_back(i);
			}
			else
			{
				while(!dmin.empty()&&a[dmin.back()]>a[i])
				{
					dmin.pop_back();
				}
				dmin.push_back(i);
			}
			write(a[dmin.front()]);
			putchar(' ');
		}
		putchar('\n');
		while(!dmax.empty())
		{
			dmax.pop_back();
		}
		for(i=1;i<=k;++i)
		{
			if(dmax.empty())
			{
				dmax.push_back(i);
			}
			else
			{
				while(!dmax.empty()&&a[dmax.back()]<a[i])
				{
					dmax.pop_back();
				}
				dmax.push_back(i);
			}
		}
		write(a[dmax.front()]);
		putchar(' ');
		for(i=k+1;i<=n;++i)
		{
			while(!dmax.empty()&&dmax.front()<=i-k)
			{
				dmax.pop_front();
			}
			if(dmax.empty())
			{
				dmax.push_back(i);
			}
			else
			{
				while(!dmax.empty()&&a[dmax.back()]<a[i])
				{
					dmax.pop_back();
				}
				dmax.push_back(i);
			}
			write(a[dmax.front()]);
			putchar(' ');
		}
		putchar('\n');
	}
}

