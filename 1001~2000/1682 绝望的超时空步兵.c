#include<stdio.h>

int m,s,t,p,q;

char get_ans(int m, int s, int t, int i)
{
	int f=0,dis=0;
	while(f<t&&dis<s)
	{
		if(m<10)
		{ 
			m+=5;
		} 
		else
		{
			m-=9;
			dis+=60;
		}
		f++;
	}
	if(dis>=s)
	{ 
		p=((f+i)<p?(f+i):p);
	} 
	else
	{ 
		q=((dis+i*17)>q?(dis+i*17):q);
	} 
	return dis>=s;
}

int main()
{
	while(scanf("%d%d%d",&m,&s,&t)==3)
	{
		p=1E9,q=0;
		char f=0;
		int i; 
		for(i=0;i<1000&&t>=i&&s-17*i>=0;i++)
		{
			f|=get_ans(m+i,s-17*i,t-i,i);
		}
		if(f)
		{
			printf("Yes\n%d\n",p);
		}
		else
		{
			printf("No\n%d\n",q);
		}
	}
	return 0;
}

