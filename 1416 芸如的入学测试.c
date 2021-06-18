#include<stdio.h>

long long an[1000001];

int main()
{
	int N,Q;
    while(~scanf("%d%d",&N,&Q))
	{
        scanf("%lld",an+1);
        int input;
        int i;
        for(i=2;i<=N;i++)
		{
            scanf("%d",&input);
            an[i]=an[i-1]+input;
        }
        int l,r;
        while(Q--)
		{
            scanf("%d%d",&l,&r);
            printf("%lld\n",(an[r]-an[l-1])%10007);
        }
    }
}

