#include<stdio.h>
#include<string.h>

int main()
{
	char buffer[30] = {0},tmp = 0;
	scanf("%s",buffer);
	int len = strlen(buffer),result1 = 0,result2 = 0,start = 0,m = 0,n = len - 1;
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