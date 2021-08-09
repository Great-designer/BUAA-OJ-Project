#include<stdio.h>

int n;
char s[100010];

int main()
{
	while(~scanf("%d",&n))
	{
		scanf("%s",s);
		int flag;
		int cnt;
		flag=s[0];
		cnt=1;
		int i;
		for(i=1;i<n;++i)
		{
			if(s[i]!=flag)
			{
				cnt++;
				flag=s[i];
			}
		}
		if(cnt+2>n)
		{
			printf("%d\n",n);
		}
		else
		{
			printf("%d\n",cnt+2);
		}
	}
}
