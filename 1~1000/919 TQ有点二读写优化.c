#include<stdio.h>
#include<string.h>

long long read()
{
	long long k=0;
	char c=getchar();
	while(!isdigit(c))
	{ 
		c=getchar();
	}
	while(isdigit(c))
	{ 
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

int main()
{
	long long n;
	long long m;
	int result;
	n=read();
	while(n--)
	{
		m=read();
		result=0;
		while(m)
		{
			m=m&(m-1);
			result++;
		}
		if(result==1)
		{
			printf("222\n");
		} 
		else
		{
			printf("%d\n",result);
		} 
	}
	return 0;
}
