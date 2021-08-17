#include<stdio.h>
#include<limits.h>

int main()
{
    signed long long int a,b;
    scanf("%lld%lld",&a,&b);
    if(a>=0&&b>=0)
    {
        unsigned long long c=(unsigned long long)a+(unsigned long long)b;
        printf("%llu",c);
    }
    else if(a<=0&&b<=0)
    {
        if(a==LLONG_MIN&&b==LLONG_MIN)
        {
        	printf("-18446744073709551616");
		}
        else
        {
	        unsigned long long d,e;
	        d=-a;
	        e=-b;
	        if(a==LLONG_MIN)
	        {
	        	d=9223372036854775808ull;
			}
	        if(b==LLONG_MIN)
	        {
	        	e=9223372036854775808ull;
			}
	        unsigned long long c=d+e;
	        printf("-%llu",c);
        }
    }
    else
    {
        signed long long c;
        c=a+b;
        printf("%lld",c);
    }
}
