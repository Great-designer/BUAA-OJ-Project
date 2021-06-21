#include<stdio.h>
#include<ctype.h>
#include<string.h>

char expr[100010];

long long now;
long long ans;
long long timeNum;
char isTime;
unsigned int len;

int main()
{
	while(scanf("%s",expr)!=EOF)
	{
		now = ans = 0;
		timeNum = 1;
		isTime = 0;
		len=strlen(expr);
		unsigned int i;
		for (i = 0; i < len; ++i)
		{
			switch (expr[i])
			{
				case '+':
					if (isTime)
					{
						ans += timeNum * now;
						ans %= 10000;
						isTime = 0;
						timeNum = 1;
					}
					else
					{
						ans += now;
						ans %= 10000;
					}
					now = 0;
					break;
				case '*':
					timeNum *= now;
					timeNum %= 10000;
					isTime = 1;
					now = 0;
					break;
				default:
					if (isdigit(expr[i]))
					{
						now = ((now << 1) + (now << 3) + expr[i] - '0') % 10000;
					}
					break;
			}
		}
		//注意处理最后一个数
		if (isTime)
		{
			ans += timeNum * now;
			ans %= 10000;
			isTime = 0;
			timeNum = 1;
		}
		else
		{
			ans += now;
			ans %= 10000;
		}
		printf("%lld\n",ans);
	}
}
