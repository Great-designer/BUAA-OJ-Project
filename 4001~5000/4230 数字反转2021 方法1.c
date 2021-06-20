#include<stdio.h>

int main()
{
	char num[21] = "\0";
	char c;
	int length = 0, i, is_neg = 0, print_head;
	c = getchar();
	if (c == '-')
	{
		is_neg = 1;
		c = getchar();
	}
	while ((c >= '0' && c <= '9') || c == '.')
	{
		num[length] = c;
		length++;
		c = getchar();
	}
	if (length == 1 && num[0] == '0')
	{
		printf("0");
		return 0;
	}
	for (i = length - 1; num[i] == '0' && num[i - 1] != '.'; i--)
	{
		//去掉末尾多余的0
	}
	print_head = i;
	if (is_neg)
	{
		printf("-");
	}
	for (i = print_head; i >= 0; i--)
	{
		printf("%c", num[i]);
	}
}