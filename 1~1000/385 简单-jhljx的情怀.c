#include<stdio.h>

char a[105][105];
int n;

int main()
{
	while(~scanf("%d",&n))
	{
		getchar();
		getchar();
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%[^\r\n]",a[i]);
			getchar();
			getchar();
		}
		for(i=n-1;i>=0;--i)
		{
			printf("%s\n",a[i]);
		}
	}
}
