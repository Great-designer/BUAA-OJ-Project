#include<stdio.h>

int p[101][101];
int t[101][101];
int T[101][101];

int Floyd(int n,int m)
{
    int r=1000000000;
    int line;
    for(line=1;line<=n;line++)
    {
    	int station;
    	for(station=1;station<=m;station++)
    	{
    		T[line][station]=1000000000;
		}
	}
    for(line=1;line<=n;line++)
    {
    	T[line][1]=p[line][1];
	}
    int station;
    for(station=2;station<=m;station++)
    {
    	int endLine;
    	for(endLine=1;endLine<=n;endLine++)
    	{
    		int startLine;
    		for(startLine=1;startLine<=n;startLine++)
    		{
    			T[endLine][station]=(T[endLine][station]<(T[startLine][station-1]+p[endLine][station]+t[startLine][endLine])?T[endLine][station]:(T[startLine][station-1]+p[endLine][station]+t[startLine][endLine]));
			}
		}
	}
    for(line=1;line<=n;line++)
    {
    	r=(r<T[line][m]?r:T[line][m]);
	}
    return r;
}

int main()
{
    int n,m,i,j;
    while(~scanf("%d%d",&n,&m))
    {
        getchar();
        for(i=1;i<=n;i++)
        {
        	for(j=1;j<=m;j++)
        	{
        		scanf("%d",&p[i][j]);
			}
		}
        getchar();
        for(i=1;i<=n;i++)
        {
        	for(j=1;j<=n;j++)
        	{
        		scanf("%d",&t[i][j]);
			}
		}
        getchar();
        printf("%d\n",Floyd(n,m));
    }
}

