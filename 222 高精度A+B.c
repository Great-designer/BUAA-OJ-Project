#include<stdio.h>
#include<string.h>

int a[111],b[111],c[111],na,nb,nc,i;
char s[111],r[111];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        scanf("%s",r);
        na=strlen(s);
        nb=strlen(r);
        for(i=1;i<=na;i++)
        {
            a[na-i]=s[i-1]-'0';
        }
        for(i=1;i<=nb;i++)
        {
            b[nb-i]=r[i-1]-'0';
        }
        nc=na>nb?na:nb; 
        for(i=na;i<nc;++i)
        {
            a[i]=0; 
        } 
        for(i=nb;i<nc;++i)
        {
            b[i]=0;
        } 
        for(i=0;i<=nc;++i)
        { 
            c[i]=0; 
        }
        for(i=0;i<nc;i++)
        {
            c[i]+=a[i]+b[i];
            if (c[i]>=10)
            {
                c[i]=c[i]-10;
                ++c[i+1];
            }
        }
        if(c[nc])
        {
            ++nc;
        }
        for(i=nc-1;i>=0;--i)
        {
            printf("%d",c[i]);
        }
        printf("\n");
    }
}
