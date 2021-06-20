#include<stdio.h>
#include<string.h>
#include<math.h>

int toxicdoses[100001];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int small=0xFFFFFF;
        int big=0;
		int ans=0;
        int i;
        for(i=0;i<n;++i)
        {
            scanf("%lld",&toxicdoses[i]);
            if(toxicdoses[i]>big)
            {
            	big=toxicdoses[i];
			}
            if(toxicdoses[i] < small)
            {
            	small=toxicdoses[i];
			}
        }
        int k;
        scanf("%d",&k);
        while(small<=big)
        {
            int totalTime=0;
            int possible=(small+big)/2;
            for(i=0;i<n;i++)
            {
            	if(toxicdoses[i]>possible)
            	{
            		totalTime+=ceil((double)(toxicdoses[i]-possible)/(k-1));
				}
			}
            if(totalTime>possible)
            {
            	small=possible+1;
			}
            else
            {
                ans=possible;
                big=possible-1;
            }
        }
        printf("%d\n",ans);
    }
}

