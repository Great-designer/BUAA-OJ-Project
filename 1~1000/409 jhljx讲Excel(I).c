#include<stdio.h>
#include<string.h>

char a[1028]; 

int main()
{
	scanf("%s",a);
	int i;
	long long answer=(a[0]-'A'+1);
	for(i=1;i<strlen(a);i++)
	{
		answer*=26;
		answer+=(a[i]-'A'+1);
	}
	printf("%lld\n",answer);
}

