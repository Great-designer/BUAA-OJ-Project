#include<stdio.h>
#include<string.h>

char a[20],b[20];

int main()
{
	scanf("%s%s",a,b);
	int i;
	long long m=a[strlen(a)-1]-'0';
	if(strlen(a)>=2)
	{
		for(i=strlen(a)-2;i>=0;i--)
		{
			m*=10;
			m+=(a[i]-'0');
		}
	}
	long long n=b[strlen(b)-1]-'0';
	if(strlen(b)>=2)
	{
		for(i=strlen(b)-2;i>=0;i--)
		{
			n*=10;
			n+=(b[i]-'0');
		}
	}
	long long answer=m*n;
	printf("%lld\n",answer);
}
