#include<stdio.h>

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	if(a<b)
	{
		return gcd(b,a);
	}
	a=a%b;
	return gcd(b,a);
}
 
int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
		int k=gcd(m,n);
		printf("%d\n",m/k*n);
    }
} 

