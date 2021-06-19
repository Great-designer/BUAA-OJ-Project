#include<stdio.h>

int main()
{
	int num,radix;
	scanf("%d%d",&radix,&num);
	int arr[32] = {0},i=0;
	while(num)
	{
		arr[i] = num % radix;
		num /= radix;
		i++;
	}
	while(i--)
	{
		putchar(arr[i] + '0');
	}
	putchar('\n');
	return 0;
}