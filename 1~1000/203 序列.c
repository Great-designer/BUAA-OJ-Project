#include<stdio.h>

long long J[100020];

int main()
{
    J[0]=1;
	J[1]=1;
    J[2]=1;
    long long i;
    for(i=3;i<=100001;i++)
    {
    	J[i]=(J[i-1]*i)%1000000007LL;
	}
    long long n;
    while(~scanf("%lld",&n))
    {
        printf("%lld\n",J[n+1]);
    }
    return 0;
}
