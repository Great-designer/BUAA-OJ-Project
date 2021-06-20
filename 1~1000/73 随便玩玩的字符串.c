#include<stdio.h>
#include<string.h>

char a[10000];

int main()
{
	int n,m;
	while(~scanf("%d",&n))
	{
		scanf("%s",a);
		int i;
		for(i=1;i<=n;i++)
		{
			m=a[i-1]-'0';
			if(m>=0&&m<=9)
			{
				printf("%d",m);
			}
			else
			{
				printf("%d",m+48);
			}
		}
		printf("\n");
	}
}

