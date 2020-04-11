#include<stdio.h>

char a[5];

int main()
{
	while(~scanf("%s",a))
	{
		int n=a[0]-'0'+10*(a[1]-'0')+100*(a[2]-'0');
		printf("%d\n",n);
	}
}
