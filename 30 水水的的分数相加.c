#include<stdio.h>

int gcd(int a,int b)
{
    int f;
    while(b)
	{
		f=b;
		b=a%b;
		a=f;
	}
    return a;
}

int main()
{
    int n,a,b,c,d,i,x,y;
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        scanf("%d%d%d%d",&a,&c,&b,&d);
        x=c*d/gcd(c,d);
        y=x/c*a+x/d*b;
        c=gcd(x,y);
        if(c!=1)
		{
            y/=c;
			x/=c;
        }
        printf("%d %d\n",y,x);
    }
}

