#include<stdio.h>

char rowNow[2000000];

int main()
{
	int n,m,numPerRow;
	scanf("%d",&n);
	int i; 
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		int digitNow=1;
		rowNow[0]='a';
		numPerRow=1;
		while(m>numPerRow)
		{
			m-=numPerRow;
			int k;
			for(k=0;k<digitNow;k++)
			{
				if(rowNow[numPerRow-k-1]!='i')
				{
					break;
				}
			}
			int flag;
			if(k==digitNow)
			{
				digitNow++;
				flag=1;
			}
			numPerRow+=digitNow;
			int c=0;
			if(rowNow[numPerRow-digitNow-1]=='*')
			{
				rowNow[numPerRow-1]='a';
			}
			else
			{
				rowNow[numPerRow-1]=rowNow[numPerRow-digitNow-1]+1;
			}
			int j;
			for(j=0;j<digitNow;j++)
			{
				if(rowNow[numPerRow-1-j]=='j')
				{
					rowNow[numPerRow-1-j]='*';
					c=1;
				}
				else
				{
					if(j==0)
					{
						continue;
					}
					rowNow[numPerRow-1-j]=c+rowNow[numPerRow-digitNow-1-j];
					if(rowNow[numPerRow-1-j]=='*'+1)
					{
						rowNow[numPerRow-1-j]='a';
						c=0;
					}
					else if(rowNow[numPerRow-1-j]=='j')
					{
						rowNow[numPerRow-1-j]='*';
						c=1;
					}
					else
					{
						c=0;
					}
				}
			}
			if(flag==1)
			{
				rowNow[numPerRow-digitNow]='a';
			}
			flag=0;
		}
		putchar(rowNow[m-1]),putchar('\n');
	}
}
