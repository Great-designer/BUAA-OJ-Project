#include<stdio.h>
#include<string.h>

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

int a[50000];
int n,t;

int main()
{
	while(~scanf("%d%d",&n,&t))
	{
		memset(a,0,sizeof(a));
		int i;
		for(i=1;i<n;++i)
		{
			a[i]=read();
		}
		int t1=a[1];
		int j=1;
		int ans=0;
		char flag=0;
		while(ans<n)
		{
			ans=t1+j;
			if(ans>n)
			{
				break;
			}
			j=ans;
			t1=a[ans];
			if(ans==t)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
}

