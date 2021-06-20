#include<stdio.h>

int main()
{
	int m,n; 
	scanf("%d%d",&m,&n);
	if(n%2==1)
	{
		printf("Wrong number");
		return 0;
	}
	n=n/2;
	int x,y;
	x=2*m-n;
	y=n-m;
	if(x<0||y<0)
	{
		printf("Wrong number");
		return 0;
	}
	printf("%d %d",x,y);
}
