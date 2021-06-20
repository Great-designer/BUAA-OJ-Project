#include<stdio.h>
#include<string.h>

char num[10010];
int n,s;
int remain;

int main()
{
	while(~scanf("%d%d%s",&n,&s,num))
	{
		int mi=0;
		remain=n-s;
		int i;
		for(i=0;i<=s;++i)
		{
			if(num[i]<num[mi]&&num[i]!='0')
			{
				mi=i;
			}
		}
		s-=mi;
		for(i=mi+1;i<n&&s!=0;++i)
		{
			int j;
			for(j=i-1;s>0&&j>mi&&num[j]>num[i];j--)
			{
				if(num[j]!=':')
				{
					s--;
					num[j]=':';
				}
			}
		}
		int j;
		for(i=mi,j=0;i<n&&j<remain;++i)
		{
			if(num[i]!=':')
			{
				putchar(num[i]);
				++j;
			}
		}
		putchar('\n');
	}
}
