#include<stdio.h>
#include<string.h>

char a[20];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&a);
		int i;
		int answer=0;
		for(i=0;i<strlen(a);i++)
		{
			answer+=(a[i]-'0');
		}
		printf("%d\n",answer);
	}
}
