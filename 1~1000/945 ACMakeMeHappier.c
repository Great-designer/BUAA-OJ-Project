#include<stdio.h>

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int a,b,p;

int main()
{
	while(scanf("%d%d%d",&a,&b,&p)!=EOF)
	{

		int c = gcd(a,b);
		a/=c;
		b/=c;
		int counter = 1;
		long long tmp = (long long)b;
		while(tmp%p!=1)
		{
			tmp+=(long long)b;
			counter++;
		}
		printf("%d\n",(a*counter)%p);
	}
}
