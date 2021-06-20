#include<stdio.h>
#include<string.h>

long long a[100],b[100];
int pp[100];
int n1,n2;
long long x,y;

int main()
{
    while(~scanf("%lld%lld",&x,&y))
    {
    	x=(x>0)?x:-x;
    	y=(y>0)?y:-y;
        memset(pp,0,sizeof(pp));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        n1=n2=0;
        while(x>0)
        {
            n1++;
            a[n1]=x%3;
            x/=3;
        }
        while(y>0)
        {
            n2++;
            b[n2]=y%3;
            y/=3;
        }
        int flag=0;
        int pos;
        int tt=0;
        int i;
        for(i=1;;i++)
        {
            if(pp[i])
			{
				continue;
			}
            if(a[i]*b[i]!=0)
            {
                tt=1;
                break;
            }
            if(a[i]+b[i]==0)
            {
                flag=1;
                pos=i;
                break;
            }
            if(a[i]==1)
            {
                pp[i]=1;
        	}
            else if(a[i]==2)
            {
                pp[i]=1;
                a[i+1]++;
                int d=i+1;
                while(a[d]==3)
                {
                    a[d+1]++;
                    a[d]=0;
                    d++;
                }
            }
            else if(b[i]==1)
            {
                pp[i]=1;
            }
            else 
            {
                pp[i]=1;
                b[i+1]++;
                int d=i+1;
                while(b[d]==3)
                {
                    b[d+1]++;
                    b[d]=0;
                    d++;
                }
            }
        }
        if(tt)
        {
            printf("-1\n");
            continue;
        }
        if(flag)
        {
            int fflag=0;
            int j;
            for(j=pos;j<100;j++)
            {
                if(a[j]+b[j]!=0)
                {
                    fflag=1;
                    break;
                }
            }
            if(fflag)
			{
				printf("-1\n");
			}
            else
			{
				printf("%d\n",pos-1);
			}
        }
        else
		{
			printf("%d\n",pos-1);
		}
    }          
    return 0;
}

