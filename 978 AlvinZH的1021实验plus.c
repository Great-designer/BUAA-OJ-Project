#include<stdio.h>
#include<stdlib.h>

int n,m;
int FM[1005];

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
    	int i;
        for(i=0;i<n;++i)
        {
        	scanf("%d",&FM[i]);
		}
        qsort(FM,n,sizeof(int),compare);
        int ans=0;
        int pos=0;
        long long miss=1;
        while(miss<=m)
        {
            if(pos<n&&FM[pos]<=miss)
			{
                miss+=FM[pos];
                pos++;
            }
            else
			{
                ans++;
                miss<<=1;
            }
        }
        printf("%d\n",ans);
    }
}
