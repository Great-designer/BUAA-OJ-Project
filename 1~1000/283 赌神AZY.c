#include<stdio.h>

int n;
int m;
int op;
int opA,opB;
int position[1000020];
long long result;

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

void write(long long x)
{
	if(x>=10)
	{
		write(x/10);
	} 
	putchar(x%10+48);
}

void initlist()
{
	int i;
	for(i=1;i<=n;++i)
	{
		position[i]=i;
	}
}

void additself(int lo,int hi)
{
	int i;
	for(i=1;i<=n;++i)
	{
		if(position[i]>=lo&&position[i]<=hi)
		{
			++position[i];
		}
	}
}

void minusitself(int lo,int hi)
{
	int i;
	for(i=1;i<=n;++i)
	{
		if(position[i]>=lo&&position[i]<=hi)
		{
			--position[i];
		}
	}
}

void moveleft(int fromx,int toy)
{
	int originalx=position[fromx];
	int newx;
	if(position[fromx]<position[toy])
	{
		newx=position[toy]-1;
		minusitself(originalx+1,newx);
		position[fromx]=newx;
	}
	else
	{
		newx=position[toy];
		additself(newx,originalx-1);
		position[fromx]=newx;
	}
}

void moveright(int fromx,int toy)
{
	int originalx=position[fromx];
	int newx;
	if(position[fromx]<position[toy])
	{
		newx=position[toy];
		minusitself(originalx+1,newx);
		position[fromx]=newx;
	}
	else
	{
		newx=position[toy]+1;
		additself(newx,originalx-1);
		position[fromx]=newx;
	}
}

void swap(int fromx,int toy)
{
	int tmp=position[fromx];
	position[fromx]=position[toy];
	position[toy]=tmp;
}

void reverse()
{
	int i;
	for(i=1;i<=n;++i)
	{
		position[i]=n+1-position[i];
	}
}

void printtab()
{
	int i;
	for(i=1;i<=n;++i)
	{
		write((long long)position[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main()
{
	while(~scanf("%d",&n))
	{
		initlist();
		m=read();
		int i;
		for(i=0;i<m;++i)
		{
			op=read();
			if(op==1)
			{
				opA=read();
				opB=read();
				moveleft(opA,opB);
			}
			else if(op==2)
			{
				opA=read();
				opB=read();
				moveright(opA,opB);
			}
			else if(op==3)
			{
				opA=read();
				opB=read();
				swap(opA,opB);
			}
			else
			{
				reverse();
			}
		}
		result=0;
		for(i=1;i<=n;++i)
		{
			if(position[i]%2)
			{
				result+=i;
			}
		}
		write(result);
		putchar('\n');
	}
}

