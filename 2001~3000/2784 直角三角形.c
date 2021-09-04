#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a=a*a;
		b=b*b;
		c=c*c;
		if(a+b==c||a+c==b||b+c==a)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}