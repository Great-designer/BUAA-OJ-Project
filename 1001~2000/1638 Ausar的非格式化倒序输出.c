#include<stdio.h>

int b;

void Ausar()
{
	long long a;
	b=scanf("%lld",&a);
	if(b==EOF)
	{
		return ;
	}
	Ausar();
	printf("%lld\n",a);
}

int main()
{
	Ausar();
}
