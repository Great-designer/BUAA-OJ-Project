#include<stdio.h>

int main()
{
   int n,m;
   while(~scanf("%d%d",&n,&m))
   {
       int sum1=0,sum2=0,k1=1,k2=1;
       int i;
       for(i=1;i<=n;i++)
       {
           k1=k1*(2*i+1)%10007;
           sum1=(sum1+k1)%10007;
       }
       int j;
       for(j=1;j<=m;j++)
       {
           k2=k2*(2*j)%10007;
           sum2=(sum2+k2)%10007;
       }
       printf("%d\n",(sum1-sum2+10007)%10007);
   }
}

