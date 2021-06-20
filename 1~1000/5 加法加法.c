#include<stdio.h>

char a[9999999];

int main()
{
	scanf("%s",a);
	int i,n=0;
	for(i=0;a[i]!='\0';i++)
	{
		n=n+a[i]-'0';
		n=n%9;
	}
	if(n==0)
	{
		n=9;
	}
	printf("%d",n);
}
