#include<stdio.h>
#include<string.h>

char a[2048];

int main()
{
	int lalala = 1;
	scanf("%s",a);
	int i;
	for(i = 0; i <= (strlen(a)-1)/2; ++i)
	{
		if(a[i]!=a[strlen(a)-1-i])
		{
			lalala = 0;
		}
	}
	printf("%d",lalala);
}
