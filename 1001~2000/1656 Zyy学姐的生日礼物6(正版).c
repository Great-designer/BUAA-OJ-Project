#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char x[1010][25];

int compare(const void*p1,const void*p2)
{
	char*a=(char*)p1;
	char*b=(char*)p2;
	int c=strcmp(a,b);
	if(c<0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s",x[i]);
	}
	qsort(x,n,sizeof(char[25]),compare);
	for(i=0;i<n;i++)
	{
		printf("%s\n",x[i]);
	}
}
