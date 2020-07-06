#include<stdio.h>
#include<string.h>

char a[510][510];

struct counter
{
	long long mark[10];
};

struct counter List[510][510];

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

void write(int x)
{
	if(x>9)
	{
		write(x/10);
	} 
	putchar(x%10+48);
}

int m,n,t;
int x1,y1,x2,y2;

void copySheetFromTo(int fromi,int fromj,int toi,int toj)
{
	int i;
	for(i=0;i<10;++i)
	{
		List[toi][toj].mark[i]=List[fromi][fromj].mark[i];
	}
}

void updateSheet(int i,int j)
{
	if(i==1&&j==1)
	{
		List[1][1].mark[a[1][1]]++;
	} 
	else if(i == 1)
	{
		copySheetFromTo(1,j-1,1,j);
		List[1][j].mark[a[1][j]]++;
	}
	else
	{
		copySheetFromTo(i-1,j,i,j);
		int k;
		for(k=1;k<=j;++k)
		{
			List[i][j].mark[a[i][k]]++;
		} 
	}
}

int main()
{
	while(~scanf("%d%d%d",&m,&n,&t))
	{
		memset(List,0,sizeof(List));
		memset(a,0,sizeof(a));
		int i;
		for(i=1;i<=m;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				a[i][j]=read();
				updateSheet(i,j);
			}
		}
		while(t--)
		{
			x1=read();
			y1=read();
			x2=read();
			y2=read();
			long long tmp[10]={0,0,0,0,0,0,0,0,0,0};
			int i;
			for(i=0;i<10;++i)
			{
				tmp[i]=List[x2][y2].mark[i]-List[x1-1][y2].mark[i]-List[x2][y1-1].mark[i]+List[x1-1][y1-1].mark[i];
			}
			char result=0;
			for(i=0;i<10;++i)
			{
				if(tmp[i]!=0)
				{
					result++;
				} 
			} 
			if(result<10)
			{
				putchar(result+48);
			} 
			else
			{
				putchar('1');
				putchar('0');
			}
			putchar('\n');
		}
		memset(List,0,sizeof(List));
		memset(a,0,sizeof(a));
	}
}
