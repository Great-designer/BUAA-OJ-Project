#include<stdio.h>
#include<string.h>

char a[20];

int main()
{
	scanf("%s",a);
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
	printf("%lld\n",m);
}
