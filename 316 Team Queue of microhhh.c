#include<stdio.h>
#include<string.h>
#include<ctype.h>

int s[1010][1010];
int sfront[1010];
int srear[1010];
int ss[1010];
int ssfront;
int ssrear;

int team[1000010];
int scenario;
char instr[10];

void init()
{
	memset(team,0,sizeof(team));
	memset(sfront,0,sizeof(sfront));
	memset(srear,0,sizeof(srear));
	ssfront=0;
	ssrear=0;
}

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

void getInstr()
{
	int i=0;
	char c=getchar();
	while(!isalpha(c))
	{
		c=getchar();
	}
	while(isalpha(c))
	{
		instr[i++]=c;
		c=getchar();
	}
}

int n,qsize,tmp;

int main()
{
	while((n=read())&&n)
	{
		init();
		int i;
		for(i=1;i<=n;++i)
		{
			qsize=read();
			int j;
			for(j=1;j<=qsize;++j)
			{
				tmp=read();
				team[tmp]=i;
			}
		}
		printf("Scenario #%d\n",++scenario);
		while(1)
		{
			getInstr();
			if(instr[0]=='S')
			{
				break;
			}
			else if(instr[0]=='E')
			{
				tmp=read();
				int t=team[tmp];
				if(sfront[t]==srear[t])
				{
					ss[ssrear]=t;
					ssrear++;
				}
				s[t][srear[t]]=tmp;
				srear[t]++;
			}
			else if(instr[0]=='D')
			{
				int t=ss[ssfront];
				write(s[t][sfront[t]]);
				putchar('\n');
				sfront[t]++;
				if(sfront[t]==srear[t])
				{
					ssfront++;
				}
			}
		}
		puts("");
	}
}
