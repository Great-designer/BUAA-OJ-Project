#include<stdio.h>
#include<math.h>

long long H[2020],L[2020];
int n,m;

void CalDis(int ph,int pl,long long *Ret)
{
    int i,j;
    long long Ans=0;
    for(i=1;i<ph;i++)
    {
    	Ans+=(long long)(ph-i)*H[i];
	}
    for(i=ph+1;i<=n;i++)
    {
    	Ans+=(long long)(i-ph)*H[i];
	}
    for(j=1;j<pl;j++)
    {
    	Ans+=(long long)(pl-j)*L[j];
	}
    for(j=pl+1;j<=m;j++)
    {
    	Ans+=(long long)(j-pl)*L[j];
	}
    *Ret=Ans;
}

int main()
{
    int T;
    int x,y,q;
    int i,j,Num;
    long long Ans,tmp;
    long long Sumh,Suml,Psumh,Psuml;
    double ph,pl;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%d%d%d",&x,&y,&q);
        Psumh=Psuml=Sumh=Suml=0;
        for(j=1;j<=m;j++)
        {
        	L[j]=0;
		}
        for(i=1;i<=n;i++)
        {
            H[i]=0;
            for(j=1;j<=m;j++)
            {
                Num=((x^i)+(y^j))%q;
                H[i]+=Num;
                L[j]+=Num;
            }
            Sumh+=H[i];
            Psumh+=(long long)i*H[i];
        }
        for(j=1;j<=m;j++)
        {
            Suml+=L[j];
            Psuml+=(long long)j*L[j];
        }
        if(!Sumh)
        {
            printf("0\n");
            continue;
        }
        ph=Psumh/Sumh;
        pl=Psuml/Suml;
        CalDis(ph,pl,&Ans);
        CalDis(ph+1,pl,&tmp);
        if(tmp<Ans)
        {
        	Ans=tmp;
		}
        CalDis(ph,pl+1,&tmp);
        if(tmp<Ans)
        {
        	Ans=tmp;
		}
        CalDis(ph+1,pl+1,&tmp);
        if(tmp<Ans)
        {
        	Ans=tmp;
		}
        printf("%lld\n",Ans);
    }
    return 0;
}
