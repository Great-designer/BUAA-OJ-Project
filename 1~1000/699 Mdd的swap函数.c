#include<stdio.h>

void swapbyvalue(int a,int b)
{
	int c=a;
}

void swapbyquote(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void swapbypointer(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int m,n;
int tmpm,tmpn;

int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		tmpm=m;
		tmpn=n;
		swapbyvalue(tmpm,tmpn);
		printf("%d %d\n",tmpm,tmpn);
		tmpm=m;
		tmpn=n;
		swapbyquote(&tmpm,&tmpn);
		printf("%d %d\n",tmpm,tmpn);
		tmpm=m;
		tmpn=n;
		swapbypointer(&tmpm,&tmpn);
		printf("%d %d\n",tmpm,tmpn);
	}
}
