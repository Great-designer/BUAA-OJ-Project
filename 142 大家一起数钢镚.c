#include<stdio.h>

int main()
{
    int a[7];
    int b[7]={0,1,5,10,50,100,500};
    int num;
    while(~scanf("%d",&a[1]))
	{
    	int ans=0;
    	int i;
    	for(i=2;i<=6;i++)
    	{
    		scanf("%d",&a[i]);
		}
		scanf("%d",&num);
	    for(i=6;i>=1;i--)
	    {
	        while(num-b[i]>=0&&a[i]>0)
	        {
	            a[i]--;
	            ans++;
	            num-=b[i];
	        }
	    }
	    printf("%d\n",ans);
    }
}
