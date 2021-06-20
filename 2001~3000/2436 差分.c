#include<stdio.h>
#include<string.h>

int a[1000010];

int main()
{
	memset(a,0,sizeof(a));
	int n,k; 
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++;
		a[x+y]--;
    }
    int max=0;
    for(i=1;i<=n;i++)
    {
    	a[i]+=a[i-1];
    	if(a[i]>max)
    	{
    		max=a[i];
		}
	}
	printf("%d",max);
}

