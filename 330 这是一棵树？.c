#include<stdio.h>

short pre[1005];
short mid[1005];
short back[1005];
char flagg=1;

void getBack(int preStart,int preEnd,int midStart,int midEnd,int backStart,int backEnd)
{
    if(!flagg)
	{
		return;
	}
    int len=preEnd-preStart+1;
    if(len==0)
	{
		return;
	}
    if(len==1)
	{
        back[backEnd]=pre[preStart];
        return;
    }
    int node=pre[preStart];
    int divided=-1;
    int left=-1;
    int right=-1;
    char flag=0;
    int i;
    for(i=midStart;i<=midEnd;i++)
	{
        if(mid[i]==node)
		{
            divided=i;
            left=i-midStart;
            right=len-1-left;
            flag=1;
            break;
        }
    }
    if(!flag)
	{
        flagg=0;
        return;
    }
    back[backEnd]=node;
    getBack(preStart+1,preStart+left,midStart,divided-1,backStart,backStart+left-1);
    getBack(preStart+left+1,preEnd,divided+1,midEnd,backStart+left,backStart+left+right-1);
}

int main()
{
    int n;
    while(~scanf("%d",&n))
	{
        flagg=1;
        int i;
        for(i=0;i<n;i++)
        {
        	scanf("%hd",&pre[i]);
		}
        for(i=0;i<n;i++)
        {
        	scanf("%hd",&mid[i]);
		}
        getBack(0,n-1,0,n-1,0,n-1);
        if(flagg)
		{
            for(i=0;i<n;i++)
            {
            	printf("%hd ",back[i]);
			}
            printf("\n");
        }
        else
        {
        	printf("No\n");
		}
    }
}
