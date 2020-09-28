#include<stdio.h>
#include<string.h>

struct App
{
	int status;
	int appid;
};

struct App app[300010];

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

int n,q;
int res,time;
int readTime;
int type,op;

int main()
{
	while(~scanf("%d%d",&n,&q))
	{
		res=0,time=0;
		memset(app,0,sizeof(app));
		readTime=0;
		int i;
		for(i=0;i<q;++i)
		{
			type=read(),op=read();
			if(type==1)
			{
				app[time].appid=op;
				app[time++].status=1;
				res++;
			}
			else if(type==2)
			{
				int j;
				for(j=readTime;j<time;++j)
				{
					if(app[j].appid==op)
					{
						if(app[j].status==1)
						{
							app[j].status=2;
							res--;
						}
					}
				}
			}
			else
			{
				int j;
				for(j=readTime;j<op;++j)
				{
					if(app[j].status==1)
					{
						app[j].status=2;
						res--;
					}
				}
				if(op>readTime)
				{
					readTime=op;
				}
			}
			write(res);
			putchar('\n');
		}
	}
}
