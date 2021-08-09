#include<stdio.h>

struct complex
{
	double x;
	double y;
};

struct complex a,b,result;

void print(struct complex A)
{
	if(A.x==0.0)
	{
		if(A.y==0.0)
		{
			printf("0\n");
		}
		else
		{
			printf("%.2lfi\n",A.y);
		}
	}
	else
	{
		if(A.y==0.0)
		{
			printf("%.2lf\n",A.x);
		}
		else if(A.y>0.0)
		{
			printf("%.2lf+%.2lfi\n",A.x,A.y);
		}
		else
		{
			printf("%.2lf%.2lfi\n",A.x,A.y);
		}
	}
}

int n;
char op;
char tmp;
char lalala[10];

int main()
{
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%s%lf%lf%lf%lf",lalala,&a.x,&a.y,&b.x,&b.y);
			op=lalala[0];
			if(op=='+')
			{
				result.x=a.x+b.x;
				result.y=a.y+b.y;
				print(result);
			}
			if(op=='-')
			{
				result.x=a.x-b.x;
				result.y=a.y-b.y;
				print(result);
			}
			if(op=='*')
			{
				result.x=a.x*b.x-a.y*b.y;
				result.y=a.x*b.y+a.y*b.x;
				print(result);
			}
			if(op=='/')
			{
				if(b.x!=0.0||b.y!=0.0)
				{
					result.x=(a.x*b.x+a.y*b.y)/(b.x*b.x+b.y*b.y);
					result.y=(a.y*b.x-a.x*b.y)/(b.x*b.x+b.y*b.y);
					print(result);
				}
				else
				{
					printf("Wrong Input!\n");
				}
			}
		}
	}
}
