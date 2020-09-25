#include<stdio.h>
#include<string.h>

int occurhang[25],occurlie[25];
int occurzuoxie[50];
int occuryouxie[50];

void init()
{
	memset(occurhang,0,sizeof(occurhang));
	memset(occurlie,0,sizeof(occurlie));
	memset(occuryouxie,0,sizeof(occuryouxie));
	memset(occurzuoxie,0,sizeof(occurzuoxie));
}

int n;
char map[25][25];

int main()
{
	while(~scanf("%d",&n))
	{
		init();
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%s",map[i]+1);
		}
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				if(map[i][j]=='1')
				{
					occurhang[i]++;
					occurlie[j]++;
					occuryouxie[i-j+n]++;
					occurzuoxie[i+j]++;
				}
			}
		}
		char flag=1;
		for(i=1;i<=n;++i)
		{
			flag=flag&&(occurhang[i]==1);
			flag=flag&&(occurlie[i]==1);
		}
		for(i=1;i<=2*n-1;++i)
		{
			flag=flag&&(occuryouxie[i]<=1);
			flag=flag&&(occurzuoxie[i+1]<=1);
		}
		if(flag)
		{
			puts("Move Forward!");
		}
		else
		{
			puts("Bad End!");
		}
	}
}
