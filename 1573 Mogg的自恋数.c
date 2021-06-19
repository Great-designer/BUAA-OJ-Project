#include<stdio.h>
#include<math.h>
int main()
{
    int n,ans,n1;
    int a[10]={0};
    while(scanf("%d",&n)!=EOF)
    {
        a[0]=0;
        ans=0;
        n1=abs(n);
        while(n1>=1)
        {
            a[0]++;
            a[a[0]]=n1%10;
            n1/=10;
        }
        for(int i=1;i<=a[0];i++)
            ans+=pow(a[i],a[0]);
        if(ans==n)
            printf("guna\n");
        else
            printf("%d\n",ans);
    }
}
