#include<stdio.h>

int a[100020];

int Mygcd(int a,int b)
{
    int r;
    if(a<b)
    {
    	int temp=a;
    	a=b;
    	b=temp;
	}
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int n,ans;
    int x,tmp;
    int i;
    char flag;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&a[i]);
            if(i==1)
            {
            	x=a[i];
			}
            else
            {
            	x=Mygcd(a[i],x);
			}
        }
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        ans=0;
        flag=0;
        for(i=1;i<=n;i++)
        {
            if(!flag)
            {
                if(a[i]==x)
                {
                	ans++;
				}
                else
                {
                    tmp=a[i];
                    flag=1;
                }
            }
            else
            {
                tmp=Mygcd(a[i],tmp);
                if(tmp==x)
                {
                    flag=0;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

