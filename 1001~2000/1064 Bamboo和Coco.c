#include<stdio.h>

int Left[1000005],Right[1000005];
int thinking[1000005];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
    	int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&thinking[i]);
        }
        for(i=0;i<n;i++)
        {
            Left[i]=1;
			Right[i]=1;
        }
        for(i=1;i<n;i++)
        {
            if(thinking[i]>thinking[i-1])
            {
            	Left[i]=Left[i-1]+1;
			}
        }
        for(i=n-2;i>=0;i--)
        {
            if(thinking[i]>thinking[i+1])
            {
            	Right[i]=Right[i+1]+1;
			}
        }
        int res=0;
        for(i=0;i<n;i++)
        {
        	res+=((Left[i]>Right[i])?Left[i]:Right[i]);
		}
        printf("%d\n",res);
    }
}
