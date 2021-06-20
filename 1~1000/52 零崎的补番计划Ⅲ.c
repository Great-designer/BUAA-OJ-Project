#include<stdio.h>

int dis[1010][1010];

int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        int i;
        for(i=1;i<=n;i++)
        {
        	int j;
			for(j=1;j<=n;j++)
            {
                scanf("%d",&dis[i][j]);
                if(dis[i][j]==-1)
                {
                	dis[i][j]=0xFFFFFF;
				}
            }
		}
        int k;
        for(k=1;k<=n;k++)
        {
        	for(i=1;i<=n;i++)
        	{
        		int j;
        		for(j=1;j<=n;j++)
        		{
        			if(dis[i][j]>dis[i][k]+dis[k][j])
        			{
        				dis[i][j]=dis[i][k]+dis[k][j];
					}
        		}
			}
		}
		int start,des;
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&start,&des);
            if(dis[start][des]!=0xFFFFFF&&start!=des)
            {
            	printf("%d\n",dis[start][des]);
			}
            else
            {
            	printf("jujue\n");
			}
        }
    }
}

