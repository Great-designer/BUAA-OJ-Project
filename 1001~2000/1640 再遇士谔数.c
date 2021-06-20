#include<stdio.h>
int main()
{	
	int a,b;
	scanf("%d%d",&a,&b);
	int n;
	n=a;
	while(n<=b)
	{
		if(n%10==1||n%10==3||n%10==7||n%10==8)
		{
			printf("%d\n",n);
		}
		n++;
	}
}
