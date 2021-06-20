#include<stdio.h>

int a[100010];

int main()
{
    int n,m,i;
    while(~scanf("%d%d",&n,&m))
	{
        int left=0,right=0;
        for(i=0;i<n;i++)
		{
            scanf("%d",&a[i]);
            if(a[i]>left)
			{
				left=a[i];
			} 
            right+=a[i];
        } 
        while(left<right)
		{
            int mid=(left+right)/2;
            int count=0,sum=0;
            for(i=0;i<n;i++)
			{
                if(sum+a[i]<=mid)
				{
					sum+=a[i];
				} 
                else
				{
                    sum=a[i];
                    count++;
                }
            }
            count++;
            if(count>m)
			{
				left=mid+1;
			} 
            else
			{
				right=mid;
			} 
        }
        printf("%d\n",left);
    }
    return 0;
}
