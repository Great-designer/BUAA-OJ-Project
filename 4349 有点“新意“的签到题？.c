#include<stdio.h>

int arr[501]= {0};

void printX(int n)
{
	int i,j;
	for(i=0; i<n/2; i++)
	{
		for(j=0; j<n; j++)
		{
			if(j==i)
			{
				putchar('\\');
				continue;
			}
			if(j==n-1-i)  putchar('/');
			else putchar(' ');
		}
		putchar(10);
	}
	if(n&1)
	{
		for(i=0; i<n/2; i++) putchar(' ');
		printf("x\n");
	}
	for(i=n/2-1; i>=0; i--)
	{
		for(j=0; j<n; j++)
		{
			if(j==i)
			{
				putchar('/');
				continue;
			}
			if(j==n-1-i)  putchar('\\');
			else putchar(' ');
		}
		putchar(10);
	}
}

int main(void)
{
	int n,i,j;
	while(~scanf("%d",&n))
		arr[n]++;
	for(i=12; i>=0; i--)
	{
		for(j=0; j<arr[i]; j++)
			printX(i),putchar(10);
	}
	return 0;
}