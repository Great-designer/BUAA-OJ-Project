#include<stdio.h>
#include<string.h>

char s[15];

int main()
{
	unsigned long long ans;
	unsigned long long lala;
	while(~scanf("%s",s))
	{
		ans=0;
		lala=1;
		int i;
		for(i=strlen(s)-1;i>=0;--i)
		{
			ans+=1ll*(s[i]-'A'+1)*lala;
			lala*=26;
		}
		printf("%llu\n",ans);
	}
}
