#include<stdio.h>
#include<stdlib.h>

#include<algorithm>
using namespace std;

long long ar[1000010];

int main()
{
    int n;
    while(~scanf("%d",&n))
	{
		int i;
        for(i=0;i<n;i++)
        {
        	scanf("%lld",&ar[i]);
		}
        sort(ar,ar+n);
        long long x;
        scanf("%lld",&x);
        int len=unique(ar,ar+n)-ar;
        int ans=len-(lower_bound(ar,ar+len,x)-ar);
        printf("%d\n",ans);
    }
    return 0;
}
