#include<stdio.h>
#include<string.h>

char chessmap[40][40];
char t;
int n;
char result;
char cache[40];

void find()
{
	int i;
	for(i=1;i<n-3;++i)
	{
		int j;
		for(j=1;j<=n;++j)
		{
			char win=1;
			int p;
			for(p=0;p<5;++p)
			{
				if(chessmap[i+p][j]!=t)
				{
					win=0;
				}
			}
			if(win)
			{
				result=1;
				return;
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<n-3;++j)
		{
			char win=1;
			int p;
			for(p=0;p<5;++p)
			{
				if(chessmap[i][j+p]!=t)
				{
					win=0;
				}
			}
			if(win)
			{
				result=1;
				return;
			}
		}
	}
	for(i=1;i<n-3;++i)
	{
		int j;
		for(j=1;j<n-3;++j)
		{
			char win=1;
			int p;
			for(p=0;p<5;++p)
			{
				if(chessmap[i+p][j+p]!=t)
				{
					win=0;
				}
			}
			if(win)
			{
				result=1;
				return;
			}
		}
	}
	for(i=5;i<=n;++i)
	{
		int j;
		for(j=0;j<n-3;++j)
		{
			char win=1;
			int p;
			for(p=0;p<5;++p)
			{
				if(chessmap[i-p][j+p]!=t)
				{
					win=0;
				}
			}
			if(win)
			{
				result=1;
				return;
			}
		}
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		memset(chessmap,0,sizeof(chessmap));
		result=0;
		scanf("%s",cache);
		getchar();
		getchar();
		t=cache[0];
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%[^\r\n]",cache);
			getchar();
			getchar();
			int j;
			for(j=1;j<=n;++j)
			{
				chessmap[i][j]=cache[j-1];
			} 
		}
		for(i=1;i<=n&&result!=1;++i)
		{
			int j;
			for(j=1;j<=n&&result!=1;++j)
			{
				if(chessmap[i][j]=='+')
				{
					chessmap[i][j]=t;
					find();
					chessmap[i][j]='+';
				}
			}
		}
		printf("%s\n",result?"YES":"NO");
	}
}
