#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

long long sum, num;
int flag;
char ch;

int main(void)
{
	while ((ch = getchar()) != EOF)
	{
		if (ch >= '0' && ch <= '9') //如果当前读到的是数字字符
		{
			flag = 1;                    //记录是否读到过数
			num = num * 10 + (ch - '0'); //更新num
		}
		else //如果不是数字字符
		{
			sum += num; //对num进行求和
			num = 0;
			if (ch == '#') //如果读到结尾
			{
				if (flag) //如果曾经读到过数
					printf("%lld\n", sum);
				else //否则
					puts("No numbers");
				return 0;
			}
		}
	}
	return 0;
}