#include<stdio.h>
#include<string.h>

#include<algorithm>
#include<stack>

using namespace std;

void write(long long x)
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

int n;
int a[1000010],left[1000010],right[1000010],same[1000010];
long long ans;

stack<int>s;

int main()
{
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(same,0,sizeof(same));
		int i;
		for(i=0;i<n;++i)
		{
			a[i]=read();
		}
		rotate(a,max_element(a,a+n),a+n);
		a[n]=a[0];
		while(!s.empty())
		{
			s.pop();
		}
		s.push(0);
		left[0]=-1;
		for(i=1;i<n;++i)
		{
			while(!s.empty()&&a[s.top()]<=a[i])
			{
				if(a[s.top()]==a[i])
				{
					same[i]=same[s.top()]+1;
				}
				s.pop();
			}
			if(s.empty())
			{
				left[i]=-1;
			}
			else
			{
				left[i]=s.top();
			}
			s.push(i);
		}
		while(!s.empty())
		{
			s.pop();
		}
		s.push(n);
		right[n]=n;
		for(i=n-1;i>=1;--i)
		{
			while(!s.empty()&&a[s.top()]<=a[i])
			{
				s.pop();
			}
			if(s.empty())
			{
				right[i]=n+1;
			}
			else
			{
				right[i]=s.top();
			}
			s.push(i);
		}
		ans=0;
		for(i=1;i<n;++i)
		{
			if(left[i]!=-1)
			{
				++ans;
			}
			if(right[i]!=n+1)
			{
				++ans;
			}
			if(left[i]==0&&right[i]==n)
			{
				--ans;
			}
			ans+=same[i];
		}
		write(ans);
		putchar('\n');
	}
}
