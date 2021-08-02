#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

char buffer[100][1020] = {0};

void reverse(char *str)
{
	int n = strlen(str);
	char tmp;
	int lb = 0,ub = n - 1;
	while(lb < ub)
	{
		tmp = str[lb];
		str[lb] = str[ub];
		str[ub] = tmp;
		lb++;
		ub--;
	}
}

int main()
{
	int cur = 0;
	while(gets(buffer[cur]))
	{
		reverse(buffer[cur]);
		cur++;
	}
	while(cur--)
	{
		puts(buffer[cur]);
	}
	return 0;
}