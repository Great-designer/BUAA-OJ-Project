#include<stdio.h>

char a[10];

int main()
{
    scanf("%s",a);
    int sum=0;
    int i;
    for(i=0;i<8;i++)
    {
    	sum+=(a[i]-'0')*(9-i);
    	sum%=10;
	}
	printf("%s%d\n",a,sum);
}
