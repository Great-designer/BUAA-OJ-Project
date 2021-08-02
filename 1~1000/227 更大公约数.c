#include<stdio.h>
#include<string.h>

int a[1071][1071],d1[1071][1071],d2[1071][1071],d3[1071][1071],d4[1071][1071];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int ans=0;
		int temp;
		int i;
		for(i=1; i<=n; i++)
		{
			int j;
			for(j=1; j<=m; j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		int j;
		for(j=1; j<=m; j++)
		{
			d1[0][j]=d2[0][j]=d3[0][j]=d4[0][j]=a[1][j];
			d1[n+1][j]=d2[n+1][j]=d3[n+1][j]=d4[n+1][j]=a[n][j];
		}
		for(i=1; i<=n; i++)
		{
			d1[i][0]=d2[i][0]=d3[i][0]=d4[i][0]=a[i][1];
			d1[i][m+1]=d2[i][m+1]=d3[i][m+1]=d4[i][m+1]=a[i][m];
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				d1[i][j]=gcd(a[i][j],gcd(d1[i-1][j],d1[i][j-1]));
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=m; j>=1; j--)
			{
				d2[i][j]=gcd(a[i][j],gcd(d2[i-1][j],d2[i][j+1]));
			}
		}
		for(i=n; i>=1; i--)
		{
			for(j=1; j<=m; j++)
			{
				d3[i][j]=gcd(a[i][j],gcd(d3[i+1][j],d3[i][j-1]));
			}
		}
		for(i=n; i>=1; i--)
		{
			for(j=m; j>=1; j--)
			{
				d4[i][j]=gcd(a[i][j],gcd(d4[i+1][j],d4[i][j+1]));
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				temp=0;
				if(i-1>=1&&j-1>=1)
				{
					temp=d1[i-1][j-1];
				}
				if(i-1>=1&&j+1<=m)
				{
					if(temp==0)
					{
						temp=d2[i-1][j+1];
					}
					else
					{
						temp=gcd(temp,d2[i-1][j+1]);
					}
				}
				if(i+1<=n&&j-1>=1)
				{
					if(temp==0)
					{
						temp=d3[i+1][j-1];
					}
					else
					{
						temp=gcd(temp,d3[i+1][j-1]);
					}
				}
				if(i+1<=n&&j+1<=m)
				{
					if(temp==0)
					{
						temp=d4[i+1][j+1];
					}
					else 
					{
						temp=gcd(temp,d4[i+1][j+1]);
					}
				}
				ans=ans>temp?ans:temp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

