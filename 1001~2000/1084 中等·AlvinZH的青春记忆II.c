#include<stdio.h>
#include<math.h>

int n,k;
int X[100010];
int Xmax;

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        Xmax=0;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&X[i]);
            if(X[i]>Xmax)
            {
            	Xmax=X[i];
			}
        }
        if(k==1)
        {
            printf("%d\n",Xmax);
            continue;
        }
        int ans=0;
        int l=1;
		int r=Xmax;
		int mid;
        while(r>=l)
        {
            mid=(l+r)/2;
            long long cnt=0;
            for(i=0;i<n;i++)
            {
                if(X[i]>mid)
                {
                    long long s=ceil(1.0*(X[i]-mid)/(k-1));
                    cnt+=s;
                }
            }
            if(cnt>mid)
            {
            	l=mid+1;
			}
            else
            {
            	r=mid-1;
				ans=mid;
			}
        }
        printf ("%d\n",ans);
    }
}
