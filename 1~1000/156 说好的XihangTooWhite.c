#include<stdio.h>
#include<ctype.h>

int n,m;

int trans(char c)
{
	return (isdigit(c)?(c-'0'):(c-'a'+10));
}

char read()
{
	int i,j,k;
	char c=getchar();
	while(!isalnum(c))
	{
		c=getchar();
	}
	i=trans(c);
	c=getchar();
	i=(i<<4)+trans(c);
	c=getchar();
	j=trans(c);
	c=getchar();
	j=(j<<4)+trans(c);
	c=getchar();
	k=trans(c);
	c=getchar();
	k=(k<<4)+trans(c);
    getchar();
	return (i+j+k)<m;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		m+=(m<<1);
		int i;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				putchar(read()+48);
				putchar(' ');
			}
			putchar('\n');
		}
		putchar('\n');
	}
}
