#include <ctype.h>
#include <stdio.h>

int main()
{
	int ch, out; // 思考一下为什么要把字符定义为int类型
	while ((ch = getchar()) != EOF)
	{
		if (!isprint(ch)) //字符不可见则跳过
			continue;
		ch = tolower(ch);
		if (isdigit(ch))
			out = ch - 48;
		else if (ch < 'a')
			out = 1;
		else if (ch <= 'c')
			out = 2;
		else if (ch <= 'f')
			out = 3;
		else if (ch <= 'i')
			out = 4;
		else if (ch <= 'l')
			out = 5;
		else if (ch <= 'o')
			out = 6;
		else if (ch <= 's')
			out = 7;
		else if (ch <= 'v')
			out = 8;
		else if (ch <= 'z')
			out = 9;
		else
			out = 1;
		printf("%d", out);
	}
}