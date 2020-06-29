#include<stdio.h>

int RGB[1005][1005];
char BW[1005][1005];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		m=m*3;
		int i,j;
		int r,g,b;
		int sum;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%x",&RGB[i][j]);
				r=RGB[i][j]/65536;
				g=(RGB[i][j]/256)%256;
				b=RGB[i][j]%256;
				sum=r+g+b;
				if(sum>=m)
				{
					BW[i][j]='0';
				}
				else
				{
					BW[i][j]='1';
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%c ",BW[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
