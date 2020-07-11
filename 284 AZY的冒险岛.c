#include<stdio.h>
#include<ctype.h>
#include<string.h>

int a[55];
int f[55];
int n,m;

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void init()
{
	f[1]=a[1];
	f[2]=max(a[1],a[2]);
	int i;
	for(i=3;i<=n;++i)
	{
		f[i]=max(f[i-1],f[i-2]+a[i]);
	}
}

void erase()
{
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
}

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		init();
		scanf("%d",&m);
		printf("%s\n",(f[n]<m)?"Poor AZY!":"AZY is back, baby!");
		erase();
	}
}
