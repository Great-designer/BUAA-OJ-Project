#include<stdio.h>
#include<math.h>

long long int y(long long int a,long long int b)
{
    long long int c;
    if (b>a)
    {
    	c=a;
    	a=b;
    	b=c;
	}
    c=a%b;
    a=b;
    b=c;
    if (b==0)
        return a;
    else
        return y(a,b);
}

int main()
{
    long long int a,b,d;
    double e,f,g,h; 
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
    	d=y(a,b);
    	a=a/d;
	    b=b/d;
    	h=a*a-4*b;
	    if (h<0)
    	    printf("No Solution\n");
		else
    	{
	        h=sqrt(h);
    	    e=(a+h)/2;
	        f=(a-h)/2;
    	    if (f>e)
	        {
    	    	g=f;
        		f=e;
        		e=g;
			}
			e=e*d;
			f=f*d;
			if ((long long int)e!=e||(long long int)f!=f)
			    printf("No Solution\n");
			else
    	    printf("%lld %lld\n",(long long int)f,(long long int)e);
		}
	}
}


