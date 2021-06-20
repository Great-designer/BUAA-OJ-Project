#include<stdio.h>
#include<string.h>

int f[2][5001];
int g[2][5001];

char s1[100000],s2[100000];

int main()
{
    while(~scanf("%s",s1))
    {
		scanf("%s",s2);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        int len1=strlen(s1)-1;
		int len2=strlen(s2)-1;
		int i;
		for(i=0;i<=len2;i++)
		{
			g[0][i]=1;
		}
	    int k;
	    for(i=1;i<=len1;i++)
	    {
	        k=i&1;
	        memset(g[k],0,sizeof(g[k]));
	        memset(f[k],0,sizeof(f[k]));
	        g[k][0]=1;
	        g[!k][0]=1;
	        int j;
	        for(j=1;j<=len2;j++)
	        {
	            if(s1[i-1]==s2[j-1])
	            {
	                f[k][j]=f[!k][j-1]+1;
	                g[k][j]=g[!k][j-1];
	                g[k][j]%=100000000;
	                if(f[k][j]==f[!k][j])
	                {
	                    g[k][j]+=g[!k][j];
	                    g[k][j]%=100000000;
	                }
	                if(f[k][j-1]==f[k][j])
	                {
	                    g[k][j]+=g[k][j-1];
	                    g[k][j]%=100000000;
	                }
	            }
	            else
	            {
	                if(f[!k][j]>f[k][j-1])
	                {
	                    f[k][j]=f[!k][j];
	                    g[k][j]+=g[!k][j];
	                    g[k][j]%=100000000;
	                }
	                if(f[!k][j]<f[k][j-1])
	                {
	                    f[k][j]=f[k][j-1];
	                    g[k][j]+=g[k][j-1];
	                    g[k][j]%=100000000;
	                }
	                if(f[!k][j]==f[k][j-1])
	                {
	                    f[k][j]=f[!k][j];
	                    g[k][j]+=g[!k][j]+g[k][j-1];
						if(f[!k][j-1]==f[k][j])
						{
							g[k][j]-=g[!k][j-1];
						}
	                    g[k][j]=(g[k][j]+3*100000000)%100000000;
	                }
	            }
	        }
	    }
	    printf("%d\n",f[k][len2]);
	    printf("%d\n",g[k][len2]);
    }
}
