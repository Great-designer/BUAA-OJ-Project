#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void UPRT(long long a)
{
	if(a>=10)
	{
		UPRT(a/10);
	}
	putchar(a%10+48);
}

int hs[255];
char s[100005];
int sum[100005];

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	char c;
	for(c='a';c<='z';++c)
	{
		hs[c]=1<<(c-'a');
	}
	while(~scanf("%s",s))
	{
		int len=strlen(s);
		sum[0]=0;
		int i;
		for(i=1;i<=len;++i)
		{
			sum[i]=sum[i-1]^hs[s[i-1]];
		}
		int cnt=1;
		long long ans=0;
		qsort(sum,len+1,sizeof(int),compare);
		for(i=1;i<=len;++i)
		{
			if(sum[i]==sum[i-1])
			{
				++cnt;
			}
			else
			{
				ans+=(long long)cnt*(cnt-1)/2;
				cnt=1;
			}
		}
		ans+=(long long)cnt*(cnt-1)/2;
		UPRT(ans);
		putchar(10);
	}
	return 0;
}

