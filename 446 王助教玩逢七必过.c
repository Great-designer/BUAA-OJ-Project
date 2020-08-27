#include<stdio.h>

char get7(long long num)
{
    while(num)
	{
        if(num%10==7)
		{
			return 1;
		}
        num/=10;
    }
    return 0;
}
int main()
{
    int n,i;
	long long beg,j;
    scanf("%d%d%lld",&n,&i,&beg);
    for(j=i-1;;j+=n)
	{
        if(((beg+j)%7==0||get7(beg+j)))
		{
			break;
		}
    }
    printf("%lld",beg+j);
}

