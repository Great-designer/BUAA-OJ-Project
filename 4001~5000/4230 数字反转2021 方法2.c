#include<stdio.h>
#include<string.h>

int main()
{
	char buffer[30] = {0},tmp;
	scanf("%s",buffer);
	int start=0;
	int m = 0;
	int n = strlen(buffer) - 1;
	if(buffer[0] == '-') //先处理负号
	{
		putchar('-');
		m = 1;
		start = 1;
	}
	while(m < n) //翻转
	{
		tmp = buffer[m];
		buffer[m] = buffer[n];
		buffer[n] = tmp;
		m++;
		n--;
	}
	char *dotpos = strchr(buffer,'.');//找小数点
	int result1;
	if(!dotpos)
	{
		sscanf(buffer + start,"%d",&result1);
		printf("%d\n",result1);
	}
	else
	{
		*dotpos = ' ';
		sscanf(buffer + start,"%d",&result1);
		printf("%d.",result1);
		puts(dotpos + 1);
	}
	return 0;
}