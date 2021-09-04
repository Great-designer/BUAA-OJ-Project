#include<stdio.h>

int main()
{
	char op;
	double x,y,result=0;
	scanf("%c",&op);
	scanf("%lf",&x);
	scanf("%lf",&y);
	switch(op)
	{
		case '+':
			result=x+y;
			break;
		case '-':
			result=x-y;
			break;
		case '*':
			result=x*y;
			break;
		case '/':
			result=x/y;
			break;
	}
	printf("%.2f",result);
	return 0;
}