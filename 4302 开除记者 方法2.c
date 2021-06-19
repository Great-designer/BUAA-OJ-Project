#include<stdio.h>

char C[1100][1100];

int t;
int n,m;

int main()
{
	C[0][0]=1;
	int i,j;
	for (i = 1; i < 1100; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			C[i][j] =C[i - 1][j]^C[i - 1][j - 1];
		}
	}
	while(scanf("%d",&t)!=EOF)
	{
		int size=1<<t;
		for(i=0;i<size;i++)
		{
			for(j=size-1;j>=0;j--)
			{
				printf("%d ",C[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}