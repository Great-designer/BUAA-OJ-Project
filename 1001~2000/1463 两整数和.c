#include<stdio.h>

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
        if(a==-9223372036854775808&&b==-9223372036854775808)
        {
        	printf("-18446744073709551616");
		}
        else
        {
	        unsigned long long d,e;
	        d=-a;
	        e=-b;
	        if(a==-9223372036854775808)
	        {
	        	d=9223372036854775808;
			}
	        if(b==-9223372036854775808)
	        {
	        	e=9223372036854775808;
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
