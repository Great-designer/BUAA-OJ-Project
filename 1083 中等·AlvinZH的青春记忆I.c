#include<stdio.h>

int n;
int V[100005];

int maxValue(int left, int right)
{
    int LastTwo=0;
	int LastOne=0;
    int i; 
    for(i=left;i<=right;i++)
    {
        int temp=LastOne;
        LastOne=((LastOne>(LastTwo+V[i]))?LastOne:(LastTwo+V[i]));
        LastTwo=temp;
    }
    return LastOne;
}

int main()
{
    while(~scanf("%d",&n))
    {
    	int i;
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&V[i]);
		}
        if(n==1)
		{
			printf("%d\n",V[1]);
		}
        else
		{
			int a=maxValue(1,n-1);
			int b=maxValue(2,n);
			int ans=((a>b)?a:b);
			printf("%d\n",ans);
		}
    }
}
