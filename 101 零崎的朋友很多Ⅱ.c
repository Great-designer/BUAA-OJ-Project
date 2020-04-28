#include<stdio.h>
#include<string.h>

int V[20010];

int main()
{
    int p,n,pi,ci;
    while(~scanf("%d%d",&p,&n))
    {
        memset(V,-1,sizeof(V));
        V[0]=0;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&pi,&ci);
            int j;
            for(j=p;j>=ci;j--)
            {
            	if(V[j-ci]!=-1&&V[j]<V[j-ci]+pi)
            	{
            		V[j]=V[j-ci]+pi;
				}
			}
        }
        if(V[p]==-1)
        {
        	printf("jpx\n");
		}
        else
        {
        	printf("%d\n",V[p]);
		}
    }
}
