#include<stdio.h> 

int m[100000];
int f[100000];
int mfront;
int mrear;
int ffront;
int frear;

int t,n;
char a;

char b[100000][10];
int btop;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		btop=0;
		while(n--)
		{
			a='\0';
			while(a!='m'&&a!='f')
			{
				a=getchar();
			}
			scanf("%s",b[btop]);
			if(a=='m')
			{
				m[mrear]=btop;
				mrear++;
			} 
			else
			{
				f[frear]=btop;
				frear++;
			}
			btop++;
		}
		while(!(mrear==mfront||frear==ffront))
		{
			printf("%s %s\n",b[f[ffront]],b[m[mfront]]);
			ffront++;
			mfront++;
		}
		mrear=mfront=0;
		frear=ffront=0;
	}
}
