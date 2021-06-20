#include<stdio.h>

char s[100][100]={0};

int main()
{
    int n,a,b;
    char c;
    scanf("%d",&n);
    int i;
    for(i=1;i<n;i++)
    {
        c='A'+i-1;
        a=2*n-i;
        int j;
        for(j=i;j<=a;j++)
            s[i][j]=c;
        for(j=i+1;j<=a;j++)
            s[j][a]=c;
        for(j=a-1;j>=i;j--)
            s[a][j]=c;
        for(j=a-1;j>=i+1;j--)
            s[j][i]=c;
    }
    b=2*n-1;
	s[n][n]='A'+n-1;
    for(i=1;i<=b;i++)
	{
		int j;
		for(j=1;j<=b;j++)
		{
			printf("%c",s[i][j]);
		}
		printf("\n");
	} 
}

