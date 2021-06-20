#include<iostream>

using namespace std;

string a,b,c;
string words;
char hashlist[256],used[27];
char finish;
int n;
int stack[27];

int ans[27];

void addChar(int ch)
{
	if(!hashlist[ch])
	{
		hashlist[ch]=1;
		words+=(char)ch;
	}
}

string change(string str,char x,char y)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(str[i]==x)
		{
			str[i]=y;
		}
	}
	return str;
}

char bad()
{
	int p,g=0;
	int i;
	for(i=n-1;i>=0;--i)
	{
		if(a[i]>=n||b[i]>=n||c[i]>=n)
		{
			return 0;
		}
		p=a[i]+b[i]+g;
		if(p%n!=c[i])
		{
			return 1;
		}
		g=p/n;
	}
	return 0;
}

char checkMod()
{
	int p,p1,p2;
	int i;
	for(i=n-1;i>=0;--i)
	{
		if(a[i]>=n||b[i]>=n||c[i]>=n)
		{
			continue;
		}
		p=(a[i]+b[i])%n;
		if(!(p%n==c[i]||(p+1)%n==c[i]))
		{
			return 1;
		}
	}
	for(i=n-1;i>=0;--i)
	{
		if(!(a[i]<n&&b[i]>=n&&c[i]<n))
		{
			continue;
		}
		p1=(c[i]-a[i]+n)%n;
		p2=(c[i]-a[i]-1+n)%n;
		if(used[p1]&&used[p2])
		{
			return 1;
		}
	}
	for(i=n-1;i>=0;--i)
	{
		if(!(a[i]>=n&&b[i]<n&&c[i]<n))
		{
			continue;
		}
		p1=(c[i]-b[i]+n)%n;
		p2=(c[i]-b[i]-1+n)%n;
		if(used[p1]&&used[p2])
		{
			return 1;
		}
	}
	for(i=n-1;i>=0;--i)
	{
		if(!(a[i]<n&&b[i]<n&&c[i]>=n))
		{
			continue;
		}
		p1=(a[i]+b[i])%n;
		p2=(a[i]+b[i]+1)%n;
		if(used[p1]&&used[p2])
		{
			return 1;
		}
	}
	return 0;
}

void outputResult()
{
	int i;
	for(i=0;i<n;++i)
	{
		ans[words[i]-65]=stack[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",ans[i]);
	}
	finish=1;
}

void dfs(int level)
{
	int i;
	string tmpA,tmpB,tmpC;
	if(finish||bad()||checkMod())
	{
		return;
	}
	if(level==n)
	{
		outputResult();
		return;
	}
	for(i=n-1;i>=0;--i)
	{
		if(!used[i])
		{
			used[i]=1;
			tmpA=a;
			a=change(tmpA,words[level],i);
			tmpB=b;
			b=change(tmpB,words[level],i);
			tmpC=c;
			c=change(tmpC,words[level],i);
			stack[level]=i;
			dfs(level+1);
			used[i]=0;
			a=tmpA;
			b=tmpB;
			c=tmpC;
		}
	}
}

int main()
{
	scanf("%d",&n);
	cin >> a >> b >> c;
	words="";
	int i;
	for(i=n-1;i>=0;--i)
	{
		addChar(a[i]);
		addChar(b[i]);
		addChar(c[i]);
	}
	dfs(0);
	return 0;
}
