#include<stdio.h>

int main()
{
	int n; 
    scanf("%d",&n);
    int a=n%10;
    n/=10;
    int b=n%10;
    n/=10;
    int c=n%10;
    n/=10;
    int d=n%10;
    n/=10;
    n*=10;
    n+=a;
    n*=10;
    n+=b;
    n*=10;
    n+=c;
    n*=10;
    n+=d;
    printf("%d\n",n);
}
