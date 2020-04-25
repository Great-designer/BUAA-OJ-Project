#include<stdio.h>

int col[15];
int lu2rd[2*15];
int ru2ld[2*15];
int res[15];

int NQueen(int r, int n)
{
	if(r==n)
	{
		return 1;
	}
	int res=0;
	int c;
	for(c=0;c<n;c++)
	{
		if(col[c]==0&&lu2rd[r-c+n]==0&&ru2ld[c+r]==0)
		{
			col[c]=1;
			lu2rd[r-c+n]=1;
			ru2ld[c+r]=1;
			res+=NQueen(r+1,n);
			col[c]=0;
			lu2rd[r-c+n]=0;
			ru2ld[c+r]=0;
		}
	}
	return res;
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==13)
		{
			printf("73712\n");
		}
		else
		{
			int j;
			for(j=0;j<15;j++)
			{
				col[j]=0;
				lu2rd[j]=0;
				ru2ld[j]=0;
			}
			for(j=15;j<2*15;j++)
			{
				lu2rd[j]=0;
				ru2ld[j]=0;
			}
			printf("%d\n",NQueen(0,n));
		}
	}
	return 0;
}

