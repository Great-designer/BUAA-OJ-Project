#include<stdio.h>
#include<string.h>

int n,m;
char instr[5];
int opnum;

int curstack[20010];
int curtop;
int maxstack[20010];
int maxtop;

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

int main()
{
	n=read();
	m=read();
	curtop=0;
	maxtop=0;
	maxstack[maxtop]=0;
	maxtop++;
	while(m--)
	{
		scanf("%s",instr);
		if(!strcmp(instr,"push"))
		{
			opnum=read();
			if(curtop==n)
			{
				puts("Error");
			}
			else
			{
				curstack[curtop]=opnum;
				curtop++;
				maxstack[maxtop]=(opnum>maxstack[maxtop-1]?opnum:maxstack[maxtop-1]);
				maxtop++;
			}
		}
		else if(!strcmp(instr,"pop"))
		{
			if(curtop==0)
			{
				puts("Error");
			}
			else
			{
				curtop--;
				maxtop--;
			}
		}
		else if(!strcmp(instr,"top"))
		{
			if(curtop==0)
			{
				puts("Error");
			}
			else
			{
				printf("%d\n",curstack[curtop-1]);
			}
		}
		else if(!strcmp(instr,"max"))
		{
			if(curtop==0)
			{
				puts("Error");
			}
			else
			{
				printf("%d\n",maxstack[maxtop-1]);
			}
		}
	}
}

